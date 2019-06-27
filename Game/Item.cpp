#include "stdafx.h"
#include "Item.h"
#include "Game.h"
#include "Player.h"
Item::Item()
{
	m_modelrender = NewGO<prefab::CSkinModelRender>(0);
	m_modelrender->Init(L"modelData/box.cmo");
	m_position.x = 200.0f;
	m_position.z = 700.0f;
	m_modelrender->SetPosition(m_position);
}


Item::~Item()
{
	DeleteGO(m_modelrender);
}

bool Item::Start()
{
	m_player = FindGO<Player>("Player");
	return true;
}

void Item::Update()
{

	CVector3 diff = m_player->m_position - m_position;
	if (diff.Length() < 30.0f) {
		Game* game = FindGO<Game>("Game");
		game->Nhp += 10;
		DeleteGO(this);
	}
}