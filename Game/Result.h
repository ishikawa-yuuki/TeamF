#pragma once
class Game;
class Result : public IGameObject
{
public:
	Result();
	~Result();
	void Update();
	prefab::CSpriteRender* m_spriterender;
	prefab::CSoundSource* m_sound;
	Game* game;
	void PostRender(CRenderContext& rc) override;
	int Over = false;
	int Clear = false;
	int m_score = 0;
	CFont m_scoa;
	CFont m_zikan;
	CFont m_sougou;
};

