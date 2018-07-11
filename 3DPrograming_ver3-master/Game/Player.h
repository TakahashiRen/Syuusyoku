//--------------------------------------------------------
//	プレイヤークラスのヘッダファイル
//	Player.h
//--------------------------------------------------------
#pragma once
#include "../pch.h"
#include "MyRobot.h"

class Player : public MyRobot
{
public:
	Player();

	void Init(DirectX::SimpleMath::Vector3 pos, float dir) { m_position = pos; m_direction = dir; }
	void Start()override;
	bool Update(float elpsedTime)override;
	void Render()override;

};