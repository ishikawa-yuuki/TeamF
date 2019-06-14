#pragma once

#include "tkEngine/camera/tkSpringCamera.h"
class Player;
class GameCamera : public IGameObject
{
public:
	GameCamera();
	~GameCamera();
	bool Start() override;
	void Update();

	Player* m_player;
	CVector3 m_toCameraPos;
	CSpringCamera m_springCamera;
};

