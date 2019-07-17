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
	float lStick_x = Pad(0).GetLStickXF();
	float lStick_y = Pad(0).GetLStickYF();
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	cameraForward.y = 0.0f;
	cameraForward.Normalize();
	m_movespeed.x = 0.0f;
	m_movespeed.z = 0.0f;
	m_movespeed.y = 0.0f * GameTime().GetFrameDeltaTime();
	m_movespeed += cameraForward * lStick_y * 600.0f;
	m_movespeed += cameraRight * lStick_x * 600.0f;
	m_position = m_chracon.Execute(m_movespeed, GameTime().GetFrameDeltaTime());
}

void Player::Update()
{
	CQuaternion qRot = CQuaternion::Identity;
	if (Pad(0).IsPress(enButtonRight)) {
		qRot.SetRotationDeg(CVector3::AxisY, 10.0f);
	}
	else if (Pad(0).IsPress(enButtonLeft)) {
		qRot.SetRotationDeg(CVector3::AxisY, -10.0f);
	}
	m_rotation.Multiply(qRot);

	CVector3 stick;
	stick.x = Pad(0).GetRStickXF();
	stick.y = -Pad(0).GetRStickYF();
	stick.z = 0.0f;
	qRot.SetRotationDeg(CVector3::AxisY, stick.x * 2.0f);
	m_rotation.Multiply(qRot);
	Move();
	m_timer++;
	if (Pad(0).IsPress(enButtonA)&& m_timer >= 10) {
		Bullet* bullet = NewGO<Bullet>(0, "Pbullet");
		bullet->m_position = m_position;
		bullet->m_movespeed.z = MainCamera().GetForward().z*30.0f;
		bullet->m_movespeed.x = MainCamera().GetForward().x*30.0f;
		bullet->m_skinrender->SetRotation(m_rotation);
		m_sound = NewGO<prefab::CSoundSource>(0);
		m_sound->Init(L"sound/shoot.wav");
		m_sound->Play(false);
		m_timer = 0;
	}

	QueryGOs<Bullet>("Ebullet", [&](Bullet*bullet)->bool {
		CVector3 dill = bullet->m_position - m_position;
		if (dill.Length() <= 50.0f) {
			Game* game = FindGO<Game>("Game");
			game->Nhp--;
			m_hp->SetScale({ game->Nhp/game->HP, 1.0f, 1.0f });
			m_hpber->SetScale({ game->NHPkaba / game->HP, 1.0f, 1.0f });
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/damege.wav");
			m_sound->Play(false);
			DeleteGO("Ebullet");
			return false;
		}
		return true;
	});
	m_skinmodelrender->SetRotation(m_rotation);
	m_skinmodelrender->SetPosition(m_position);
	/*if (game->Nhp == 20)
	{
		m_hp = NewGO<prefab::CSpriteRender>(0);
		m_hp->Init(L"sprite/gezi.dds", 400.0f, 40.0f);
	}*/
}
