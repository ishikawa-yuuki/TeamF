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
	DeleteGO(m_Cspriterender);
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
		DeleteGO(m_s);
	}

}


void Result::PostRender(CRenderContext& rc)
{
	wchar_t text[256];

	swprintf(text, L"スコア\n%d", m_s->m_score);
	m_scoa.Begin(rc);
	m_scoa.Draw(
		text,
		{ -450.0f,-100.0f },
		CVector4::Black,
		0.0f,
		1.5f
	);
	m_scoa.End(rc);
	
	swprintf(text, L"撃破数\n%d",  m_s->gekihacount);
	m_kazu.Begin(rc);
	m_kazu.Draw(
		text,
		{ -470.0f,120.0f },
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
	
	CVector3 C;
	C.x = 300.0f;
	C.y = -100.0f;

		if (m_s->gekihacount <= 3&& m_Cspriterender ==nullptr)
		{
			
			m_Cspriterender = NewGO< prefab::CSpriteRender>(0);
			m_Cspriterender->Init(L"sprite/C.dds", 300.0f, 400.0f);
			m_Cspriterender->SetPosition(C);
		}

		else if (m_s->gekihacount <= 4 || m_s->gekihacount <= 5 || m_s->gekihacount <= 6)
		{
			
			m_Cspriterender = NewGO< prefab::CSpriteRender>(0);
			m_Cspriterender->Init(L"sprite/B.dds", 300.0f, 400.0f);
			m_Cspriterender->SetPosition(C);
		}
		else if (m_s->gekihacount <= 7 || m_s->gekihacount <= 8)
		{
			
			m_Cspriterender = NewGO< prefab::CSpriteRender>(0);
			m_Cspriterender->Init(L"sprite/A.dds", 300.0f, 400.0f);
			m_Cspriterender->SetPosition(C);
		}

		else if (m_s->gekihacount == 9 && game->Bossgekiha == 1)
		{
			
			m_Cspriterender = NewGO< prefab::CSpriteRender>(0);
			m_Cspriterender->Init(L"sprite/S.dds", 300.0f, 400.0f);
			m_Cspriterender->SetPosition(C);
		}
}