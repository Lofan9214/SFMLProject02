#pragma once
#include "stdafx.h"

template<typename T>
class ResourceMgr : public Singleton<ResourceMgr<T>>
{
	friend Singleton<ResourceMgr<T>>;
protected:
	std::unordered_map<std::string, T*> resources;
	ResourceMgr() = default;
	~ResourceMgr() override;
	ResourceMgr(const ResourceMgr&) = delete;
	ResourceMgr& operator=(const ResourceMgr&) = delete;

	static T Empty;
	void UnloadAll();
public:
	bool Load(const std::string& id);
	bool Unload(const std::string& id);
	T& Get(const std::string& id);
};

template<typename T>
inline ResourceMgr<T>::~ResourceMgr()
{
	UnloadAll();
}

template<typename T>
inline void ResourceMgr<T>::UnloadAll()
{
	for (auto& pair : resources)
	{
		delete pair.second;
	}
	resources.clear();
}

template<typename T>
inline bool ResourceMgr<T>::Load(const std::string& id)
{
	auto it = resources.find(id);
	if (it != resources.end())
	{
		return false;
	}
	T* resource = new T();
	bool success = resource->loadFromFile(id);
	if (success)
	{
		resources.insert({ id, resource });
	}
	else
	{
		delete resource;
	}

	return success;
}

template<typename T>
inline bool ResourceMgr<T>::Unload(const std::string& id)
{
	auto it = resources.find(id);
	if (it != resources.end())
	{
		return false;
	}
	delete it->second;

	resources.erase(it);

	return true;
}

template<typename T>
inline T& ResourceMgr<T>::Get(const std::string& id)
{
	auto it = resources.find(id);
	if (it == resources.end())
	{
		return Empty;
	}
	return *(it->second);
}

template<typename T>
T ResourceMgr<T>::Empty;

#define TEXTUREMGR (ResourceMgr<sf::Texture>::Instance())