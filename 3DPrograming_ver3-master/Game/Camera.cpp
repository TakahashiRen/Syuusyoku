//-------------------------------------------------------------
//	カメラクラスの実装
//	Camera.cpp
//-------------------------------------------------------------
#include "pch.h"
#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

const float Camera::CAMERA_DISTANCE = 5.0f;
//
//	コンストラクタ
//
Camera::Camera()
{
	m_scX = 0;
	m_scY = 0;
}

//
//	コンストラクタ
//	スクリーンのサイズを設定
//
Camera::Camera(int windowWidth, int windowHeight)
	: m_eyePos(Vector3::Zero), m_refPos(Vector3::Zero), m_upVec(Vector3(0.0f, 1.0f, 0.0f))
{
	m_scX = windowWidth;
	m_scY = windowHeight;
}

//
//	デストラクタ
//	
Camera::~Camera()
{
}

//
//	初期化関数
//
void Camera::Init(DirectX::SimpleMath::Vector3 eyepos, DirectX::SimpleMath::Vector3 refpos, DirectX::SimpleMath::Vector3 upvec)
{
	m_eyePos = eyepos;
	m_refPos = refpos;
	m_upVec = upvec;
}

//
//	更新関数
//
void Camera::Update()
{
	m_view = Matrix::CreateLookAt(m_eyePos, m_refPos, m_upVec);
}

//
//	視点設定関数
//
void Camera::SetEyepos(DirectX::SimpleMath::Vector3 eyepos)
{
	m_eyePos = eyepos;
}

//
//	参照点設定関数
//
void Camera::SetRefpos(DirectX::SimpleMath::Vector3 refpos)
{
	m_refPos = refpos;
}

//
//	ウィンドウサイズの設定
//
void Camera::SetWindowSize(int width, int height)
{
	m_scX = width;
	m_scY = height;
}

//
//	視点取得関数
//
DirectX::SimpleMath::Vector3 Camera::GetEyepos()
{
	return m_eyePos;
}

//
//	参照点取得関数
//
DirectX::SimpleMath::Vector3 Camera::GetRefpos()
{
	return m_refPos;
}

//
//	ビュー行列取得関数
//
DirectX::SimpleMath::Matrix Camera::GetViewMatrix()
{
	return m_view;
}
