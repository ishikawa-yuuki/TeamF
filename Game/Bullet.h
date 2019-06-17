#pragma once
class Bullet :public IGameObject
{
public:
	Bullet();
	~Bullet();
	bool Start();
	void Update();

	prefab::CSkinModelRender*m_skinrender;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_movespeed = CVector3::Zero;
	int m_timer = 0;
};

