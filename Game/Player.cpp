#include "stdafx.h"
#include "Player.h"
#include "Game.h"
#include "Bullet.h"


Player::Player()
{
	
	m_skinmodelrender = NewGO<prefab::CSkinModelRender>(0);
	m_skinmodelrender->Init(L"modelData/kitai.cmo");
	m_chracon.Init(
		30.0f,
		100.0f,
		m_position
	);

	m_hp = NewGO<prefab::CSpriteRender>(0);
	m_hp->Init(L"sprite/gezi.dds", 300.0f, 40.0f);
	CVector3 ps;
	ps.x = -550.0f;
	ps.y = -300.0f;
	m_hp->SetPosition(ps);
	m_hp->SetPivot({ 0.0f, 0.5f });
	m_hpber = NewGO<prefab::CSpriteRender>(0);
	m_hpber->Init(L"sprite/gezikaba.dds", 330.0f, 55.0f);
	CVector3 psk;
	psk.x = -560.0f;
	psk.y = -300.0f;
	m_hpber->SetPosition(psk);
	m_hpber->SetPivot({ 0.0f, 0.5f });
}



Player::~Player()
{
	DeleteGO(m_skinmodelrender);
}

void Player::Move()
{

}

void Player::Trun()
{
	if (fabsf(m_movespeed.x) < 1.0f
		&& fabsf(m_movespeed.z) < 1.0f) {
		return;
	}
	float angle = atan2(m_movespeed.x, m_movespeed.z);
	m_rotation.SetRotation(CVector3::AxisY, -angle);
}

void Player::Update()
{
	Trun();
	m_timer++;
	if (Pad(0).IsPress(enButtonA)&& m_timer >= 10) {
		Bullet* bullet = NewGO<Bullet>(0, "Pbullet");
		bullet->m_position = m_position;
		bullet->m_movespeed.z = 30.0f;
		m_sound = NewGO<prefab::CSoundSource>(0);
		m_sound->Init(L"sound/shoot.wav");
		m_sound->Play(false);
		m_timer = 0;
	}

	QueryGOs<Bullet>("Ebullet", [&](Bullet*bullet)->bool {
		CVector3 dill = bullet->m_position - m_position;
		if (dill.Length() < 50.0f) {
			Game* game = FindGO<Game>("Game");
			game->Nhp--;
			m_hp->SetScale({ game->Nhp/game->HP, 1.0f, 1.0f });
			m_hpber->SetScale({ game->Nhp / game->HP, 1.0f, 1.0f });
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/damege.wav");
			m_sound->Play(false);
			DeleteGO("Ebullet");
			return false;
		}
		return true;
	});
	m_movespeed.x = Pad(0).GetLStickXF() * 600.0f;
	m_movespeed.z = Pad(0).GetLStickYF() * 600.0f;
	m_position = m_chracon.Execute(m_movespeed);

	m_skinmodelrender->SetPosition(m_position);
}
