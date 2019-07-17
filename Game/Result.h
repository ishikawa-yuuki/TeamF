#pragma once

class Game;
class Player;
class Score;
class Result : public IGameObject
{
public:
	Result();
	~Result();
	void Update();
	prefab::CSpriteRender* m_spriterender;
	prefab::CSpriteRender* m_Cspriterender = nullptr;
	prefab::CSoundSource* m_sound;
	Game* game;
	Player* m_player;
	void PostRender(CRenderContext& rc) override;
	Score* m_s;
	int m_Rscore = 0;
	CFont m_scoa;
	CFont m_kazu;
	CFont m_sougou;
	prefab::CFontRender* m_score = nullptr;	//フォントレンダラー。
};

