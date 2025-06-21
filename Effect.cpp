#include "Effect.h"
#include "DxLib.h"
#include <string>

namespace
{
	const float ANIME_TIME = { 1.0f };
	const int EFFECT_IMAGE_SIZE = 48; // エフェクトの画像サイズ
	const std::string EIMG_PATH = "Assets\\explosion.png"; // エフェクトの画像パス
	const int MAX_FRAME = 9; // エフェクトのフレーム数
	const int DIV_NUM = 3; // 画像を分割する数（3x3のグリッド）
	const float FRAME_TIME = ANIME_TIME / MAX_FRAME; // フレームごとの時間 
	
}
Effect::Effect(Point _pos)
	:GameObject(),  pos_({ _pos.x,_pos.y }), AnimTimer_(ANIME_TIME), hImage_(std::vector<int>(MAX_FRAME, -1)),frame_(0) // エフェクトの初期化
{
	//hImage_ = LoadGraph(EIMG_PATH.c_str()); // エフェクトの画像を読み込む
	LoadDivGraph(EIMG_PATH.c_str(), MAX_FRAME, 
		DIV_NUM,DIV_NUM, EFFECT_IMAGE_SIZE, EFFECT_IMAGE_SIZE,
		hImage_.data()); // 画像を分割して読み込む

	AddGameObject(this); // ゲームオブジェクトのベクターに追加
	
}


Effect::~Effect()
{
	//DeleteGraph(hImage_); // 画像ハンドルを解放
	for(auto& itr: hImage_)
	
		
			DeleteGraph(itr); // 各エフェクト画像のハンドルを解放
			hImage_.clear(); // 画像ハンドルのベクターをクリア
		

}

void Effect::Update()
{
	float dt = GetDeltaTime(); // フレーム間の時間差を取得
	AnimTimer_ = AnimTimer_ - dt; // アニメーションタイマーを減少
	if (AnimTimer_ <= 0)
	
	{
		
		this->isAlive_ = false; // アニメーションが終了したらオブジェクトを非アクティブにする
	}

	frameTimer_ = frameTimer_ - dt; // フレームタイマーを更新
	if (frameTimer_ < 0) // フレームタイマーがフレーム時間を超えたら
	{
		frame_++; // フレームを進める
		if (frame_ >= MAX_FRAME) // フレームが最大フレーム数を超えたら
		{
			frame_ = 8; // フレームをリセット
		}
		frameTimer_ = FRAME_TIME - frameTimer_;


	}
	
		
}

void Effect::Draw() 
{
	DrawExtendGraphF(pos_.x, pos_.y, pos_.x+EFFECT_IMAGE_SIZE, pos_.y+EFFECT_IMAGE_SIZE, hImage_[frame_], TRUE); // エフェクトの描画
}
