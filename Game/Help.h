#pragma once
class Help : public IGameObject
{
public:
	Help();
	~Help();
	void Update();
	prefab::CSpriteRender* m_spriterender;
	prefab::CSoundSource* m_sound;
	void PostRender(CRenderContext& rc) override;
	CFont m_sousa;
};