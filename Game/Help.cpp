#include "stdafx.h"
#include "Help.h"
#include "Title.h"

Help::Help()
{
	m_spriterender = NewGO < prefab::CSpriteRender>(0);
	m_spriterender->Init(L"sprite/sousa.dds", 1280.0f, 720.0f);
}

Help::~Help()
{
	DeleteGO(m_spriterender);
}
void Help::Update()
{
	if (Pad(0).IsPress(enButtonSelect) == true)
	{
		NewGO<Title>(0);
		DeleteGO(this);
	}
}