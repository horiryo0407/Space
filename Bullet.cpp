#include  "Globals.h"
#include "Bullet.h"
#include "DxLib.h"
#include <string>

namespace
{
	const int BULLET_IMAGE_WIDTH = 13;
	const int BULLET_IMAGE_HEIGHT = 33;
	const int BULLET_INIT_SPEED = 200;
	const std::string BULLET_IMAGE_PATH = "Assets\\laserBlue03 1.png";//’e‚Ì‰æ‘œƒpƒX
}

Bullet::Bullet()
	:GameObject(), hImage_(-1), 
	x_(0), y_(0), speed_(0), isFired_(false),
	imageSize_({ BULLET_IMAGE_WIDTH, BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());
	speed_ = BULLET_INIT_SPEED;//ˆÚ“®‘¬“x
	isFired_ = false;
	AddGameObject(this);
}

Bullet::Bullet(float x, float y)
	:GameObject(), hImage_(-1),
	x_(x), y_(y), speed_(0),isFired_(false),
	imageSize_({ BULLET_IMAGE_WIDTH, BULLET_IMAGE_HEIGHT })
{
	hImage_ = LoadGraph(BULLET_IMAGE_PATH.c_str());
	speed_ = BULLET_INIT_SPEED;//ˆÚ“®‘¬“x
	isFired_ = false;
	AddGameObject(this);
}

Bullet::~Bullet()
{
	if (hImage_ != -1)
	{
		DeleteGraph(hImage_);//‰æ‘œ‚ÌŠJ•ú
	}
	hImage_ = -1;//‰æ‘œƒnƒ“ƒhƒ‹‚ð–³Œø‰»
}



void Bullet::Update()
{
	float dt = GetDeltaTime();
	y_ = y_ - speed_ * dt;//’e‚ÌˆÚ“®
	if (y_ < 0)
	{
		isFired_ = false;//‰æ–ÊŠO‚Éo‚½‚ç€”õó‘Ô‚É–ß‚·
	}
}

void Bullet::Draw()
{
	//”­ŽË‚³‚ê‚Ä‚¢‚½‚ç•`‰æ
	if (isFired_)
	{
		DrawExtendGraphF(x_, y_, x_ + imageSize_.x, y_ + imageSize_.y, hImage_, TRUE);//’e‚Ì•`‰æ
	}
}

void Bullet::SetPos(float x, float y)
{
	x_ = x;
	y_ = y;
}
