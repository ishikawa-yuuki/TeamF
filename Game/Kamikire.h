#pragma once
class Player;
class Kamikire : public IGameObject
{
public:
	Kamikire();
	~Kamikire();
	bool Start();
	void Update();
	CVector3 m_position = CVector3::Zero;
	CQuaternion m_rotation = CQuaternion::Identity;
	CVector3 m_scale = CVector3::One;
	prefab::CSkinModelRender* m_skinmodelRender = nullptr;
	Player* m_player;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;
};

