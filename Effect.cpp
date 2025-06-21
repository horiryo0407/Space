#include "Effect.h"
#include "DxLib.h"
#include <string>

namespace
{
	const float ANIME_TIME = { 1.0f };
	const int EFFECT_IMAGE_SIZE = 48; // �G�t�F�N�g�̉摜�T�C�Y
	const std::string EIMG_PATH = "Assets\\explosion.png"; // �G�t�F�N�g�̉摜�p�X
	const int MAX_FRAME = 9; // �G�t�F�N�g�̃t���[����
	const int DIV_NUM = 3; // �摜�𕪊����鐔�i3x3�̃O���b�h�j
	const float FRAME_TIME = ANIME_TIME / MAX_FRAME; // �t���[�����Ƃ̎��� 
	
}
Effect::Effect(Point _pos)
	:GameObject(),  pos_({ _pos.x,_pos.y }), AnimTimer_(ANIME_TIME), hImage_(std::vector<int>(MAX_FRAME, -1)),frame_(0) // �G�t�F�N�g�̏�����
{
	//hImage_ = LoadGraph(EIMG_PATH.c_str()); // �G�t�F�N�g�̉摜��ǂݍ���
	LoadDivGraph(EIMG_PATH.c_str(), MAX_FRAME, 
		DIV_NUM,DIV_NUM, EFFECT_IMAGE_SIZE, EFFECT_IMAGE_SIZE,
		hImage_.data()); // �摜�𕪊����ēǂݍ���

	AddGameObject(this); // �Q�[���I�u�W�F�N�g�̃x�N�^�[�ɒǉ�
	
}


Effect::~Effect()
{
	//DeleteGraph(hImage_); // �摜�n���h�������
	for(auto& itr: hImage_)
	
		
			DeleteGraph(itr); // �e�G�t�F�N�g�摜�̃n���h�������
			hImage_.clear(); // �摜�n���h���̃x�N�^�[���N���A
		

}

void Effect::Update()
{
	float dt = GetDeltaTime(); // �t���[���Ԃ̎��ԍ����擾
	AnimTimer_ = AnimTimer_ - dt; // �A�j���[�V�����^�C�}�[������
	if (AnimTimer_ <= 0)
	
	{
		
		this->isAlive_ = false; // �A�j���[�V�������I��������I�u�W�F�N�g���A�N�e�B�u�ɂ���
	}

	frameTimer_ = frameTimer_ - dt; // �t���[���^�C�}�[���X�V
	if (frameTimer_ < 0) // �t���[���^�C�}�[���t���[�����Ԃ𒴂�����
	{
		frame_++; // �t���[����i�߂�
		if (frame_ >= MAX_FRAME) // �t���[�����ő�t���[�����𒴂�����
		{
			frame_ = 8; // �t���[�������Z�b�g
		}
		frameTimer_ = FRAME_TIME - frameTimer_;


	}
	
		
}

void Effect::Draw() 
{
	DrawExtendGraphF(pos_.x, pos_.y, pos_.x+EFFECT_IMAGE_SIZE, pos_.y+EFFECT_IMAGE_SIZE, hImage_[frame_], TRUE); // �G�t�F�N�g�̕`��
}
