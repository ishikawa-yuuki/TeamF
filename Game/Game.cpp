#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "tkEngine/light/tkDirectionLight.h"
#include "Help.h"

const float SKY_TYOKKEI = 10000.0f; //ãÛÇÃíºåaÅB
Game::Game()
{
	m_sky = NewGO<prefab::CSky>(0);
	m_sky->SetScale({ SKY_TYOKKEI, SKY_TYOKKEI, SKY_TYOKKEI });

	m_camera = NewGO<Camera>(0);
	m_player = NewGO<Player>(0, "Player");
	m_boss = NewGO<Boss>(0);
}


Game::~Game()
{
	for (auto& m_enemy : m_enemyList) {
		DeleteGO(m_enemy);
	}
	DeleteGO(m_camera);
	DeleteGO(m_player);
	DeleteGO(m_sky);
	DeleteGO(m_boss);
	DeleteGO(m_spriteRender);
	DeleteGO(m_player->m_hp);
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

}

void Game::Update()
{
	if (Clear == false && Over == false) {
		if (Pad(0).IsPress(enButtonSelect) == true)
		{
			NewGO<Title>(0);
			DeleteGO(this);
		}
		if (Nhp <= 0) {
			Over = true;
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/gameover.wav");
			m_sound->Play(false);
			m_spriteRender = NewGO<prefab::CSpriteRender>(0);
			m_spriteRender->Init(L"sprite/gameover.dds", 1280.0f, 720.0f);
			timer++;
			if (timer == 30) {
				NewGO<Title>(0);
				DeleteGO(this);
			}
		}
		if (gekihacount >= 10 && Bossgekiha >= 1) {
			Clear = true;
			m_sound = NewGO<prefab::CSoundSource>(0);
			m_sound->Init(L"sound/clea.wav");
			m_sound->Play(false);
			m_spriteRender = NewGO<prefab::CSpriteRender>(0);
			m_spriteRender->Init(L"sprite/GameClear.dds", 1280.0f, 720.0f);
			}
	}
	else {
		timer++;
		if (timer == 30) {
			NewGO<Title>(0);
			DeleteGO(this);
		}
	}
}