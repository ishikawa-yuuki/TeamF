#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"
#include "Camera.h"
#include "Enemy.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Bullet.h"
#include "Boss.h"
#include "Item.h"
#include "PowerItem.h"
#include "Camera.h"
#include "Score.h"
class Result;
class Game : public IGameObject
{
public:
	Game();
	~Game();
	bool Start();
	void Update();
	void OnDestroy();
	void RemoveenemyFromList(Enemy* enemy)
	{
		std::vector<Enemy*>::iterator it = std::find(
			m_enemyList.begin(),
			m_enemyList.end(),
			enemy
		);
		if (it != m_enemyList.end()) {
			m_enemyList.erase(it);
		}
	}

	void RemoveenemyFromList2(Enemy2* enemy2)
	{
		std::vector<Enemy2*>::iterator it = std::find(
			m_enemy2List.begin(),
			m_enemy2List.end(),
			enemy2
		);
		if (it != m_enemy2List.end()) {
			m_enemy2List.erase(it);
		}
	}

	void RemoveenemyFromList3(Enemy3* enemy3)
	{
		std::vector<Enemy3*>::iterator it = std::find(
			m_enemy3List.begin(),
			m_enemy3List.end(),
			enemy3
		);
		if (it != m_enemy3List.end()) {
			m_enemy3List.erase(it);
		}
	}

	void RemoveenemyFromList4(Boss* boss)
	{
		std::vector<Boss*>::iterator it = std::find(
			m_bossList.begin(),
			m_bossList.end(),
			boss
		);
		if (it != m_bossList.end()) {
			m_bossList.erase(it);
		}
	}

	void RemoveenemyFromList5(Item* m_item)
	{
		std::vector<Item*>::iterator it = std::find(
			m_itemList.begin(),
			m_itemList.end(),
			m_item
		);
		if (it != m_itemList.end()) {
			m_itemList.erase(it);
		}
	}
	void PostRender(CRenderContext& rc);
	prefab::CDirectionLight*m_lig;
	CVector3 m_lightDir;
	std::vector<Enemy*> m_enemyList;
	std::vector<Enemy2*> m_enemy2List;
	std::vector<Enemy3*> m_enemy3List;
	std::vector<Boss*> m_bossList;
	std::vector<Item*> m_itemList;
	prefab::CEffect* m_effect;
	Player * m_player;
	Enemy2* enemy2;
	Enemy3* m_ene3;
	PowerItem* m_power;
	Camera* m_camera;
	Bullet* m_bullet;
	Boss* m_boss;
	Item* m_item;
	Result* result;
	Score* m_s;
	CLevel m_level;
	//int gekihacount = 0;
	int Over = false;
	int Clear = false;
	int Ctime = 0;
	int timer = 10;
	int time = 30;
	int m_timer = 0;
	int m_score = 0;
	int HP = 20;
	float Nhp = 20;
	float NHPkaba = 20;
	//float Bossgekiha = 0;
	CFont m_font;
	prefab::CSoundSource* m_sound;
	CVector4 m_color = CVector4::Yellow;
	CVector4 m_colo = CVector4::Black;
	CVector3 m_position = CVector3::Zero;
	prefab::CSky* m_sky = nullptr;
	prefab::CSpriteRender*m_spriteRender = nullptr;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	
};

