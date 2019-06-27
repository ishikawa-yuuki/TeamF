#include "stdafx.h"
#include "PowerItem.h"
#include "Player.h"
#include "Game.h"
#include "Boss.h"
PowerItem::PowerItem()
{
	m_modelrender = NewGO<prefab::CSkinModelRender>(0);
	m_modelrender->Init(L"modelData/Tama.cmo");
	m_position.x = -200.0f;
	m_position.z = 700.0f;
	m_modelrender->SetPosition(m_position);
}

PowerItem::~PowerItem()
{
	DeleteGO(m_modelrender);
}

bool PowerItem::Start()
{
	m_player = FindGO<Player>("Player");
	return true;
}

void PowerItem::Update()
{
	CVector3 diff = m_player->m_position - m_position;
	if (diff.Length() < 30.0f)
	{
		Boss* boss = FindGO<Boss>("Boss");
		boss->BossHP -= 10;
		DeleteGO(this);
	}
}