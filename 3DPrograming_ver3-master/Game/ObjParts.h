//------------------------------------------------------------------------
//	�K�w�\���̂RD�I�u�W�F�N�g�̃N���X
//	ObjParts.h
//------------------------------------------------------------------------
#pragma once
#include <vector>
#include "Obj3D.h"

class ObjParts : public Obj3D
{
private:
	// �ϊ��s��
	DirectX::SimpleMath::Matrix m_transform;
	// �q�ւ̃|�C���^
	ObjParts* m_child = nullptr;
	// �Z��ւ̃|�C���^
	ObjParts* m_sibling = nullptr;
public:
	ObjParts();

	virtual void Init();

	virtual void Start();

	virtual bool Update(float elapsedTime);

	virtual void Render();

	//�q�A�Z��̐ݒ�
	void SetChild(ObjParts* child) { m_child = child; }
	void SetSibling(ObjParts* sib) { m_sibling = sib; }

	// �e�p�[�c�̏����ʒu�s���e�̍��W�n�ɕϊ�����֐�
	static void SetupMatrix(ObjParts* parts, DirectX::SimpleMath::Matrix* offset)
	{
		if (parts->m_child) SetupMatrix(parts->m_child, &parts->m_initial.Invert());
		if (parts->m_sibling) SetupMatrix(parts->m_sibling, offset);
		if (offset) parts->m_initial *= *offset;
	}
	// �e�p�[�c�̃��[���h�s����X�V����֐�
	static void UpdateMatrix(ObjParts* parts, DirectX::SimpleMath::Matrix* parent)
	{
		parts->m_world = parts->m_transform * parts->m_initial;
		parts->m_world *= *parent;
		if (parts->m_child) UpdateMatrix(parts->m_child, &parts->m_world);
		if (parts->m_sibling) UpdateMatrix(parts->m_sibling, parent);
	}
};