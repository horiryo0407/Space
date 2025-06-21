#include "Scene.h"
#include "DxLib.h"
#include "Stage.h"

class GameScene : public Scene
{
    int timer = 0;
    bool endFlag = false;
    float deathTimer = -1.0f;
   
public:
    GameScene();
    void Update() override;
    void Draw() override;
    bool IsEnd() const override { return endFlag; }
    Scene* NextScene() override; // èIóπÇµÇΩÇÁnullptrï‘Ç∑
};
