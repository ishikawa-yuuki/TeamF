#pragma once
#include "Player.h"
#include "Bullet.h"
class Score;
class Enemy3 : public IGameObject
{
public:
	Enemy3();
	~Enemy3();
	bool Start();
	void Update();
	int m_timer = 0;
	int EHP = 5;
	Player* m_player;
	Score* m_s;
	prefab::CSoundSource* m_sound;
	prefab::CEffect* m_effect;
	prefab::CSkinModelRender* m_Modelrender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_movespeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
};

