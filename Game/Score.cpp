#include "stdafx.h"
#include "Score.h"
#include "Game.h"


Score::Score()
{
	/*m_sc = NewGO<prefab::CFontRender>(0);
	m_sc->SetShadowParam(true, 2.0f, CVector4::Black);*/
	m_game = FindGO<Game>("Game", false);
}


Score::~Score()
{
	
}

bool Score::Start()
{

	
	return true;
}
void Score::Update()
{
	/*wchar_t text[256];
	swprintf(text, L"スコア \n%d", m_score);
	m_sc->SetText(text);
	m_sc->SetPosition({ 450.0f,300.0f });
	m_sc->SetPivot({ 0.0f, 0.0f });
	*/

}

void Score::PostRender(CRenderContext& rc)
{
	wchar_t text[256];
	swprintf(text, L"スコア\n%d", m_score);
	m_sc.Begin(rc);
	m_sc.Draw(
		text,
		{ 450.0f,300.0f },
		CVector4::Black
	);
	m_sc.End(rc);
	
}