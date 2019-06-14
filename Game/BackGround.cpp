#include "stdafx.h"
#include "Player.h"
#include "Kamikire.h"
#include "BackGround.h"


BackGround::BackGround()
{

}


BackGround::~BackGround()
{
	DeleteGO(m_skinModelRender);
}

bool BackGround::Start()
{
	return true;
}