#include "stdafx.h"
#include "Help.h"
#include "Title.h"

Help::Help()
{
	m_spriterender = NewGO < prefab::CSpriteRender>(0);
	m_spriterender->Init(L"sprite/sousa.dds", 1000.0f, 520.0f);
}

Help::~Help()
{
	DeleteGO(m_spriterender);
}
void Help::Update()
{
	if (Pad(0).IsPress(enButtonB) == true)
	{
		NewGO<Title>(0);
		DeleteGO(this);
	}
}

void Help::PostRender(CRenderContext& rc)
{
	wchar_t text[256];

	swprintf(text, L"操 作 説 明\n");
	m_sousa.Begin(rc);
	m_sousa.Draw(
		text,
		{ 0.0f,300.0f },
		CVector4::White,
		0.0f,
		1.5f
	);
	m_sousa.End(rc);

	swprintf(text, L"Ａボタン：射撃/決定");
	m_sousa.Begin(rc);
	m_sousa.Draw(
		text,
		{ -100.0f, -100.0f },
		CVector4::White,
		0.0f,
		1.0f
	);
	m_sousa.End(rc);
	swprintf(text, L"左スティックボタン：移動");
	m_sousa.Begin(rc);
	m_sousa.Draw(
		text,
		{ -100.0f, -200.0f },
		CVector4::White,
		0.0f,
		1.0f
	);
	m_sousa.End(rc);
	swprintf(text, L"右スティックボタン：カメラ");
	m_sousa.Begin(rc);
	m_sousa.Draw(
		text,
		{ -100.0f, -300.0f },
		CVector4::White,
		0.0f,
		1.0f
	);
	m_sousa.End(rc);
}