//--------------------------------------------------------
//	プレイヤークラスの実装
//	Player.cpp
//--------------------------------------------------------

#include "../pch.h"
#include "Player.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Player::Player()
{
}

void Player::Start()
{
	MyRobot::Start();
}

bool Player::Update(float elpsedTime)
{
	Keyboard::State keyboard = Keyboard::Get().GetState();

	if (keyboard.IsKeyDown(Keyboard::Keys::W))
	{
		m_moveFlag = FORWARD;
	}
	else if (keyboard.IsKeyDown(Keyboard::Keys::A))
	{
		m_moveFlag = LEFT_TURN;
	}
	else if (keyboard.IsKeyDown(Keyboard::Keys::D))
	{
		m_moveFlag = RIGHT_TURN;
	}
	else if (keyboard.IsKeyDown(Keyboard::Keys::S))
	{
		m_moveFlag = BACKWARD;
	}
	this->Move();

	return true;
}

void Player::Render()
{
	MyRobot::Render();
}
