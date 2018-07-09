//------------------------------------------------------------
//	�J�����N���X�̒�`
//	Camera.h
//------------------------------------------------------------
#pragma once
#include <SimpleMath.h>

class Camera
{
//�N���X�ϐ�
public:
	// �J�����̋���
	static const float CAMERA_DISTANCE;
private:
	//���_
	DirectX::SimpleMath::Vector3 m_eyePos;
	//�Q�Ɠ_
	DirectX::SimpleMath::Vector3 m_refPos;
	//������x�N�g��
	DirectX::SimpleMath::Vector3 m_upVec;
	//�������ꂽ�r���[�s��
	DirectX::SimpleMath::Matrix m_view;
	//�E�B���h�E�̃T�C�Y
	int m_scX, m_scY;

//�N���X�֐�
public:
	//�R���X�g���N�^
	Camera();
	Camera(int windowWidth, int windowHeight);
	//�f�X�g���N�^
	~Camera();

	//�������֐�
	void Init();
	void Init(DirectX::SimpleMath::Vector3 eyepos, DirectX::SimpleMath::Vector3 refpos, DirectX::SimpleMath::Vector3 upvec);
	//�X�V�֐�
	void Update();

	//�ݒ�֐�
	void SetEyepos(DirectX::SimpleMath::Vector3 eyepos);
	void SetRefpos(DirectX::SimpleMath::Vector3 refpos);
	void SetWindowSize(int width, int height);
	//�擾�֐�
	DirectX::SimpleMath::Vector3 GetEyepos();
	DirectX::SimpleMath::Vector3 GetRefpos();
	DirectX::SimpleMath::Matrix GetViewMatrix();
private:

};
