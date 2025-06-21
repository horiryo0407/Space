#include "TitleScene.h"
#include "GameScene.h"

TitleScene::TitleScene()
	: titleImage_(-1)
{
	titleImage_ = LoadGraph("Assets\\Title.png");
}

void TitleScene::Update()
{
	timer++;
	if (CheckHitKey(KEY_INPUT_RETURN)) // EnterÇ≈éüÇÃâÊñ Ç÷
	{
		endFlag = true;
	}
}


void TitleScene::Draw()
{
	ClearDrawScreen();


	if (titleImage_ != -1) {
		DrawGraph(0, 0, titleImage_, TRUE);
	}


	ScreenFlip();
}



Scene* TitleScene::NextScene()
{
	if (CheckHitKey(KEY_INPUT_RETURN)) {
		return new GameScene();
	}
	return this; // ë±çsÅI
}
