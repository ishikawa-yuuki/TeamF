#include "stdafx.h"
#include "Item.h"
#include "Game.h"
#include "Player.h"
Item::Item()
{
}


Item::~Item()
{
	DeleteGO(m_modelrender);
}

bool Item::Start()
{
	m_player = FindGO<Player>("Player");

	m_modelrender = NewGO<prefab::CSkinModelRender>(0);
	m_modelrender->Init(L"modelData/box.cmo");
	m_modelrender->SetPosition(m_position);
	m_modelrender->SetScale(m_scale);
	m_modelrender->SetRotation(m_rotation);
	return true;
}

void Item::Update()
{

	CVector3 diff = m_player->m_position - m_position;
	if (diff.Length() < 100.0f) {
		Game* game = FindGO<Game>("Game");
		game->Nhp += 10;
		game->NHPkaba += 10;
		m_player->m_hp->SetScale({ game->Nhp / game->HP, 1.0f, 1.0f });
		m_player->m_hpber->SetScale({ game->NHPkaba / game->HP, 1.0f, 1.0f });
		m_sound = NewGO<prefab::CSoundSource>(0);
		m_sound->Init(L"sound/heal02.wav");
		m_sound->Play(false); 
		m_effect = NewGO<prefab::CEffect>(0);
		m_effect->Play(L"effect/heal.efk");
		m_effect->SetPosition(m_position);
		game->RemoveenemyFromList5(this);
		DeleteGO(this);
		
	}
}