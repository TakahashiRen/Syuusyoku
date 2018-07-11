//---------------------------------------------------------
//	���{�b�g�N���X�̃w�b�_�t�@�C��
//	MyRobot.h
//---------------------------------------------------------
#pragma once
#include "ObjParts.h"

class MyRobot
{
public:
	//���{�b�g�̃p�[�cID
	enum PARTS_ID { BODY, ENGINE, CANON, PARTS_CNT };

	//�ړ��t���O
	enum MOVE
	{
		STOP,		// ��~
		FORWARD,	// �O�i
		BACKWARD,	// ��i
		RIGHT_TURN,	// �E����
		LEFT_TURN,	// ������
	};
protected:
	Game* m_game;

	//���{�b�g�̈ʒu
	DirectX::SimpleMath::Vector3 m_position;
	//���{�b�g�̌����Ă������
	float m_direction;
	//��]
	DirectX::SimpleMath::Quaternion m_rotation;
	//���[���h�s��
	DirectX::SimpleMath::Matrix m_world;
	//���f���p�[�c�̏��
	ObjParts m_parts[PARTS_CNT];
	//�ړ��t���O
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
