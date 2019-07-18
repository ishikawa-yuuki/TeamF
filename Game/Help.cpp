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

	swprintf(text, L"�� �� �� ��\n");
	m_sousa.Begin(rc);
	m_sousa.Draw(
		text,
		{ 0.0f,300.0f },
		CVector4::White,
		0.0f,
		1.5f
	);
	m_sousa.End(rc);

	swprintf(text, L"�`�{�^���F�ˌ�/����");
	m_sousa.Begin(rc);
	m_sousa.Draw(
		text,
		{ -100.0f, -100.0f },
		CVector4::White,
		0.0f,
		1.0f
	);
	m_sousa.End(rc);
	swprintf(text, L"���X�e�B�b�N�{�^���F�ړ�");
	m_sousa.Begin(rc);
	m_sousa.Draw(
		text,
		{ -100.0f, -200.0f },
		CVector4::White,
		0.0f,
		1.0f
	);
	m_sousa.End(rc);
	swprintf(text, L"�E�X�e�B�b�N�{�^���F�J����");
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