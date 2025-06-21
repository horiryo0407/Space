#pragma once
#include "GameObject.h"
#include "globals.h"
class EnemyBeam :
    public GameObject
{
public:
   EnemyBeam();
   EnemyBeam(float x, float y);
   EnemyBeam(Point pos_);
    ~EnemyBeam();
    void Update() override;
    void Draw() override;

	void SetPos(float x, float y) { pos_.x = x; pos_.y = y; } // �e�̍��W��ݒ�
	void SetPos(const Point& pos) { pos_ = pos; }
    void SetFired(bool fired) { isFired_ = fired; }
    bool IsFired() const { return isFired_; }
    Rect GetRect() const { return{ pos_.x,pos_.y,imageSize_.x,imageSize_.y }; }
protected:

private:
    int hImage_;//�e�̉摜�n���h��
    Point pos_;
    float speed_;//�e�̈ړ����x
    Point imageSize_; // �e�̉摜�T�C�Y
    //int isize_x, isize_y = 5;//�e�̕\���T�C�Y
    bool isFired_;//���˂��ꂽ���ǂ����@true:���˂���Ă���@false:���˂���Ă��Ȃ�

};

