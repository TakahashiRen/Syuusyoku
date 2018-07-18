//-----------------------------------------------
//	���{�b�g�N���X�̎���
//	MyRobot.cpp
//-----------------------------------------------
#include "../pch.h"
#include "MyRobot.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//�����̉�]��(���W�A���p)
const float MyRobot::ADD_DIR_ANGLE	= 1.0f * (3.14f / 180.0f);
//���[����]��(���W�A���p)
const float MyRobot::ADD_ROLL_ANGLE	= 2.0f * (3.14f / 180.0f);
//��]�̍ő�p�x(���W�A���p)
const float MyRobot::MAX_ROLL_ANGLE	= 15.0f * (3.14f / 180.0f);
//�����x
const float MyRobot::ADD_SPEED = 0.02f;
//�ő呬�x
const float MyRobot::MAX_SPEED = 0.1f;

//
//	�R���X�g���N�^
//
MyRobot::MyRobot()
	:m_world(Matrix::Identity),m_position(Vector3::Zero),m_direction(0.0f),m_moveFlag(STOP),m_rollAngle(0.0f),m_speed(0.0f)
{
}

//
//	�J�n����
//
void MyRobot::Start()
{
	m_world = Matrix::CreateRotationY(m_direction) * Matrix::CreateTranslation(m_position);

	//�p�[�c�̏����ʒu��ݒ�
	m_parts[BODY].SetInitPos(Matrix::CreateTranslation(0.0f, 0.5f, 0.0f));
	m_parts[CANON].SetInitPos(Matrix::CreateTranslation(0.0f, 0.35f, 0.0f));
	m_parts[ENGINE].SetInitPos(Matrix::CreateTranslation(0.0f, 0.75f, 0.0f));

	//�p�[�c�̐e�q�֌W��ݒ�
	m_parts[BODY].SetChild(&m_parts[CANON]);
	m_parts[CANON].SetSibling(&m_parts[ENGINE]);

	//�e��p�[�c�̏����ݒ�
	ObjParts::SetupMatrix(m_parts, &m_world);
	for (int i = 0; i < PARTS_CNT; i++)
	{
		m_parts[i].SetGame(m_game);
		m_parts[i].Start();
	}
}

//
//	�X�V����
//
bool MyRobot::Update(float elpsedTime)
{
	this->Move();

	return true;
}

//
//	�`�揈��
//
void MyRobot::Render()
{
	//�e��p�[�c�̕`��
	for (int i = 0; i < PARTS_CNT; i++)
	{
		m_parts[i].Render();
	}
}

//�ړ�����
void MyRobot::Move()
{
	// ���x
	float v = 0;

	switch (m_moveFlag)
	{
		//�O�i
		case FORWARD:
		{	
			m_speed += ADD_SPEED;
			if (m_speed > MAX_SPEED)m_speed = MAX_SPEED;
			break;
		}
		//��i
		case BACK:
		{		
			m_speed += -ADD_SPEED;
			if (m_speed <= -MAX_SPEED)m_speed = -MAX_SPEED;
			break;
		}
		// �E����
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
		// ������
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

	//���[���h�s��̍X�V
	m_world = Matrix::CreateRotationZ(m_rollAngle) * Matrix::CreateRotationY(m_direction) * Matrix::CreateTranslation(m_position);

	//�e�p�[�c�̃��[���h�s��̍X�V
	ObjParts::UpdateMatrix(m_parts, &m_world);

}