#pragma once
#include "GameObject.h"
#include "Globals.h"
class Bullet :
    public GameObject
{

public:
    Bullet();
    Bullet(float x, float y);
    ~Bullet();
    void Update() override;
    void Draw() override;

    void SetPos(float x, float y);
    void SetFired(bool fired) { isFired_ = fired; }
    bool IsFired() const { return isFired_; }
    Rect GetRect() const { return{ x_,y_,imageSize_.x,imageSize_.y }; }
protected:

private:
    int hImage_;//�e�̉摜�n���h��
    float x_, y_;//�e�̍��W
    float speed_;//�e�̈ړ����x
	Point imageSize_; // �e�̉摜�T�C�Y
    int isize_x, isize_y = 5;//�e�̕\���T�C�Y
    bool isFired_;//���˂��ꂽ���ǂ����@true:���˂���Ă���@false:���˂���Ă��Ȃ�
};

