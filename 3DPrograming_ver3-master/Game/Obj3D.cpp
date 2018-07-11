//-----------------------------------------------
//	3Dオブジェクトの実装
//	Obj3D.cpp
//-----------------------------------------------
#include "../pch.h"
#include "../Game.h"

#include "Obj3D.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


//
//	コンストラクタ
//
Obj3D::Obj3D()
	:m_game(nullptr),m_model(nullptr),m_position(Vector3::Zero),m_rotaiton(Quaternion::Identity),m_world(Matrix::Identity),m_initial(Matrix::Identity)
{
}

//
//	初期化関数
//
void Obj3D::Init()
{
	m_world = m_initial;
	m_position = m_world.Translation();
}

//
//	初期化関数
//
void Obj3D::Start()
{
}

//
//	更新関数
//
bool Obj3D::Update(float elapsedTime)
{
	m_world = Matrix::CreateFromQuaternion(m_rotaiton) * Matrix::CreateTranslation(m_position);
	return true;
}

//
//	描画関数
//
void Obj3D::Render()
{
	if (m_model != nullptr && m_game != nullptr)
	{
		m_model->Draw(m_game->GetContext(), *m_game->GetStates(), m_world, m_game->GetView(), m_game->GetProjection());
	}
}
