#include "stdafx.h"
#include "Kamikire.h"
#include "Player.h"
#include "Game.h"


Kamikire::Kamikire()
{
}


Kamikire::~Kamikire()
{
	DeleteGO(m_skinmodelRender);
}

bool Kamikire::Start()
{
	m_player = FindGO<Player>("Player");
	m_skinmodelRender = NewGO<prefab::CSkinModelRender>(0);
	m_skinmodelRender->Init(L"modelData/kamikire.cmo");
	m_skinmodelRender->SetPosition(m_position);
	m_skinmodelRender->SetScale(m_scale);
	m_skinmodelRender->SetRotation(m_rotation);
	return true;
}

void Kamikire::Update()
{
	CVector3 diff = m_position - m_player->m_position;
	if (diff.Length() < 100.0f) {
		Game* game = FindGO<Game>("Game");
		m_bgmSoundSource = NewGO<prefab::CSoundSource>(0);
		m_bgmSoundSource->Init(L"sound/hakken.wav");
		m_bgmSoundSource->Play(false);
		game->kamikireCount++;
		game->RemoveKamikireFromList(this);
		DeleteGO(this);
	}
}