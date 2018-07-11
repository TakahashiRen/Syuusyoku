//---------------------------------------------------------------------
//	�K�w�\���̂RD�I�u�W�F�N�g�̎���
//	ObjParts.cpp
//---------------------------------------------------------------------
#include "../pch.h"
#include "Obj3D.h"
#include "../Game.h"

#include "ObjParts.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//
//	�R���X�g���N�^
//
ObjParts::ObjParts()
	: Obj3D()
{
}

//
//�������֐�
//
void ObjParts::Init()
{
}

//
//	�������֐�
//
void ObjParts::Start()
{
	m_world = m_initial;
}

//
//	�X�V�֐�
//
bool ObjParts::Update(float elapsedTime)
{
	m_world = Matrix::CreateFromQuaternion(m_rotaiton) * Matrix::CreateTranslation(m_position);
	return true;
}

//
//	�`��֐�
//
void ObjParts::Render()
{
	if (m_model != nullptr && m_game != nullptr)
	{
		m_model->Draw(m_game->GetContext(), *m_game->GetStates(), m_world, m_game->GetView(), m_game->GetProjection());
	}
}
