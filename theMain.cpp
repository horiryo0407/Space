#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include <vector>
#include "Stage.h"
#include "TitleScene.h"
#include "Enemy.h"
#include "Player.h"
#include "GameScene.h"
#include "ResultScene.h"


namespace
{
	const int BGCOLOR[3] = { 0, 0, 0 }; // 背景色{ 255, 250, 205 }; // 背景色
	int crrTime;
	int prevTime;
}

std::vector<GameObject*> gameObjects; // ゲームオブジェクトのベクター
std::vector<GameObject*> newObjects; // ゲームオブジェクトのベクター


float gDeltaTime = 0.0f; // フレーム間の時間差

void DxInit()
{
	ChangeWindowMode(true);
	SetWindowSizeChangeEnableFlag(false, false);
	SetMainWindowText("TITLE");
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);
	SetWindowSizeExtendRate(1.0);
	SetBackgroundColor(BGCOLOR[0], BGCOLOR[1], BGCOLOR[2]);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		DxLib_End();
	}

	SetDrawScreen(DX_SCREEN_BACK);
}





int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	DxInit();
	
	Scene* currentScene = new TitleScene(); // タイトルシーンの生成


	crrTime = GetNowCount();
	prevTime = GetNowCount();

	

	SceneType currentSceneType = SceneType::TITLE;
	

	while (true) {
		ClearDrawScreen();

		Input::KeyStateUpdate(); // キー入力の状態を更新

		crrTime = GetNowCount(); // 現在の時間を取得
		// 前回の時間との差分を計算
		float deltaTime = (crrTime - prevTime) / 1000.0f; // 秒単位に変換
		gDeltaTime = deltaTime; // グローバル変数に保存
		currentScene->Update();
		currentScene->Draw();

		Scene* nextScene = currentScene->NextScene();
		if (nextScene != currentScene) {
			delete currentScene;
			currentScene = nextScene;
			//for (auto obj : gameObjects) delete obj;
			gameObjects.clear();
		}
		//ここにやりたい処理を書く(ここから）
		//ゲームオブジェクトの追加
		if (newObjects.size() > 0) {
			for (auto& obj : newObjects) {
				gameObjects.push_back(obj); // 新しいゲームオブジェクトを追加	
			}
			newObjects.clear(); // 新しいゲームオブジェクトのベクターをクリア
		}
		//gameObjectsの更新
		for (auto& obj : gameObjects) {
			obj->Update(); // ゲームオブジェクトの更新
		}
		//gameObjectsの描画
		

		
		for (auto it = gameObjects.begin(); it != gameObjects.end();) {
			if (!(*it)->IsAlive()) {
				delete* it; // ゲームオブジェクトを削除
				it = gameObjects.erase(it); // ベクターから削除
			}
			else {
				++it; // 次の要素へ
			}
		}

		if (ProcessMessage() == -1) break;
		ScreenFlip();
		WaitTimer(16);
		prevTime = crrTime;
		
	}


	delete currentScene;
	DxLib_End();
	return 0;
	
}