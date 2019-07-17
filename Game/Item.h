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
	CVector3 m_position = CVector3::Zero;
	CVector3 m_Scale = CVector3::One;
	prefab::CSoundSource* m_sound;
};
