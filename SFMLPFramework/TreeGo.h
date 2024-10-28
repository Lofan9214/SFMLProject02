#pragma once
#include "GameObject.h"
#include "BranchGo.h"
#include "EffectLog.h"

class TreeGo :
    public GameObject
{
protected:
    sf::Sprite sprTree;
    std::list<BranchGo*> lstBranch;

    int cntBranch = 6;

    std::string treeTextureId = "graphics/tree.png";
    std::string branchTextureId = "graphics/branch.png";

    float offsetYBranch = 150.f;

    ObjectPool<EffectLog> objpoolEffectLog;

public:
    TreeGo(const std::string& name = "");
    virtual ~TreeGo();

    Sides chop(Sides side);
    void updateBranchPos();

    void init() override;
    void release() override;

    void reset() override;

    void update(float dt) override;
    void draw(sf::RenderWindow& window) override;

    void setPosition(const sf::Vector2f& pos) override;
};

