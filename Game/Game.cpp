#include "stdafx.h"
#include "Game.h"
#include "Title.h"
#include "GameCamera.h"
#include "Player.h"
#include "BackGround.h"
#include "Kamikire.h"
#include "Enemy.h"
#include "tkEngine/light/tkDirectionLight.h"

Game::Game()
{
	m_player = NewGO<Player>(0, "Player");
	m_camera = NewGO<GameCamera>(0);
}


Game::~Game()
{
}
bool Game::Start()
{
	/*m_lightDir.Set(0.707f, -0.707f, 10.0f);
	m_lig = NewGO<prefab::CDirectionLight>(0);
	m_lig->SetDirection(m_lightDir);
	m_lig->SetColor({ 0.5f,0.5f,0.5f,1.0f });
	GraphicsEngine().GetShadowMap().SetLightDirection({ 0.707f,0.707f,0.0f });*/
	m_level.Init(L"modelData/rouka.tkl", [&](LevelObjectData& objData) {
		if (objData.EqualObjectName(L"enemy") == true) {
			Enemy*m_enemy = NewGO<Enemy>(0);
			m_enemy->m_position = objData.position;
			m_enemy->m_rotation = objData.rotation;
			m_enemy->m_scale = objData.scale;
			m_enemyList.push_back(m_enemy);
			return true;
		}
		if (objData.EqualObjectName(L"kamikire") == true) {
			Kamikire*m_kamikire = NewGO<Kamikire>(0);
			m_kamikire->m_position = objData.position;
			m_kamikire->m_rotation = objData.rotation;
			m_kamikire->m_scale = objData.scale;
			m_kamikireList.push_back(m_kamikire);
			return true;
		}
		return false;
	});
	return true;
}
void Game::OnDestroy()
{
	for (auto& m_enemy : m_enemyList) {
		DeleteGO(m_enemy);
	}
	for (auto& m_kamikire : m_kamikireList) {
		DeleteGO(m_kamikire);
	}
	DeleteGO(m_player);
	DeleteGO(m_camera);
	DeleteGO(m_gameoverspritRender);
	DeleteGO(m_clearspriteRender);
}

void Game::Update()
{
	if (m_isClear == false) {
		if (Pad(0).IsPress(enButtonSelect) == true) {
			NewGO<Title>(0);
			DeleteGO(this);
		}
		/*if (DeathCount == 1) {
			m_isOver = true;
			m_bgmSoundSource = NewGO<prefab::CSoundSource>(0);
			m_bgmSoundSource->Init(L"sound/himei.wav");
			m_bgmSoundSource->Play(false);
			m_gameoverspritRender = NewGO<prefab::CSpriteRender>(0);
			m_gameoverspritRender->Init(L"sprite/gameover.dds", 1280.0f, 720.0f);
		}*/
		if (kamikireCount == 4) {
			m_isClear = true;
			m_bgmSoundSource = NewGO<prefab::CSoundSource>(0);
			m_bgmSoundSource->Init(L"sound/oti.wav");
			m_bgmSoundSource->Play(false);
			m_clearspriteRender = NewGO<prefab::CSpriteRender>(0);
			m_clearspriteRender->Init(L"sprite/GameClear.dds", 1280.0f, 720.0f);
		}
	}
	/*else {
		m_timer++;
		if (m_timer == 60) {
			NewGO<Title>(0);
			DeleteGO(this);
		}
	}*/
}