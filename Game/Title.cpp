#include "stdafx.h"
#include "Title.h"
#include "Game.h"


Title::Title()
{
	m_SpriteRender = NewGO<prefab::CSpriteRender>(0);
	m_SpriteRender->Init(L"sprite/title.dds", 1280.0f, 720.0f);
}


Title::~Title()
{
	DeleteGO(m_SpriteRender);
}

bool Title::Start()
{
	m_bgmSoundSource = NewGO<prefab::CSoundSource>(0);
	m_bgmSoundSource->Init(L"sound/noroinouta.wav");
	m_bgmSoundSource->Play(true);
	return true;
}

void Title::Update()
{
	if (Pad(0).IsPress(enButtonA) == true) {
		NewGO<Game>(0, "Game");
		DeleteGO(m_bgmSoundSource);
		DeleteGO(this);
	}
}