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

	void SetPos(float x, float y) { pos_.x = x; pos_.y = y; } // 弾の座標を設定
	void SetPos(const Point& pos) { pos_ = pos; }
    void SetFired(bool fired) { isFired_ = fired; }
    bool IsFired() const { return isFired_; }
    Rect GetRect() const { return{ pos_.x,pos_.y,imageSize_.x,imageSize_.y }; }
protected:

private:
    int hImage_;//弾の画像ハンドル
    Point pos_;
    float speed_;//弾の移動速度
    Point imageSize_; // 弾の画像サイズ
    //int isize_x, isize_y = 5;//弾の表示サイズ
    bool isFired_;//発射されたかどうか　true:発射されている　false:発射されていない

};

