//-----------------------------------------------
//	3Dオブジェクトの実装
//	Obj3D.cpp
//-----------------------------------------------
#include "pch.h"
#include "Obj3D.h"
#include "Game.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


//
//	コンストラクタ
//
Object3d::Object3d()
	:m_game(nullptr),m_model(nullptr),m_position(Vector3::Zero),m_rotaiton(Quaternion::Identity),m_world(Matrix::Identity)
{
}

//
//	初期化関数
//
void Object3d::Start()
{
}

//
//	更新関数
//
bool Object3d::Update(float elapsedTime)
{
	m_world = Matrix::CreateFromQuaternion(m_rotaiton) * Matrix::CreateTranslation(m_position);

	return true;
}

//
//	描画関数
//
void Object3d::Render()
{
	if (m_model != nullptr && m_game != nullptr)
	{
		m_model->Draw(m_game->GetContext(), *m_game->GetStates(), m_world, m_game->GetView(), m_game->GetProjection());
	}
}
