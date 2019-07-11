#pragma once
class Bullet :public IGameObject
{
public:
	Bullet();
	~Bullet();
	bool Start();
	void Update();
	void Move();

	prefab::CSkinModelRender*m_skinrender;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_movespeed = CVector3::Zero;
	CVector3 cameraForward = MainCamera().GetForward();
	CVector3 cameraRight = MainCamera().GetRight();
	int m_timer = 0;
};

