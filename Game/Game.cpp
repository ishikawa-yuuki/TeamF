#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Help.h"
#include "Result.h"
#include "Boss.h"
#include "Score.h"
const float SKY_TYOKKEI = 10000.0f; //空の直径。
Game::Game()
{
	m_sky = NewGO<prefab::CSky>(0);
	m_sky->SetScale({ SKY_TYOKKEI, SKY_TYOKKEI, SKY_TYOKKEI });
	m_camera = NewGO<Camera>(0);
	m_player = NewGO<Player>(0, "Player");
	m_item = NewGO<Item>(0);
	//m_power = NewGO<PowerItem>(0);
	m_s = NewGO<Score>(0,"Score");
	
}


Game::~Game()
{
	for (auto& m_enemy : m_enemyList) {
		DeleteGO(m_enemy);
	}

	for (auto& m_enemy2 : m_enemy2List) {
		DeleteGO(m_enemy2);
	}

	for (auto& m_enemy3 : m_enemy3List) {
		DeleteGO(m_enemy3);
	}

	for (auto& m_boss : m_bossList) {
		DeleteGO(m_boss);
	}

	DeleteGO(m_camera);
	DeleteGO(m_player);
	DeleteGO(m_sky);
	QueryGOs<Item>("Item", [](Item* item)->bool
		{
			DeleteGO(item);
			return true;
		});

	//QueryGOs<PowerItem>("PowerItem", [](PowerItem* Pitem)->bool
	//	{
	//		DeleteGO(Pitem);
	//		return true;
	//	});

	DeleteGO(m_spriteRender);
	DeleteGO(m_player->m_hp);
	DeleteGO(m_player->m_hpber);
	//DeleteGO(m_s);
	QueryGOs<Bullet>("Pbullet", [](Bullet* bullet)->bool
	{
		DeleteGO(bullet);
		return true;
	});
	QueryGOs<Bullet>("Ebullet", [](Bullet* bullet)->bool
	{
		DeleteGO(bullet);
		return true;
	});
}
bool Game::Start()
{

	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/cyber.wav");
	m_sound->Play(true);

	m_level.Init(L"sora.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualObjectName(L"taiF") == true) {
			Enemy* enemy = NewGO<Enemy>(0);
			enemy->m_position = objData.position;
			enemy->m_rotation = objData.rotation;
			enemy->m_scale = objData.scale;
			m_enemyList.push_back(enemy);
			return true;
		}
		if (objData.EqualObjectName(L"falcon") == true) {
			Enemy2* enemy2 = NewGO<Enemy2>(0);
			enemy2->m_position = objData.position;
			enemy2->m_rotation = objData.rotation;
			enemy2->m_scale = objData.scale;
			m_enemy2List.push_back(enemy2);
			return true;
		}
		if (objData.EqualObjectName(L"hune") == true) {
			Enemy3* enemy3 = NewGO<Enemy3>(0);
			//Enemy2* enemy3 = NewGO<Enemy2>(0);
			enemy3->m_position = objData.position;
			enemy3->m_rotation = objData.rotation;
			enemy3->m_scale = objData.scale;
			m_enemy3List.push_back(enemy3);
			return true;
		}
		if (objData.EqualObjectName(L"mather") == true) {
			Boss* boss = NewGO<Boss>(0);
			boss->m_position = objData.position;
			boss->m_rotation = objData.rotation;
			boss->m_scale = objData.scale;
			m_bossList.push_back(boss);
			return true;
		}
		return false;
	});
	m_lightDir.Set(0.707f, 10.707f, 0.0f);
	m_lig = NewGO<prefab::CDirectionLight>(0);
	m_lig->SetDirection(m_lightDir);
	m_lig->SetColor({ 0.5f,0.5f,0.5f,1.0f });
	return true;
}

void Game::OnDestroy()
{

}

void Game::PostRender(CRenderContext& rc)
{
	m_timer++;
	if (m_timer == 60)
	{
		time--;
		m_timer = 0;
	}

	
	wchar_t text[256];

	swprintf(text, L"残り時間\n%d", time);


	m_font.Begin(rc);
	m_font.Draw(
		text,
		{ -550.0f,300.0f },
		m_color
	);
	m_font.End(rc);

	/*swprintf(text, L"スコア\n%d", m_score);
	m_font.Begin(rc);
	m_font.Draw(
		text,
		{ 450.0f,300.0f},
		m_color
	);
	m_font.End(rc);
	*/
}

void Game::Update()
{
	if (Clear == false && Over == false) {
		if (Pad(0).IsTrigger(enButtonSelect) == true)
		{
			
			NewGO<Title>(0);
			DeleteGO(this);
		}
		if (Nhp <= 0) {
			Over = true;

			//NewGO<Result>(0);
			//DeleteGO(this);
			DeleteGO(m_sound);
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/gameover.wav");
			m_sound->Play(false);
			m_spriteRender = NewGO<prefab::CSpriteRender>(0);
			m_spriteRender->Init(L"sprite/gameover.dds", 1280.0f, 720.0f);
			timer++;
			if (timer == 30) {
				NewGO<Result>(0);
				DeleteGO(this);
				
			}
		}
			if (m_s->gekihacount >= 10 && m_s->Bossgekiha == 1) {

				Clear = true;

				DeleteGO(m_sound);
				m_sound = NewGO<prefab::CSoundSource>(0);
				m_sound->Init(L"sound/clea.wav");
				m_sound->Play(false);
				m_spriteRender = NewGO<prefab::CSpriteRender>(0);
				m_spriteRender->Init(L"sprite/GameClear.dds", 1280.0f, 720.0f);
				timer++;
				if (timer == 30)
				{
					NewGO<Result>(0);
					DeleteGO(this);
				}
			}
		}
	else {
		timer++;
		
		if (timer == 30) {
			NewGO<Result>(0);
			DeleteGO(m_sound);
			DeleteGO(this);
		}
	}
}