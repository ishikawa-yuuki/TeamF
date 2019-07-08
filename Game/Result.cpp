#include "stdafx.h"
#include "Result.h"
#include "Title.h"
#include "Game.h"

Result::Result()
{

	m_spriterender = NewGO< prefab::CSpriteRender>(0);
	m_spriterender->Init(L"sprite/result.dds", 1280.0f, 720.0f);
	
}


Result::~Result()
{
	DeleteGO(m_spriterender);
}

void Result::Update()
{
	

	if (Pad(0).IsPress(enButtonB) == true)
	{
		NewGO<Title>(0);
		DeleteGO(this);
	} 

}


void Result::PostRender(CRenderContext& rc)
{
	
	wchar_t text[256];
	swprintf(text, L"スコア\n%d");
	m_scoa.Begin(rc);
	m_scoa.Draw(
		text,
		{ -450.0f,-10.0f },
		CVector4::Black,
		0.0f,
		1.5f
	);
	m_scoa.End(rc);

	swprintf(text, L"経過時間\n%d");
	m_zikan.Begin(rc);
	m_zikan.Draw(
		text,
		{ -520.0f,140.0f },
		CVector4::Black,
		0.0f,
		1.5f
	);
	m_zikan.End(rc);

	m_sougou.Begin(rc);
	const wchar_t* Sougou=
		L"総合スコア\n";
	m_sougou.Draw(
		Sougou,
		{ -380.0f,-170.0f },
		CVector4::Black,
		0.0f,
		1.5f
	); 
	m_sougou.End(rc);
	
}