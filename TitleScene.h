#pragma once
#include "Scene.h"
#include "DxLib.h"

class TitleScene : public Scene
{
    int timer = 0;
    bool endFlag = false;
    int titleImage_ = -1;
public:
    TitleScene();
    void Update() override;
    void Draw() override;
    bool IsEnd() const override { return endFlag; }
    Scene* NextScene() override;
   
};
