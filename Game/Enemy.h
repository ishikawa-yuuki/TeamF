#pragma once

class Player;
class Enemy : public IGameObject
{
public:
	Enemy();
	~Enemy();
	void Update();
	bool Start();
	Player* m_player;
	Enemy* m_enemy;
	int DeathCount = 0;
	CVector3 m_position = CVector3::Zero;
	CVector3 oldposition = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
	CVector3 m_movespeed = CVector3::Zero;
	CPhysicsStaticObject m_phyStaticObject;
	prefab::CSkinModelRender* m_skinmodelRender = nullptr;
};

