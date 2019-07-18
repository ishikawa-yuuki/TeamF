#include "stdafx.h"
#include "Enemy3.h"
#include "Player.h"
#include "Game.h"
#include "Bullet.h"
#include "Result.h"
#include "Score.h"
Enemy3::Enemy3()
{

}


Enemy3::~Enemy3()
{
	DeleteGO(m_Modelrender);
	
}

bool Enemy3::Start()
{
	m_player = FindGO<Player>("Player");

	m_Modelrender = NewGO<prefab::CSkinModelRender>(0);
	m_Modelrender->Init(L"modelData/hune.cmo");
	m_Modelrender->SetPosition(m_position);
	m_Modelrender->SetScale(m_scale);
	m_Modelrender->SetRotation(m_rotation);
	return true;
}

void Enemy3::Update()
{
	CVector3 diff = m_player->m_position - m_position;
	if (diff.Length() < 1000.0f) {
		diff.Normalize();
		diff *= 10.0f;
		m_position += diff;
		m_Modelrender->SetPosition(m_position);
	}
	m_timer++;
	if (diff.Length() < 1000.0f && m_timer >= 20) {
		Bullet* bullet = NewGO<Bullet>(0, "Ebullet");
		bullet = NewGO<Bullet>(0, "Ebullet");
		bullet->m_position = m_position;
		bullet->m_movespeed.x = -10.0f;
		bullet->m_movespeed.z = -50.0f;

		bullet = NewGO<Bullet>(0, "Ebullet");
		bullet->m_position = m_position;
		bullet->m_movespeed.x = 10.0f;
		bullet->m_movespeed.z = -50.0f;

		m_sound = NewGO<prefab::CSoundSource>(0);
		m_sound->Init(L"sound/shoot.wav");
		m_sound->SetVolume(0.05f);
		m_sound->Play(false);
		m_timer = 0.0f;
	}

	QueryGOs<Bullet>("Pbullet", [&](Bullet* bullet) {
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

	if (EHP <= 0) {
		Game* game = FindGO<Game>("Game");
		Score* m_s = FindGO<Score>("Score");
		m_sound = NewGO<prefab::CSoundSource>(0);
		m_sound->Init(L"sound/bakuhatu.wav");
		m_sound->Play(false);
		m_effect = NewGO<prefab::CEffect>(0);
		m_effect->Play(L"effect/baku.efk");
		m_effect->SetPosition(m_position);
		/*CVector3 v;
		v.x = 0.5f;
		v.y = 0.5f;
		v.z = 0.5f;*/
		/*m_effect->SetScale(v);*/
		m_s->gekihacount++;
		//game->m_score += 200;
		m_s->m_score += 200;
		game->RemoveenemyFromList3(this);
		DeleteGO(this);
		DeleteGO("Pbullet");
	}
}