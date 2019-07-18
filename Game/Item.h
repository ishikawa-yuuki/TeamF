#pragma once
#include "Player.h"
class Item : public IGameObject
{
public:
	Item();
	~Item();
	bool Start();
	void Update();
	Player* m_player;
	prefab::CSkinModelRender* m_modelrender = nullptr;
	prefab::CEffect* m_effect = nullptr;
	CVector3 m_position = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
	prefab::CSoundSource* m_sound = nullptr;
};
