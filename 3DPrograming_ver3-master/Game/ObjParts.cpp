//---------------------------------------------------------------------
//	�K�w�\���̂RD�I�u�W�F�N�g�̎���
//	ObjParts.cpp
//---------------------------------------------------------------------
#include "../pch.h"
#include "Obj3D.h"
#include "ObjParts.h"

//
//	�R���X�g���N�^	
//
ObjParts::ObjParts()
	: m_obj(nullptr)
{
	m_child.resize(5);
}

//
//	�f�X�g���N�^
//
ObjParts::~ObjParts()
{
}

//
//�e�p�[�c�̏����ʒu�s���e�̍��W�n�ɕϊ�����֐�
//
void ObjParts::SetupInitMatrix(ObjParts * parts, DirectX::SimpleMath::Matrix * parent)
{
	for (std::vector<ObjParts*>::iterator ite = m_child.begin(); ite != m_child.end(); ite++)
	{
		if (parent)
		{
			
		}
	}
}

//
//�e�p�[�c�̃��[���h�s����X�V����֐�
//
void ObjParts::UpdateMatrix(ObjParts * parts, DirectX::SimpleMath::Matrix * parent)
{
}
