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
    int hImage_;//弾の画像ハンドル
    float x_, y_;//弾の座標
    float speed_;//弾の移動速度
	Point imageSize_; // 弾の画像サイズ
    int isize_x, isize_y = 5;//弾の表示サイズ
    bool isFired_;//発射されたかどうか　true:発射されている　false:発射されていない
};

