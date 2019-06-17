#pragma once
#include "Player.h"
class Camera :public IGameObject
{
public:
	Camera();
	~Camera();
	bool Start();
	void Update();
	Player* m_player;
	CVector3 m_toCameraPos;
};

