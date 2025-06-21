
#include "GameScene.h"
#include "ResultScene.h"
#include "Stage.h"
#include "globals.h"
#include "DxLib.h"
#include "Player.h"

GameScene::GameScene()
    :timer(0), endFlag(false), deathTimer(-1.0f)
{
    
    Stage* stage = new Stage(); // Stage����  
    
}



void GameScene::Update()
{
    timer++;
    Player* player = nullptr;
    for (auto obj : gameObjects) {
        player = dynamic_cast<Player*>(obj);
        if (player) break;
    }

    if (player && player->IsDead()) {
        if (deathTimer < 0) {
            deathTimer = 1.0f; // ���S���m�����u�Ԃ�1�b�J�E���g�J�n
        }
        deathTimer -= gDeltaTime;
        if (deathTimer <= 0) {
            endFlag = true;
        }
    }
    if (CheckHitKey(KEY_INPUT_ESCAPE))
    {
        endFlag = true;
    }

    
}

void GameScene::Draw()
{
    ClearDrawScreen();

    for (auto& obj : gameObjects) {
        obj->Draw(); // �Q�[���I�u�W�F�N�g�̕`��
    }


    ScreenFlip();
}


Scene* GameScene::NextScene()
{
    if (endFlag)
    {
        return new ResultScene();
    }
     else
     {
        return this;
     }
}
