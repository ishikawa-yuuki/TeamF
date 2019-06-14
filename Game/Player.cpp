#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include "Enemy.h"


Player::Player()
{
}


Player::~Player()
{
	DeleteGO(m_skinModelRender);
}

bool Player::Start()
{
	m_skinModelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinModelRender->Init(L"modelData/unityChan.cmo");
	m_characon.Init(
		30.0f,
		100.0f,
		m_position);
	return true;
}
void Player::Update()
{
	m_movespeed.x = Pad(0).GetLStickXF() * 700.0f;
	m_movespeed.z = Pad(0).GetLStickYF() * 700.0f;
	m_position = m_characon.Execute(m_movespeed);
	m_skinModelRender->SetPosition(m_position);

}