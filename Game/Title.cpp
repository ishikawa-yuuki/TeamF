#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Help.h"

const static int Game_Y = -10.0f;   //ゲーム文字のyの位置
const static int Config_Y = -150.0f; //設定文字のyの位置

typedef enum {
	Menu_Game,     //ゲーム
	Menu_config,   //設定
	Menu_Num,      //項目の数
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
	

	if (Pad(0).IsTrigger(enButtonDown) == true) {//下キーが押されていたら選択状態を一つ下げる
		NowSelect = (NowSelect + 1) % Menu_Num;
		
	}
	if (Pad(0).IsTrigger(enButtonUp) == true){//上キーが押されていたら選択状態を一つ上げる 
		NowSelect = (NowSelect + (Menu_Num - 1)) % Menu_Num; 

	}
	if (Pad(0).IsPress(enButtonA) == true) {//エンターキーが押されていたら
		switch (NowSelect)                  //現在選択中の状態によって処理を分岐
		{
		case Menu_Game://ゲーム選択中なら
			DeleteGO(m_sound);
			DeleteGO(this);
			NewGO<Game>(0, "Game");//ゲーム画面に
			break;
		case Menu_config://設定画面中なら
			DeleteGO(m_sound);
			DeleteGO(this);  
			NewGO<Help>(0);      //設定画面に
			break;
		}
	}
	
}
void Title::PostRender(CRenderContext& rc)
{

	m_game.Begin(rc);
	const wchar_t* Start =
		L"ゲームスタート\n";
	m_select.Draw(
		Start,
		{ -20.0f, -10.0f },
		CVector4::White,
		0.0f,
		2.0f
	); m_game.End(rc);
	
	m_config.Begin(rc);
	const wchar_t* Config =
		L"ヘルプ\n";
	m_config.Draw(
		Config,
		{ -50.0f, -150.0f },
		CVector4::White,
		0.0f,
		2.0f
	);
	m_config.End(rc);

	m_select.Begin(rc);
	const wchar_t* Sirusi =
		L">\n";
	m_select.Draw(Sirusi,
		{ -360.0f, -10.0f },
		CVector4::Black,
		0.0f,
		1.5f
	);
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