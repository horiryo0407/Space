#pragma once
#include "GameObject.h"
#include <vector>

class Player;//�O���錾
class Enemy;//�O���錾
class Stage :
    public GameObject
    
{
private:
    Player* player_;
    std::vector<Enemy*> enemy_;//�G�I�u�W�F�N�g
    Stage* stage_;
	int hBackground; // �w�i�摜�̃n���h��

public:
    Stage();
    ~Stage();
    void Update() override;
    void Draw() override;
};

