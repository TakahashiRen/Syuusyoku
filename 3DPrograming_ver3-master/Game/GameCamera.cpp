//--------------------------------------------------------
//	�Q�[�����̃J�����N���X�̎���
//	GameCamera.cpp
//--------------------------------------------------------
#include "../pch.h"
#include "GameCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

GameCamera::GameCamera()
{
}

GameCamera::GameCamera(int windowWidth, int windowHeight)
	: Camera(windowWidth,windowHeight),m_targetPos(Vector3::Zero),m_targetDir(0.0f)
{
}

void GameCamera::TitleCamera()
{
	Vector3 eye(5.0f, 1.0f, 0.0f);

	Matrix roty = Matrix::CreateRotationY(XMConvertToRadians(m_angle));
	m_eyePos = Vector3::Transform(eye, roty);
	m_view = Matrix::CreateLookAt(m_eyePos, m_refPos, m_upVec);
	m_angle += 0.5f;
}

void GameCamera::DebugCamera()
{
	this->SetEyepos(Vector3(0.0f, 20.0f, 0.0f));
	this->SetRefpos(Vector3(0.0f, 0.0f, 0.0f));

	m_view = Matrix::CreateLookAt(m_eyePos, m_refPos, Vector3(0.0f,0.0f,1.0f));
}

void GameCamera::PlayCamera()
{
	Vector3 eyePos, refPos;
	//�����_�̍��W�̓^�[�Q�b�g�̍��W�ɒǏ](������ɏ������炷�j
	refPos = m_targetPos + Vector3(0, 2.0f, 0.0f);
	//�^�[�Q�b�g�̍��W����J�������W�ւ̍���
	Vector3 cameraV(0.0f, 0.0f, -CAMERA_DISTANCE);

	//�J�����̎��������̋t�����ɉ�]
	Matrix rotmat = Matrix::CreateRotationY(-m_targetDir);
	cameraV = Vector3::TransformNormal(cameraV, rotmat);

	//�J�����̍��W���v�Z
	eyePos = refPos + cameraV;

	Vector3 i;

	i = (m_eyePos + (eyePos - m_eyePos)) * 0.05;

	eyePos += i;

	this->SetEyepos(eyePos);
	this->SetRefpos(refPos);

	m_view = Matrix::CreateLookAt(m_eyePos, m_refPos, Vector3::Up);
}



