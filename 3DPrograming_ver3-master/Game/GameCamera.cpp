//--------------------------------------------------------
//	ゲーム中のカメラクラスの実装
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
	: Camera(windowWidth,windowHeight)
{
}

void GameCamera::TitleCamera()
{
	Vector3 eye(5.0f, 1.0f, 0.0f);

	Matrix roty = Matrix::CreateRotationY(XMConvertToRadians(angle));
	m_eyePos = Vector3::Transform(eye, roty);
	m_view = Matrix::CreateLookAt(m_eyePos, m_refPos, m_upVec);
	angle += 0.5f;
}

void GameCamera::DebugCamera()
{
	this->SetEyepos(Vector3(0.0f, 20.0f, 0.0f));
	this->SetRefpos(Vector3(0.0f, 0.0f, 0.0f));

	m_view = Matrix::CreateLookAt(m_eyePos, m_refPos, Vector3::Left);
}

void GameCamera::PlayCamera()
{
}
