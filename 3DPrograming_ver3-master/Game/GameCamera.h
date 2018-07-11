//--------------------------------------------------------
//	ゲーム関係のカメラ
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
	//コンストラクタ
	GameCamera();
	GameCamera(int windowWidth, int windowHeight);

	
	//タイトル画面のカメラ
	void TitleCamera();
	//上空カメラ
	void DebugCamera();
	//ゲーム中のカメラ
	void PlayCamera();
	//状態を変える
	void ChangeState(STATE state) { m_state = state; }
};
