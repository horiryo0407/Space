#include "Player.h"
#include "DxLib.h"
#include "globals.h"
#include "Input.h"
#include "Bullet.h"
#include "Effect.h"
#include "EnemyBeam.h"




namespace
{
	const float PLAYER_INIT_SPEED = 200.0f; // プレイヤーの初期移動速度;
	const int PLAYER_IMAGE_WIDTH = 48; // プレイヤーの画像の幅;
	const int PLAYER_IMAGE_HEIGHT = 48; // プレイヤーの画像の高さ;
	const int PLAYER_BASE_MARGIN = 32; // プレイヤーの基準マージン;

	const float PLAYER_INIT_X = WIN_WIDTH / 2 - PLAYER_IMAGE_WIDTH / 2; // プレイヤーの初期X座標;
	const float PLAYER_INIT_Y = WIN_HEIGHT - PLAYER_IMAGE_HEIGHT - PLAYER_BASE_MARGIN; // プレイヤーの初期Y座標;
	const int BULLET_IMAGE_MARGIN = 17; // 弾の画像のマージン;
	const float BULLET_INTERVAL = 0.5f; // 弾の発射間隔;
	const int PLAYER_BULLET_NUM = 5; // プレイヤーが同時に発射できる弾の数;
}



bool CheckHit(const Rect& a, const Rect& b) {
	return !(a.x + a.width < b.x || b.x + b.width < a.x ||
		a.y + a.height < b.y || b.y + b.height < a.y);
}



Player::Player()
	:GameObject(), hImage_(-1), x_(0), y_(0), speed_(0), imageSize_({ PLAYER_IMAGE_WIDTH, PLAYER_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph("Assets\\tiny_ship5.png"); // プレイヤーの画像を読み込む
	if (hImage_ == -1) {
		// 画像の読み込みに失敗した場合のエラーハンドリング
		// エラーを返してゲーム終了
	}
	x_ = PLAYER_INIT_X; // 初期座標
	y_ = PLAYER_INIT_Y; // 初期座標
	speed_ = PLAYER_INIT_SPEED; // 移動速度
	for (int i = 0;i < PLAYER_BULLET_NUM;i++)
	{
		bullets_.push_back(new Bullet(-10,-10)); // 弾のベクターを初期化
	}

	AddGameObject(this); // プレイヤーオブジェクトをゲームオブジェクトのベクターに追加
}

Player::~Player()
{
	
	//画面サイズを解放（あとで書く！）
}

void Player::Update()
{
	if (isDead_) 
		return;
	Point nextP = { x_,y_ };
	float dt = GetDeltaTime(); // フレーム間の時間差を取得
	if (Input::IsKeepKeyDown(KEY_INPUT_LEFT)) {
		nextP.x = x_ - speed_ * dt; // 左に移動
	}
	if (Input::IsKeepKeyDown(KEY_INPUT_RIGHT)) {
		nextP.x = x_ + speed_ * dt; // 右に移動
	}
	if (nextP.x >= 0 && nextP.x <= WIN_WIDTH - PLAYER_IMAGE_WIDTH) {
		x_ = nextP.x; // X座標を更新
		y_ = nextP.y; // Y座標を更新
	}

	Rect myRect = { x_, y_, imageSize_.x, imageSize_.y };

	for (auto obj : gameObjects) {
		EnemyBeam* beam = dynamic_cast<EnemyBeam*>(obj);
		if (beam && beam->IsFired() && CheckHit(this->GetRect(), beam->GetRect())) {
			this->Kill(); // プレイヤー死亡処理
			beam->SetFired(false); // ビーム消すならこれ
			break;
		}
	}

	static float bulletTimer = 0.0f; // 弾の発射タイマー

	if (bulletTimer > 0.0f) {
		bulletTimer -= dt; // タイマーを減少
	}

	if (Input::IsKeyDown(KEY_INPUT_SPACE)) {
		if (bulletTimer <= 0.0f) {
			Shoot(); // 弾を発射
			//new Bullet(x_ + BULLET_IMAGE_MARGIN, y_); // 弾の発射
			bulletTimer = BULLET_INTERVAL; // 弾の発射間隔をリセット
		}
	}
	
}

void Player::Draw()
{
	if (isDead_) 
		return;
	// プレイヤーの画像を描画(画像の原点は左上)
	DrawExtendGraphF(x_, y_, x_ + PLAYER_IMAGE_WIDTH, y_ + PLAYER_IMAGE_HEIGHT,
		hImage_, TRUE);
	
}
//弾を撃つ関数
void Player::Shoot()
{
	

	Bullet* blt = GetActiveBullet();
	if (blt != nullptr) {
		blt->SetPos(x_ + BULLET_IMAGE_MARGIN, y_); // 弾の位置を設定
		blt->SetFired(true); // 発射状態にする
	}
}

void Player::Kill()
{
	if (isDead_) return;  // 2回Killされないように
	isDead_ = true;
	new Effect({ x_, y_ });  // 爆発エフェクト出す
	x_ = -1000;  // 画面外に逃がす（念のため）
	y_ = -1000;
	/*isDead_ = true;
	new Effect({ x_, y_ });*/
}



Bullet* Player::GetActiveBullet()
{
	for (auto& itr : bullets_)
	{
		if (!itr->IsFired())
		{
			return itr; // 発射されていない弾を返す
		}
	}
	return nullptr;
}