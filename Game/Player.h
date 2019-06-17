#pragma once
class Player :public IGameObject
{
public:
	Player();
	~Player();
	void Update();
	void Move();
	int m_timer = 0;
	prefab::CSkinModelRender* m_skinmodelrender = nullptr;
	CCharacterController m_chracon;
	prefab::CSpriteRender* m_hpber = nullptr;
	prefab::CSpriteRender* m_hp = nullptr;
	prefab::CSoundSource* m_sound;
	prefab::CSpriteRender* m_sprite;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_position = CVector3::Zero;
	CVector3 m_movespeed = CVector3::Zero;
};
