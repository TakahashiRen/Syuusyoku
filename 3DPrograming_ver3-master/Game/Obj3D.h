//---------------------------------------------
//	�RD�I�u�W�F�N�g�̒�`
//	Obj3D.h
//---------------------------------------------
#pragma once
class Game;

class Obj3D
{
protected:
	Game* m_game;
	//���f���n���h��
	DirectX::Model* m_model;
	//�ʒu
	DirectX::SimpleMath::Vector3 m_position;
	//��]
	DirectX::SimpleMath::Quaternion m_rotaiton;
	//���[���h�s��
	DirectX::SimpleMath::Matrix m_world;
	//�����ʒu�s��
	DirectX::SimpleMath::Matrix m_initial;

public:
	Obj3D();

	virtual void Init();

	virtual void Start();

	virtual bool Update(float elapsedTime);

	virtual void Render();

	void SetGame(Game* game)									{ m_game = game; }
	void SetModel(DirectX::Model* model)						{ m_model = model; }
	void SetPosition(DirectX::SimpleMath::Vector3 position)		{ m_position = position; }
	void SetRotation(DirectX::SimpleMath::Quaternion rotation)	{ m_rotaiton = rotation; }
	void SetWorldMat(DirectX::SimpleMath::Matrix mat)			{ m_world = mat; }
	void SetInitPos(DirectX::SimpleMath::Matrix pos)			{ m_initial = pos; }

	DirectX::SimpleMath::Vector3 GetPosition() { return m_position; }
	DirectX::SimpleMath::Quaternion GetRotation() { return m_rotaiton; }
	DirectX::SimpleMath::Matrix GetWorldMat() { return m_world; }
	DirectX::SimpleMath::Matrix GetInitPos() { return m_initial; }

};
