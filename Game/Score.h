#pragma once
class Game;
class Score : public IGameObject
{
public:
	Score();
	~Score();
	bool Start();
	void Update();
	int m_score = 0;
	int gekihacount = 0;
	CFont m_sc;
	//prefab::CFontRender* m_sc = nullptr;	//�t�H���g�����_���[�B
	Game* m_game = nullptr;		
	void PostRender(CRenderContext& rc);//�Q�[���B
};

