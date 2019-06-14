#pragma once
class Enemy;
class Player : public IGameObject
{
public:
	Player();
	~Player();
	bool Start();
	void Update() override;
	prefab::CSkinModelRender* m_skinModelRender = nullptr;		//スキンモデルレンダラー。
	CCharacterController m_characon;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_movespeed = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
};

