#include "stdafx.h"
#include "Enemy2.h"
#include "Player.h"
#include "Game.h"
#include "Bullet.h"
#include "Result.h"
#include "Score.h"
Enemy2::Enemy2()
{
	m_Modelrender = NewGO<prefab::CSkinModelRender>(0);
	m_Modelrender->Init(L"modelData/ene.cmo");
	m_position.z = 1000.0f;
	m_Modelrender->SetPosition(m_position);
}


Enemy2::~Enemy2()
{
	DeleteGO(m_Modelrender);
}

bool Enemy2::Start()
{
	m_player = FindGO<Player>("Player");
	return true;
}

void Enemy2::Update()
{
	Game* game = FindGO<Game>("Game");
	Score* m_s = FindGO<Score>(0);

	CVector3 diff = m_player->m_position - m_position;
	if (diff.Length() < 3000.0f) {
		diff.Normalize();
		diff *= 30.0f;
		m_position += diff;
		m_Modelrender->SetPosition(m_position);
	}
	m_timer++;
	if (diff.Length() < 1000.0f && m_timer >= 20) {
		Bullet* bullet = NewGO<Bullet>(0, "Ebullet");
		bullet->m_position = m_position;
		bullet->m_movespeed.z = -30.0f;
		m_sound = NewGO<prefab::CSoundSource>(0);
		m_sound->Init(L"sound/shoot.wav");
		m_sound->SetVolume(0.05f);
		m_sound->Play(false);
		m_timer = 0.0f;
	}

	QueryGOs<Bullet>("Pbullet", [&](Bullet* bullet) {
		CVector3 dill = bullet->m_position - m_position;
		if (dill.Length() < 50.0f) {
			Game* game = FindGO<Game>("Game");
			Score* m_s = FindGO<Score>("Score");
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/bakuhatu.wav");
			m_sound->Play(false);
			m_effect = NewGO<prefab::CEffect>(0);
			m_effect->Play(L"effect/fire.efk");
			m_sound->SetVolume(0.2f);
			m_effect->SetPosition(m_position);
			CVector3 v;
			v.x = 0.1f;
			v.y = 0.1f;
			v.z = 0.1f;
			m_effect->SetScale(v);
			m_s->gekihacount++;
			//game->m_score += 200;
			m_s->m_score += 200;
			DeleteGO(this);
			DeleteGO("Pbullet");
			return false;
		}
		return true;
		});
}