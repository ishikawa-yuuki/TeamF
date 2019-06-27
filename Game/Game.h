#pragma once

#include "tkEngine/graphics/effect/tkEffect.h"
#include "tkEngine/physics/tkPhysicsGhostObject.h"
#include "tkEngine/character/tkCharacterController.h"
#include "Player.h"
#include "Camera.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Boss.h"
#include "Item.h"
#include "PowerItem.h"
#include "Camera.h"
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
	void PostRender(CRenderContext& rc);
	prefab::CDirectionLight*m_lig;
	CVector3 m_lightDir;
	std::vector<Enemy*> m_enemyList;
	Player * m_player;
	PowerItem* m_power;
	Camera* m_camera;
	Bullet* m_bullet;
	Boss* m_boss;
	Item* m_item;
	CLevel m_level;
	int gekihacount = 0;
	int Over = false;
	int Clear = false;
	int Ctime = 0;
	int timer = 10;
	int time = 30;
	int m_timer = 0;
	int m_score = 0;
	int HP = 20;
	float Nhp = 20;
	float Bossgekiha = 0;
	CFont m_font;
	prefab::CSoundSource* m_sound;
	CVector4 m_color = CVector4::Yellow;
	CVector4 m_colo = CVector4::Black;
	CVector3 m_position = CVector3::Zero;
	prefab::CSky* m_sky = nullptr;
	prefab::CSpriteRender*m_spriteRender = nullptr;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
};

