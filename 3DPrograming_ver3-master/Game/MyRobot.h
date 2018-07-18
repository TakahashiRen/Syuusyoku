//---------------------------------------------------------
//	���{�b�g�N���X�̃w�b�_�t�@�C��
//	MyRobot.h
//---------------------------------------------------------
#pragma once
#include "ObjParts.h"

class MyRobot
{
//----------------------------------------------------------
//	�N���X�ϐ�
//----------------------------------------------------------
public:
	//���{�b�g�̃p�[�cID
	enum PARTS_ID { BODY, ENGINE, CANON, PARTS_CNT };

	//�ړ��t���O
	enum MOVE
	{
		STOP		= 0x0000,		// ��~
		FORWARD		= 0x0001,		// �O�i
		BACKWARD	= 0x0002,		// ��i
		RIGHT_TURN	= 0x0004,		// �E����
		LEFT_TURN	= 0x0008,		// ������
	};
	//�����̉�]��
	static const float ADD_DIR_ANGLE;
	//���[����]��
	static const float ADD_ROLL_ANGLE;
	//�����x
	static const float ADD_SPEED;
	//��]�̍ő�p�x
	static const float MAX_ROLL_ANGLE;
	//�ő呬�x
	static const float MAX_SPEED;

protected:
	Game* m_game;

	//���{�b�g�̈ʒu
	DirectX::SimpleMath::Vector3 m_position;
	//���{�b�g�̌����Ă������
	float m_direction;
	//���[���p�x
	float m_rollAngle;
	//���x
	float m_speed;

	//�ړ��t���O
	MOVE m_moveFlag;

	//���[���h�s��
	DirectX::SimpleMath::Matrix m_world;
	//���f���p�[�c�̏��
	ObjParts m_parts[PARTS_CNT];

//----------------------------------------------------------
//	�N���X�֐�
//----------------------------------------------------------
public:
	//�R���X�g���N�^
	MyRobot();

	//�ʒu�A�����̏�����
	virtual void Init(DirectX::SimpleMath::Vector3 pos, float dir) { m_position = pos; m_direction = dir; }
	//�J�n����
	virtual void Start();
	//�X�V����
	virtual bool Update(float elpsedTime);
	//�`�揈��
	virtual void Render();

	//�ړ�����
	void Move();

	//���{�b�g�̃p�[�c�̃��f�����Z�b�g����
	void SetPartsModel(DirectX::Model* model, PARTS_ID id) { m_parts[id].SetModel(model); }
	//�e��f�[�^�����Q�[���f�[�^���󂯎��
	void SetGame(Game* game) { m_game = game; }

	//�ʒu�̎擾
	DirectX::SimpleMath::Vector3 GetPosition() { return m_position; }
	//�����Ă�������̎擾
	float GetDir() { return m_direction; }
};
