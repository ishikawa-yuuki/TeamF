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
	enemy2 = NewGO<Enemy2>(0, "Enemy2");
	//m_ene3 = NewGO<Enemy3>(0, "Enemy3");//
	m_boss = NewGO<Boss>(0, "Boss");
	m_item = NewGO<Item>(0);
	m_power = NewGO<PowerItem>(0);
	m_s = NewGO<Score>(0,"Score");
}


Game::~Game()
{
	for (auto& m_enemy : m_enemyList) {
		DeleteGO(m_enemy);
	}
	/*Result* m_result_tinko = FindGO<Result>("result");
	DeleteGO(m_result_tinko);*/
	DeleteGO(m_camera);
	DeleteGO(m_player);
	QueryGOs<Enemy2>("Enemy2", [](Enemy2* enemy2)->bool
		{
			DeleteGO(enemy2);
			return true;
		});
	//DeleteGO(m_ene3);
	DeleteGO(m_sky);
	//DeleteGO(m_boss);
	DeleteGO(m_item);
	DeleteGO(m_spriteRender);
	DeleteGO(m_player->m_hp);
	DeleteGO(m_player->m_hpber);
	DeleteGO(m_power);
	DeleteGO(m_s);
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

	m_level.Init(L"sora.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualObjectName(L"enemy") == true) {
			Enemy* enemy = NewGO<Enemy>(0);
			enemy->m_position = objData.position;
			enemy->m_rotation = objData.rotation;
			enemy->m_scale = objData.scale;
			m_enemyList.push_back(enemy);
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
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/gameover.wav");
			m_sound->Play(false);
			m_spriteRender = NewGO<prefab::CSpriteRender>(0);
			m_spriteRender->Init(L"sprite/gameover.dds", 1280.0f, 720.0f);
			timer++;
			m_score == true;
			if (timer == 30) {
				NewGO<Result>(0,"result");
				DeleteGO(this);
				
			}
		}
			if (m_s->gekihacount >= 10 && Bossgekiha >= 1) {

				Clear = true;

				m_sound = NewGO<prefab::CSoundSource>(0);
				m_sound->Init(L"sound/clea.wav");
				m_sound->Play(false);
				m_spriteRender = NewGO<prefab::CSpriteRender>(0);
				m_spriteRender->Init(L"sprite/GameClear.dds", 1280.0f, 720.0f);
				m_timer++;
				/*if (m_timer == 30)
				{
					DeleteGO(this);
				}*/
			}
		}
	else {
		timer++;
		
		if (timer == 30) {
		
			NewGO<Result>(0,"result");
			DeleteGO(this);
			
		}
	}
}