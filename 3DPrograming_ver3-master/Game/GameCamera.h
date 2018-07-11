//--------------------------------------------------------
//	�Q�[���֌W�̃J����
//	GameCamera.h
//--------------------------------------------------------
#pragma once
#include "Camera.h"

class GameCamera :public Camera
{
public:
	enum STATE{DEBUG,TITLE,GAME};
private:
	STATE m_state;
public:
	//�R���X�g���N�^
	GameCamera();
	GameCamera(int windowWidth, int windowHeight);

	
	//�^�C�g����ʂ̃J����
	void TitleCamera();
	//���J����
	void DebugCamera();
	//�Q�[�����̃J����
	void PlayCamera();
	//��Ԃ�ς���
	void ChangeState(STATE state) { m_state = state; }
};
