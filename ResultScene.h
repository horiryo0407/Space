#pragma once
#include "Scene.h"
#include "DxLib.h"

class ResultScene : public Scene
{
    int timer = 0;
    int ResultImage_;
    bool endFlag = false;
public:
    ResultScene();
    void Update() override;
    void Draw() override;

    bool IsEnd() const override { return endFlag; }
    Scene* NextScene() override;
};
