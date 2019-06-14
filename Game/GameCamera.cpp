#include "stdafx.h"
#include "GameCamera.h"
#include "Player.h"


GameCamera::GameCamera()
{
}


GameCamera::~GameCamera()
{
}

bool GameCamera::Start()
{
	m_toCameraPos.Set(0.0f, 100.0f, 300.0f);
	m_player = FindGO<Player>("Player");
	MainCamera().SetNear(10.0f);
	MainCamera().SetFar(10000.0f);

	m_springCamera.Init(
		MainCamera(),
		1000.0f,
		true,
		5.0f
	);
	return true;
}

void GameCamera::Update()
{
	CVector3 target = m_player->m_position;
	target.x += 30.0f;
	target.y += 50.0f;

	CVector3 toCameraPosOld = m_toCameraPos;
	float x = Pad(0).GetRStickXF();
	float y = Pad(0).GetRStickYF();
	CQuaternion qRot;
	qRot.SetRotationDeg(CVector3::AxisY, 2.0f * x);
	qRot.Multiply(m_toCameraPos);
	CVector3 axisX;
	axisX.Cross(CVector3::AxisY, m_toCameraPos);
	axisX.Normalize();
	qRot.SetRotationDeg(axisX, 2.0f * y);
	qRot.Multiply(m_toCameraPos);

	CVector3 toPosDir = m_toCameraPos;
	toPosDir.Normalize();
	if (toPosDir.y < -0.5f) {
		m_toCameraPos = toCameraPosOld;
	}
	else if (toPosDir.y > 0.8f) {
		m_toCameraPos = toCameraPosOld;
	}

	CVector3 pos = target + m_toCameraPos;
	m_springCamera.SetTarget(target);
	m_springCamera.SetPosition(pos);

	m_springCamera.Update();
	/*CVector3 position = target + toPos;
	MainCamera().SetTarget(target);
	MainCamera().SetPosition(position);
	MainCamera().Update();*/
}