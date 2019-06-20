#pragma once
class Title : public IGameObject
{
public:
	Title();
	~Title();
	bool Start();
	void Update();
	prefab::CSpriteRender* m_spriterender;
	prefab::CSoundSource* m_sound;
	int m_selectNo = 0;
	CFont m_select;
	void PostRender(CRenderContext& rc) override;
};

