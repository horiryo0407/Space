#pragma once
#include "GameObject.h"
#include "globals.h"

class Bullet; // �O���錾

class Player :
	public GameObject
{
	int hImage_;  //�v���C���[�̉摜�n���h��
	float x_, y_; //�v���C���[�̍��W
	float speed_; //�v���C���[�̈ړ����x
	bool isDead_ = false;
	Point imageSize_; // �v���C���[�̉摜�T�C�Y
	std::vector<Bullet*> bullets_; // �v���C���[�����˂����e�̃x�N�^�[
	Bullet* GetActiveBullet();
public:
	Player();
	~Player();
	void Update() override;
	void Draw() override;
	void Shoot(); // �e�𔭎˂���֐�
	bool IsDead() const { return isDead_; }
	void Kill();
	Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; } // �v���C���[�̋�`���擾
	std::vector<Bullet*> GetAllBullets() const { return bullets_; } // �S�Ă̒e���擾
	
};