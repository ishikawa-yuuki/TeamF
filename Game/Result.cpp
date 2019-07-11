#include "stdafx.h"
#include "Result.h"
#include "Title.h"
#include "Game.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Score.h"
Result::Result()
{

	m_spriterender = NewGO< prefab::CSpriteRender>(0);
	m_spriterender->Init(L"sprite/result.dds", 1280.0f, 720.0f);
	//m_score = NewGO<prefab::CFontRender>(0);
	game = FindGO<Game>("Game", false);
	m_s = FindGO<Score>("Score", false);
}


Result::~Result()
{
	DeleteGO(m_spriterender);
	DeleteGO(m_s);
}

void Result::Update()
{
	/*wchar_t score[256];
	swprintf(score, L"スコア\n%d", game->m_score);
	m_score->SetText(score);
	m_score->SetPosition({ -450.0f,-10.0f });
	m_score->SetScale(1.5f);
	*/

	if (Pad(0).IsTrigger(enButtonB) == true)
	{
		NewGO<Title>(0);
		DeleteGO(this);
	}


}


void Result::PostRender(CRenderContext& rc)
{
	wchar_t text[256];

	swprintf(text, L"スコア\n%d", m_s->m_score);
	m_scoa.Begin(rc);
	m_scoa.Draw(
		text,
		{ -450.0f,-10.0f },
		CVector4::Black,
		0.0f,
		1.5f
	);
	m_scoa.End(rc);
	
	swprintf(text, L"撃破数\n%d",  m_s->gekihacount);
	m_kazu.Begin(rc);
	m_kazu.Draw(
		text,
		{ -520.0f,140.0f },
		CVector4::Black,
		0.0f,
		1.5f
	);
	m_kazu.End(rc);

	m_sougou.Begin(rc);
	const wchar_t* Sougou=
		L"総合スコア\n";
	m_sougou.Draw(
		Sougou,
		{ 300.0f,200.0f },
		CVector4::Black,
		0.0f,
		1.5f
	); 
	m_sougou.End(rc);
	
	
	if (m_s->gekihacount <= 3)
	{
		m_spriterender = NewGO< prefab::CSpriteRender>(0);
		m_spriterender->Init(L"sprite/C.dds", 300.0f, 300.0f);
		CVector3 C;
		C.x = 400.0f;
		C.y = -100.0f;
		m_spriterender->SetPosition(C);
	}
	/*if (m_s->gekihacount <= 4 || m_s->gekihacount <= 5)
	{
		m_sougou.Begin(rc);
		const wchar_t* Sougou =
			L"B\n";
		m_sougou.Draw(
			Sougou,
			{ 150.0f,120.0f },
			CVector4::Black,
			0.0f,
			1.5f
		);
		m_sougou.End(rc);
	}
		if (m_s->gekihacount <= 6 || m_s->gekihacount <= 7 || m_s->gekihacount <= 8 )
		{
			m_sougou.Begin(rc);
			const wchar_t* Sougou =
				L"A\n";
			m_sougou.Draw(
				Sougou,
				{ 150.0f,120.0f },
				CVector4::Black,
				0.0f,
				1.5f
			);
		}

		if (m_s->gekihacount >= 9)
		{
			m_sougou.Begin(rc);
			const wchar_t* Sougou =
				L"S\n";
			m_sougou.Draw(
				Sougou,
				{ 150.0f,120.0f },
				CVector4::Black,
				0.0f,
				1.5f
			);
		}*/
}