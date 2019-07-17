#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include "Bullet.h"
#include "Result.h"
#include "Score.h"

Enemy::Enemy()
{
}


Enemy::~Enemy()
{
	DeleteGO(m_Modelrender);
}

bool Enemy::Start()
{
	m_player = FindGO<Player>("Player");
	
	m_Modelrender = NewGO<prefab::CSkinModelRender>(0);
	m_Modelrender->Init(L"modelData/taiF.cmo");
	m_Modelrender->SetPosition(m_position);
	m_Modelrender->SetScale(m_scale);
	m_Modelrender->SetRotation(m_rotation);
	return true;
}

void Enemy::Update()
{
	CVector3 diff = m_player->m_position - m_position;
	if (diff.Length() < 1000.0f) {
		diff.Normalize();
		diff *= 15.0f;
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

	CVector3 dikk = m_player->m_position - m_position;
	if (dikk.Length() < 50.0f) {
		Game* game = FindGO<Game>("Game");
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
		//m_s->gekihacount++;
		//m_s->m_score += 100;
		game->RemoveenemyFromList(this);
		DeleteGO(this);
		game->Nhp -= 5;
	}

	QueryGOs<Bullet>("Pbullet", [&](Bullet*bullet) {
		CVector3 dill = bullet->m_position - m_position;
		if (dill.Length() < 50.0f) {
			EHP--;
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/damege.wav");
			m_sound->Play(false);
			return false;
		}
		return true;
		});
	if(EHP <= 0) {
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
			//game->m_score += 100;
			m_s->m_score += 100;
			game->RemoveenemyFromList(this);
			DeleteGO(this);
			DeleteGO("Pbullet");
		}
}