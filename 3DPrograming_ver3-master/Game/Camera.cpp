//-------------------------------------------------------------
//	�J�����N���X�̎���
//	Camera.cpp
//-------------------------------------------------------------
#include "pch.h"
#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

const float Camera::CAMERA_DISTANCE = 5.0f;
//
//	�R���X�g���N�^
//
Camera::Camera()
{
	m_scX = 0;
	m_scY = 0;
}

//
//	�R���X�g���N�^
//	�X�N���[���̃T�C�Y��ݒ�
//
Camera::Camera(int windowWidth, int windowHeight)
	: m_eyePos(Vector3::Zero), m_refPos(Vector3::Zero), m_upVec(Vector3(0.0f, 1.0f, 0.0f))
{
	m_scX = windowWidth;
	m_scY = windowHeight;
}

//
//	�f�X�g���N�^
//	
Camera::~Camera()
{
}

//
//	�������֐�
//
void Camera::Init(DirectX::SimpleMath::Vector3 eyepos, DirectX::SimpleMath::Vector3 refpos, DirectX::SimpleMath::Vector3 upvec)
{
	m_eyePos = eyepos;
	m_refPos = refpos;
	m_upVec = upvec;
}

//
//	�X�V�֐�
//
void Camera::Update()
{
	m_view = Matrix::CreateLookAt(m_eyePos, m_refPos, m_upVec);
}

//
//	���_�ݒ�֐�
//
void Camera::SetEyepos(DirectX::SimpleMath::Vector3 eyepos)
{
	m_eyePos = eyepos;
}

//
//	�Q�Ɠ_�ݒ�֐�
//
void Camera::SetRefpos(DirectX::SimpleMath::Vector3 refpos)
{
	m_refPos = refpos;
}

//
//	�E�B���h�E�T�C�Y�̐ݒ�
//
void Camera::SetWindowSize(int width, int height)
{
	m_scX = width;
	m_scY = height;
}

//
//	���_�擾�֐�
//
DirectX::SimpleMath::Vector3 Camera::GetEyepos()
{
	return m_eyePos;
}

//
//	�Q�Ɠ_�擾�֐�
//
DirectX::SimpleMath::Vector3 Camera::GetRefpos()
{
	return m_refPos;
}

//
//	�r���[�s��擾�֐�
//
DirectX::SimpleMath::Matrix Camera::GetViewMatrix()
{
	return m_view;
}
