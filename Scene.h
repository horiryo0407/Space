#pragma once


class Scene
{
public:
    virtual ~Scene() {}
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual bool IsEnd() const = 0;      // ��ʏI������
    virtual Scene* NextScene() = 0;      // ���̉�ʂւ̃|�C���^��Ԃ��inullptr�Ȃ�I���j
};
