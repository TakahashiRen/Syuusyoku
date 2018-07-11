//---------------------------------------------------------
//	ロボットクラスのヘッダファイル
//	MyRobot.h
//---------------------------------------------------------
#pragma once
#include "ObjParts.h"

class MyRobot
{
public:
	//ロボットのパーツID
	enum PARTS_ID { BODY, ENGINE, CANON, PARTS_CNT };

	//移動フラグ
	enum MOVE
	{
		STOP,		// 停止
		FORWARD,	// 前進
		BACKWARD,	// 後進
		RIGHT_TURN,	// 右旋回
		LEFT_TURN,	// 左旋回
	};
protected:
	Game* m_game;

	//ロボットの位置
	DirectX::SimpleMath::Vector3 m_position;
	//ロボットの向いている方向
	float m_direction;
	//回転
	DirectX::SimpleMath::Quaternion m_rotation;
	//ワールド行列
	DirectX::SimpleMath::Matrix m_world;
	//モデルパーツの情報
	ObjParts m_parts[PARTS_CNT];
	//移動フラグ
	MOVE m_moveFlag;

public:
	MyRobot();

	virtual void Init(DirectX::SimpleMath::Vector3 pos, float dir) { m_position = pos; m_direction = dir; }
	virtual void Start();
	virtual bool Update(float elpsedTime);
	virtual void Render();

	void Move();
	void Rotate();

	void SetPartsModel(DirectX::Model* model, PARTS_ID id) { m_parts[id].SetModel(model); }
	void SetGame(Game* game) { m_game = game; }
};
