#pragma once
#include "GameObject.h"
#include "globals.h"

enum ETYPE
{
	ZAKO, MID, KNIGHT, BOSS, MAX_ETYPE
};


class Enemy :
	public GameObject
{

	int hImage_;  //�G�̉摜�n���h��
	float x_, y_; //�G�̍��W
	float speed_; //�G�̈ړ����x
	Point imageSize_; // �G�̉摜�T�C�Y
	float moveTime_;
	

	int ID_; //�G��ID
	ETYPE type_; //�G�̎��
public:
	Enemy(int id, ETYPE type);
	Enemy();
	~Enemy();
	void Update() override;
	void Draw() override;
	void SetPos(float x, float y) { x_ = x; y_ = y; } //�G�̍��W��ݒ�
	Rect GetRect() const { return { x_, y_, imageSize_.x, imageSize_.y }; } // �G�̋�`���擾	
	//void SetID(int id) { ID_ = id; } //�G��ID��ݒ�
	void SetMaxMoveX(float xmax) { xMoveMax_ = xmax; } // �G�̍ő�ړ�X���W��ݒ�
	void SetXorigin(float x) { xorigin_ = x; } // �G��X���W�̌��_��ݒ�
    protected:  
       float xMoveMax_; // �G�̍ő�ړ�X���W
       float xorigin_; // �G��X���W�̌��_
};