#include "ResultScene.h"
#include "GameScene.h"
#include "TitleScene.h"


ResultScene::ResultScene()
    :ResultImage_(-1)
{
    ResultImage_ = LoadGraph("Assets\\Game Over.png");
}

void ResultScene::Update()
{
    
        timer++;
        if (CheckHitKey(KEY_INPUT_SPACE)) // 3�b�o�߂܂���Enter�Ń^�C�g����
        {
            endFlag = true;
        }
    
}

void ResultScene::Draw()
{
    ClearDrawScreen();
   
    if (ResultImage_ != -1) {
        DrawGraph(0, 0, ResultImage_, TRUE);
    }
   
    ScreenFlip();
}

Scene* ResultScene::NextScene()
{
    if (IsEnd()) // �I������
        return new TitleScene();
    return this;
}
