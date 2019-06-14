#pragma once
class BackGround : public IGameObject
{
public:
	BackGround();
	~BackGround();
	bool Start();
	prefab::CSkinModelRender*m_skinModelRender;
};

