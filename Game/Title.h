#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();
	bool Start() override;
	void Update() override;
	prefab::CSpriteRender* m_SpriteRender;
	prefab::CSoundSource* m_bgmSoundSource = nullptr;
};

