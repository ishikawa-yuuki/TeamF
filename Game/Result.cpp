#include "stdafx.h"
#include "Result.h"
#include "Title.h"
#include "Game.h"

Result::Result()
{

	m_spriterender = NewGO< prefab::CSpriteRender>(0);
	m_spriterender->Init(L"sprite/result.dds", 1280.0f, 720.0f);
}


Result::~Result()
{
	DeleteGO(m_spriterender);
}

void Result::Update()
{
	if (Pad(0).IsPress(enButtonSelect) == true)
	{
		NewGO<Title>(0);
		DeleteGO(this);
	}  
	
	
}