#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "Help.h"

const static int Game_Y = -10.0f;   //�Q�[��������y�̈ʒu
const static int Config_Y = -150.0f; //�ݒ蕶����y�̈ʒu

typedef enum {
	Menu_Game,     //�Q�[��
	Menu_config,   //�ݒ�
	Menu_Num,      //���ڂ̐�
}Menu;

static int NowSelect = Menu_Game;

Title::Title()
{
	
	m_spriterender = NewGO < prefab::CSpriteRender>(0);
	m_spriterender->Init(L"sprite/Titlesora.dds", 1280.0f, 720.0f);
	m_select.SetShadowParam(true, 2.0f, { 0.4f, 0.4f, 0.4f, 1.0f });
}

Title::~Title()
{
	DeleteGO(m_spriterender);
	
}

bool Title::Start()
{
	m_sound = NewGO<prefab::CSoundSource>(0);
	m_sound->Init(L"sound/loop2.wav");
	m_sound->Play(true);
	
	
	return true;
}

void Title::Update()
{
	

	/*if (Pad(0).IsPress(enButtonA) == true) {
		DeleteGO(m_sound);
		DeleteGO(this);
		NewGO<Game>(0, "Game");
	}
	if (Pad(0).IsPress(enButtonB) == true)
	{
		DeleteGO(this);
		NewGO<Help>(0);
	}*/
	

	if (Pad(0).IsTrigger(enButtonDown) == true) {//���L�[��������Ă�����I����Ԃ��������
		NowSelect = (NowSelect + 1) % Menu_Num;
		
	}
	if (Pad(0).IsTrigger(enButtonUp) == true){//��L�[��������Ă�����I����Ԃ���グ�� 
		NowSelect = (NowSelect + (Menu_Num - 1)) % Menu_Num; 

	}
	if (Pad(0).IsPress(enButtonA) == true) {//�G���^�[�L�[��������Ă�����
		switch (NowSelect)                  //���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
		{
		case Menu_Game://�Q�[���I�𒆂Ȃ�
			DeleteGO(m_sound);
			DeleteGO(this);
			NewGO<Game>(0, "Game");//�Q�[����ʂ�
			break;
		case Menu_config://�ݒ��ʒ��Ȃ�
			DeleteGO(m_sound);
			DeleteGO(this);  
			NewGO<Help>(0);      //�ݒ��ʂ�
			break;
		}
	}
	
}
void Title::PostRender(CRenderContext& rc)
{

	m_game.Begin(rc);
	const wchar_t* Start =
		L"�Q�[���X�^�[�g\n";
	m_select.Draw(
		Start,
		{ -20.0f, -10.0f },
		CVector4::White,
		0.0f,
		2.0f
	); m_game.End(rc);
	
	m_config.Begin(rc);
	const wchar_t* Config =
		L"�w���v\n";
	m_config.Draw(
		Config,
		{ -50.0f, -150.0f },
		CVector4::White,
		0.0f,
		2.0f
	);
	m_config.End(rc);

	m_select.Begin(rc);
	const wchar_t* Sirusi =
		L">\n";
	m_select.Draw(Sirusi,
		{ -360.0f, -10.0f },
		CVector4::Black,
		0.0f,
		1.5f
	);
	m_select.End(rc);
	
	int y = 0;
	switch (NowSelect) {//���݂̑I����Ԃɏ]���ď����𕪊�
	case Menu_Game://�Q�[���I�𒆂Ȃ�
		y = Game_Y;    //�Q�[���̍��W���i�[
		break;
	case Menu_config://�ݒ�I�𒆂Ȃ�
		y = Config_Y;    //�ݒ�̍��W���i�[
		break;
	}

}