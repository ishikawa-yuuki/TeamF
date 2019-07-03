#pragma once
#include "Player.h"
#include "Bullet.h"
class Enemy2 : public IGameObject
{
public:
	Enemy2();
	~Enemy2();
	bool Start();
	void Update();
	int m_timer = 0;
	int EHP = 2;
	Player* m_player;
	prefab::CSoundSource* m_sound;
	prefab::CEffect* m_effect;
	prefab::CSkinModelRender* m_Modelrender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_movespeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
};

