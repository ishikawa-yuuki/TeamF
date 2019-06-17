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

	CVector3 toCameraPosold = m_toCameraPos;

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
		m_toCameraPos = toCameraPosold;
	}

	CVector3 pos = target + m_toCameraPos;

	MainCamera().SetTarget(target);
	MainCamera().SetPosition(pos);

	MainCamera().Update();
}
