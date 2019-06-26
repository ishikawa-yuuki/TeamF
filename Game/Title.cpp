#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Help.h"


Title::Title()
{
	
	m_spriterender = NewGO < prefab::CSpriteRender>(0);
	m_spriterender->Init(L"sprite/Titlesora.dds", 1280.0f, 720.0f);
	m_select.SetShadowParam(true, 2.0f, { 0.4f, 0.4f, 0.4f, 1.0f });
}

Title::~Title()
{
	DeleteGO(m_spriterender);
}

bool Title::Start()
{
	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/loop2.wav");
	m_sound->Play(true);
	return true;
}

void Title::Update()
{
	if (Pad(0).IsPress(enButtonA) == true) {
		DeleteGO(m_sound);
		DeleteGO(this);
		NewGO<Game>(0, "Game");
	}
	if (Pad(0).IsPress(enButtonB) == true)
	{
		DeleteGO(this);
		NewGO<Help>(0);
	}
	
}
void Title::PostRender(CRenderContext& rc)
{
	m_select.Begin(rc);
	const wchar_t* select =
		L"ゲームスタートはＡボタンを押してね\n"
		"\n"
		L"ヘルプはBボタを押してね\n"
		"\n"
		L"クレジットは\n";
	m_select.Draw(
		select,
		{ -250.0f, -10.0f },
		CVector4::White,
		0.0f,
		1.1f
	);
	m_select.End(rc);
}