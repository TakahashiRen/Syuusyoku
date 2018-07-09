//---------------------------------------------
//	�RD�I�u�W�F�N�g�̒�`
//	Obj3D.h
//---------------------------------------------
#pragma once
class Game;

class Object3d
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

public:
	Object3d();

	virtual void Start();

	virtual bool Update(float elapsedTime);

	virtual void Render();

	void SetGame(Game* game)									{ m_game = game; }
	void SetModel(DirectX::Model* model)						{ m_model = model; }
	void SetPosition(DirectX::SimpleMath::Vector3 position)		{ m_position = position; }
	void SetRotation(DirectX::SimpleMath::Quaternion rotation)	{ m_rotaiton = rotation; }

};
