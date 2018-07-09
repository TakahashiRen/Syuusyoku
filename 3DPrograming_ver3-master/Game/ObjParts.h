//------------------------------------------------------------------------
//	�K�w�\���̂RD�I�u�W�F�N�g�̃N���X
//	ObjParts.h
//------------------------------------------------------------------------
#pragma once
#include <vector>

class Obj3D;

class ObjParts
{
//�N���X�ϐ�
protected:
	//�I�u�W�F�N�g�f�[�^
	Obj3D* m_obj;
	//�q�ւ̃|�C���^
	std::vector<ObjParts*> m_child;

//�N���X�֐�
public:
	//�R���X�g���N�^
	ObjParts();
	//�f�X�g���N�^
	~ObjParts();

	//�e�p�[�c�̏����ʒu�s���e�̍��W�n�ɕϊ�����֐�
	void SetupInitMatrix(ObjParts* parts, DirectX::SimpleMath::Matrix* parent);
	//�e�p�[�c�̃��[���h�s����X�V����֐�
	void UpdateMatrix(ObjParts* parts, DirectX::SimpleMath::Matrix* parent);

	//�ݒ�֐�
	void SetObj(Obj3D* obj) { m_obj = obj; }
	void SetChild(ObjParts* child) { m_child.push_back(child); }

private:

};