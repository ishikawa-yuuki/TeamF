#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"

class Kamikire;
class Enemy;
class Player;
class GameCamera;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void OnDestroy();
	//紙切れをリストから削除する。
	void RemoveKamikireFromList(Kamikire* kamikire)
	{
		std::vector<Kamikire*>::iterator it = std::find(
			m_kamikireList.begin(),
			m_kamikireList.end(),
			kamikire
		);
		if (it != m_kamikireList.end()) {
			//紙切れが見つかったので、リストから削除。
			m_kamikireList.erase(it);
		}
	}
	CLevel m_level;
	std::vector<Enemy*> m_enemyList;
	std::vector<Kamikire*> m_kamikireList;
	Player* m_player = nullptr;
	GameCamera* m_camera = nullptr;
	int kamikireCount = 0;
	bool DeathCount = 0;
	bool m_isClear = false;
	bool m_isOver = false;
	int m_timer = 0;
	prefab::CDirectionLight* m_lig;			
	CVector3 m_lightDir;					
	prefab::CSpriteRender*m_gameoverspritRender = nullptr;
	prefab::CSpriteRender*m_clearspriteRender = nullptr;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;
};

