#pragma once
class Result : public IGameObject
{
public:
	Result();
	~Result();
	void Update();
	prefab::CSpriteRender* m_spriterender;
	prefab::CSoundSource* m_sound;
	
};

