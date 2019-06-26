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
		L"ƒQ[ƒ€ƒXƒ^[ƒg\n";
	m_select.Draw(
		Start,
		{ -50.0f, -10.0f },
		CVector4::White,
		0.0f,
		1.1f
	);

	const wchar_t* Config =
		L"ƒwƒ‹ƒv\n";
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
	switch (NowSelect) {//Œ»İ‚Ì‘I‘ğó‘Ô‚É]‚Á‚Äˆ—‚ğ•ªŠò
	case Menu_Game://ƒQ[ƒ€‘I‘ğ’†‚È‚ç
		y = Game_Y;    //ƒQ[ƒ€‚ÌÀ•W‚ğŠi”[
		break;
	case Menu_config://İ’è‘I‘ğ’†‚È‚ç
		y = Config_Y;    //İ’è‚ÌÀ•W‚ğŠi”[
		break;
	}
	
}