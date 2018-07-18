//---------------------------------------------------------
//	ロボットクラスのヘッダファイル
//	MyRobot.h
//---------------------------------------------------------
#pragma once
#include "ObjParts.h"

class MyRobot
{
//----------------------------------------------------------
//	クラス変数
//----------------------------------------------------------
public:
	//ロボットのパーツID
	enum PARTS_ID { BODY, ENGINE, CANON, PARTS_CNT };

	//移動フラグ
	enum MOVE
	{
		STOP		= 0x0000,		// 停止
		FORWARD		= 0x0001,		// 前進
		BACKWARD	= 0x0002,		// 後進
		RIGHT_TURN	= 0x0004,		// 右旋回
		LEFT_TURN	= 0x0008,		// 左旋回
	};
	//方向の回転量
	static const float ADD_DIR_ANGLE;
	//ロール回転量
	static const float ADD_ROLL_ANGLE;
	//加速度
	static const float ADD_SPEED;
	//回転の最大角度
	static const float MAX_ROLL_ANGLE;
	//最大速度
	static const float MAX_SPEED;

protected:
	Game* m_game;

	//ロボットの位置
	DirectX::SimpleMath::Vector3 m_position;
	//ロボットの向いている方向
	float m_direction;
	//ロール角度
	float m_rollAngle;
	//速度
	float m_speed;

	//移動フラグ
	MOVE m_moveFlag;

	//ワールド行列
	DirectX::SimpleMath::Matrix m_world;
	//モデルパーツの情報
	ObjParts m_parts[PARTS_CNT];

//----------------------------------------------------------
//	クラス関数
//----------------------------------------------------------
public:
	//コンストラクタ
	MyRobot();

	//位置、方向の初期化
	virtual void Init(DirectX::SimpleMath::Vector3 pos, float dir) { m_position = pos; m_direction = dir; }
	//開始処理
	virtual void Start();
	//更新処理
	virtual bool Update(float elpsedTime);
	//描画処理
	virtual void Render();

	//移動処理
	void Move();

	//ロボットのパーツのモデルをセットする
	void SetPartsModel(DirectX::Model* model, PARTS_ID id) { m_parts[id].SetModel(model); }
	//各種データを持つゲームデータを受け取る
	void SetGame(Game* game) { m_game = game; }

	//位置の取得
	DirectX::SimpleMath::Vector3 GetPosition() { return m_position; }
	//向いている方向の取得
	float GetDir() { return m_direction; }
};
