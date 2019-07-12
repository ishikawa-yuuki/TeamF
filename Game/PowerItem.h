#pragma once
#include "Player.h"
class PowerItem : public IGameObject
{
	public:
		PowerItem();
		~PowerItem();
		bool Start();
		void Update();
		Player* m_player;
		int powcount = 0;
		prefab::CSkinModelRender* m_modelrender = nullptr;
		CVector3 m_position = CVector3::Zero;
		CVector3 m_Scale = CVector3::One;
};

