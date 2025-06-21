#pragma once


class Scene
{
public:
    virtual ~Scene() {}
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual bool IsEnd() const = 0;      // 画面終了判定
    virtual Scene* NextScene() = 0;      // 次の画面へのポインタを返す（nullptrなら終了）
};
