#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

bool Camera::Start()
{
	m_toCameraPos.Set(0.0f, 50.0f, -200.0f);
	m_player = FindGO<Player>("Player");

	MainCamera().SetNear(1.0f);
	MainCamera().SetFar(30000.0f);
	return true;
}

void Camera::Update()
{
	CVector3 target = m_player->m_position;
	target.y += 30.0f;

	CVector3 pos = target + m_toCameraPos;

	MainCamera().SetTarget(target);
	MainCamera().SetPosition(pos);

	MainCamera().Update();
}
