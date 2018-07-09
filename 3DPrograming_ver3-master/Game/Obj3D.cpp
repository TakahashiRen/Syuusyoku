//-----------------------------------------------
//	3D�I�u�W�F�N�g�̎���
//	Obj3D.cpp
//-----------------------------------------------
#include "../pch.h"
#include "../Game.h"
#include "Obj3D.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


//
//	�R���X�g���N�^
//
Obj3D::Obj3D()
	:m_game(nullptr),m_model(nullptr),m_position(Vector3::Zero),m_rotaiton(Quaternion::Identity),m_world(Matrix::Identity),m_initialPos(Matrix::Identity)
{
}

void Obj3D::Init()
{
	m_world = m_initialPos;
	Vector3 scale;
	m_world.Decompose(scale, m_rotaiton, m_position);
}

//
//	�������֐�
//
void Obj3D::Start()
{
}

//
//	�X�V�֐�
//
bool Obj3D::Update(float elapsedTime)
{
	m_world = Matrix::CreateFromQuaternion(m_rotaiton) * Matrix::CreateTranslation(m_position);

	return true;
}

//
//	�`��֐�
//
void Obj3D::Render()
{
	if (m_model != nullptr && m_game != nullptr)
	{
		m_model->Draw(m_game->GetContext(), *m_game->GetStates(), m_world, m_game->GetView(), m_game->GetProjection());
	}
}
