#pragma once
class Result;
class Title : public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();
	prefab::CSpriteRender* m_spriterender;
	prefab::CSpriteRender* m_spr;
	prefab::CSoundSource* m_sound;
	CFont m_game;
	CFont m_config;
	CFont m_select;
	prefab::CFontRender* m_fontRender = nullptr;
	void PostRender(CRenderContext& rc) override;
	CVector2 m_position = CVector2::Zero;
	Result* result;
};

