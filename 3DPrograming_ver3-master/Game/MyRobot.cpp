//-----------------------------------------------
//	ロボットクラスの実装
//	MyRobot.cpp
//-----------------------------------------------
#include "../pch.h"
#include "MyRobot.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//方向の回転量(ラジアン角)
const float MyRobot::ADD_DIR_ANGLE	= 1.0f * (3.14f / 180.0f);
//ロール回転量(ラジアン角)
const float MyRobot::ADD_ROLL_ANGLE	= 2.0f * (3.14f / 180.0f);
//回転の最大角度(ラジアン角)
const float MyRobot::MAX_ROLL_ANGLE	= 15.0f * (3.14f / 180.0f);
//加速度
const float MyRobot::ADD_SPEED = 0.02f;
//最大速度
const float MyRobot::MAX_SPEED = 0.1f;

//
//	コンストラクタ
//
MyRobot::MyRobot()
	:m_world(Matrix::Identity),m_position(Vector3::Zero),m_direction(0.0f),m_moveFlag(STOP),m_rollAngle(0.0f),m_speed(0.0f)
{
}

//
//	開始処理
//
void MyRobot::Start()
{
	m_world = Matrix::CreateRotationY(m_direction) * Matrix::CreateTranslation(m_position);

	//パーツの初期位置を設定
	m_parts[BODY].SetInitPos(Matrix::CreateTranslation(0.0f, 0.5f, 0.0f));
	m_parts[CANON].SetInitPos(Matrix::CreateTranslation(0.0f, 0.35f, 0.0f));
	m_parts[ENGINE].SetInitPos(Matrix::CreateTranslation(0.0f, 0.75f, 0.0f));

	//パーツの親子関係を設定
	m_parts[BODY].SetChild(&m_parts[CANON]);
	m_parts[CANON].SetSibling(&m_parts[ENGINE]);

	//各種パーツの初期設定
	ObjParts::SetupMatrix(m_parts, &m_world);
	for (int i = 0; i < PARTS_CNT; i++)
	{
		m_parts[i].SetGame(m_game);
		m_parts[i].Start();
	}
}

//
//	更新処理
//
bool MyRobot::Update(float elpsedTime)
{
	this->Move();

	return true;
}

//
//	描画処理
//
void MyRobot::Render()
{
	//各種パーツの描画
	for (int i = 0; i < PARTS_CNT; i++)
	{
		m_parts[i].Render();
	}
}

//移動処理
void MyRobot::Move()
{
	// 速度
	float v = 0;

	switch (m_moveFlag)
	{
		//前進
		case FORWARD:
		{	
			m_speed += ADD_SPEED;
			if (m_speed > MAX_SPEED)m_speed = MAX_SPEED;
			break;
		}
		//後進
		case BACK:
		{		
			m_speed += -ADD_SPEED;
			if (m_speed <= -MAX_SPEED)m_speed = -MAX_SPEED;
			break;
		}
		// 右旋回
		case RIGHT_TURN:
		{
			m_rollAngle += ADD_ROLL_ANGLE;
			if (m_rollAngle >= MAX_ROLL_ANGLE)
			{
				m_rollAngle = MAX_ROLL_ANGLE;
				m_direction += -ADD_DIR_ANGLE;
			}
			break;
		}
		// 左旋回
		case LEFT_TURN:
		{
			m_rollAngle += -ADD_ROLL_ANGLE;
			if (m_rollAngle <= -MAX_ROLL_ANGLE)
			{
				m_rollAngle = -MAX_ROLL_ANGLE;
				m_direction += ADD_DIR_ANGLE;
			}
			break;
		}
		default:
			break;
	}
	m_position.x += sinf(m_direction) * m_speed;
	m_position.z += cosf(m_direction) * m_speed;

	//ワールド行列の更新
	m_world = Matrix::CreateRotationZ(m_rollAngle) * Matrix::CreateRotationY(m_direction) * Matrix::CreateTranslation(m_position);

	//各パーツのワールド行列の更新
	ObjParts::UpdateMatrix(m_parts, &m_world);

}