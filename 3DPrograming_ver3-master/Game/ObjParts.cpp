//---------------------------------------------------------------------
//	階層構造の３Dオブジェクトの実装
//	ObjParts.cpp
//---------------------------------------------------------------------
#include "../pch.h"
#include "Obj3D.h"
#include "../Game.h"

#include "ObjParts.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//
//	コンストラクタ
//
ObjParts::ObjParts()
	: Obj3D()
{
}

//
//初期化関数
//
void ObjParts::Init()
{
}

//
//	初期化関数
//
void ObjParts::Start()
{
	m_world = m_initial;
}

//
//	更新関数
//
bool ObjParts::Update(float elapsedTime)
{
	m_world = Matrix::CreateFromQuaternion(m_rotaiton) * Matrix::CreateTranslation(m_position);
	return true;
}

//
//	描画関数
//
void ObjParts::Render()
{
	if (m_model != nullptr && m_game != nullptr)
	{
		m_model->Draw(m_game->GetContext(), *m_game->GetStates(), m_world, m_game->GetView(), m_game->GetProjection());
	}
}
