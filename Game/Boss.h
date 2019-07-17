#pragma once
#include "Player.h"
class Score;
class Boss :public IGameObject
{
public:
	Boss();
	~Boss();
	bool Start();
	void Update();
	int BossHP = 20;
	int m_timer = 0;
	Player *m_player;
	Score* m_s;
	prefab::CSoundSource* m_sound;
	prefab::CEffect* m_effect;
	prefab::CSkinModelRender* m_Modelrender = nullptr;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_movespeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
};

