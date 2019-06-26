#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Help.h"

const static int Game_Y = -10.0f;
const static int Config_Y = -70.0f;

typedef enum {
	Menu_Game,
	Menu_config,
	Menu_Num,
}Menu;

static int NowSelect = Menu_Game;

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
	/*if (Pad(0).IsPress(enButtonA) == true) {
		DeleteGO(m_sound);
		DeleteGO(this);
		NewGO<Game>(0, "Game");
	}
	if (Pad(0).IsPress(enButtonB) == true)
	{
		DeleteGO(this);
		NewGO<Help>(0);
	}*/
	if (Pad(0).IsTrigger(enButtonDown) == true) {
		NowSelect = (NowSelect + 1) % Menu_Num;
	}
	if (Pad(0).IsTrigger(enButtonUp) == true)
	{
		NowSelect = (NowSelect + (Menu_Num - 1)) % Menu_Num;
	}
	if (Pad(0).IsPress(enButtonA) == true) {
		switch (NowSelect)
		{
		case Menu_Game:
			DeleteGO(m_sound);
			DeleteGO(this);
			NewGO<Game>(0, "Game");
			break;
		case Menu_config:
			DeleteGO(m_sound);
			DeleteGO(this);
			NewGO<Help>(0);
			break;
		}
	}

}
void Title::PostRender(CRenderContext& rc)
{

	m_select.Begin(rc);
	const wchar_t* Start =
		L"ゲームスタート\n";
	m_select.Draw(
		Start,
		{ -50.0f, -10.0f },
		CVector4::White,
		0.0f,
		1.1f
	);

	const wchar_t* Config =
		L"ヘルプ\n";
	m_select.Draw(
		Config,
		{ -50.0f, -70.0f },
		CVector4::White,
		0.0f,
		1.1f
	);

	const wchar_t* Sirusi =
		L">\n";
	m_select.Draw(Sirusi,
		{ -240.0f, -10.0f },
		CVector4::Black,
		0.0f,
		1.0f);
	m_select.End(rc);
	int y = 0;
	switch (NowSelect) {//現在の選択状態に従って処理を分岐
	case Menu_Game://ゲーム選択中なら
		y = Game_Y;    //ゲームの座標を格納
		break;
	case Menu_config://設定選択中なら
		y = Config_Y;    //設定の座標を格納
		break;
	}
	
}