#include "stdafx.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"


Enemy::Enemy()
{
	//CVector3 oldposition = m_position;
}


Enemy::~Enemy()
{
	DeleteGO(m_skinmodelRender);
}

bool Enemy::Start() 
{
	m_player = FindGO<Player>("Player");
	m_skinmodelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinmodelRender->Init(L"modelData/enemy.cmo");
	m_skinmodelRender->SetPosition(m_position);
	m_skinmodelRender->SetScale(m_scale);
	m_skinmodelRender->SetRotation(m_rotation);
	return true;
}

void Enemy::Update()
{

	CVector3 diff = m_player->m_position - m_position;
	if (diff.Length() < 400.0f) {
		diff.Normalize();
		diff *= 10.0f;
		m_position += diff;
		m_skinmodelRender->SetPosition(m_position);
	}
	CVector3 H = m_player->m_position - m_position;
	if (H.Length() < 100.0f) {
		
		Game* game = FindGO<Game>("Game");
		game->DeathCount++;
	}
}