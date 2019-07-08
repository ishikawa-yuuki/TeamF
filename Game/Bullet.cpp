#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet()
{
	m_skinrender = NewGO<prefab::CSkinModelRender>(0);
	m_skinrender->Init(L"modelData/Bullet.cmo");
}

Bullet::~Bullet()
{
	DeleteGO(m_skinrender);
}

bool Bullet::Start()
{
	return true;
}
void Bullet::Move()
{
}
void Bullet::Update()
{
	m_position += m_movespeed;
	m_skinrender->SetPosition(m_position);
	m_timer++;
	if (m_timer == 70) {
		DeleteGO(this);
	}
}