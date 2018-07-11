//-----------------------------------------------
//	ロボットクラスの実装
//	MyRobot.cpp
//-----------------------------------------------
#include "../pch.h"
#include "MyRobot.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;
//
//	コンストラクタ
//
MyRobot::MyRobot()
	:m_position(Vector3::Zero),m_direction(0.0f),m_moveFlag(STOP)
{
}

//
//	開始処理
//
void MyRobot::Start()
{
	m_rotation = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), m_direction);
	m_world = Matrix::CreateFromQuaternion(m_rotation) * Matrix::CreateTranslation(m_position);

	m_parts[BODY].SetInitPos(Matrix::CreateTranslation(0.0f, 0.5f, 0.0f));
	m_parts[CANON].SetInitPos(Matrix::CreateTranslation(0.0f, 0.35f, 0.0f));
	m_parts[ENGINE].SetInitPos(Matrix::CreateTranslation(0.0f, 0.75f, 0.0f));

	m_parts[BODY].SetChild(&m_parts[CANON]);
	m_parts[CANON].SetSibling(&m_parts[ENGINE]);

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
	for (int i = 0; i < PARTS_CNT; i++)
	{
		m_parts[i].Render();
	}
}

//移動処理
void MyRobot::Move()
{
	// 速度
	Vector3 v;

	switch (m_moveFlag)
	{
	case FORWARD:		// 前進
		v.z = 0.1f;
		break;
	case BACK:			// 後進
		v.z = -0.1f;
		break;
	case RIGHT_TURN:	// 右旋回
		m_direction -= XMConvertToRadians(1.0f);
		break;
	case LEFT_TURN:		// 左旋回
		m_direction += XMConvertToRadians(1.0f);
		break;
	default:
		break;
	}
	m_rotation = Quaternion::CreateFromAxisAngle(Vector3(0.0f, 1.0f, 0.0f), m_direction);
	v = Vector3::Transform(v, m_rotation);
	m_position += v;
	m_moveFlag = STOP;
	m_world = Matrix::CreateFromQuaternion(m_rotation) * Matrix::CreateTranslation(m_position);

	ObjParts::UpdateMatrix(m_parts, &m_world);
}

//回転処理
void MyRobot::Rotate()
{
}
