﻿//
// Game.h
//

#pragma once

#include "DeviceResources.h"
#include "StepTimer.h"

#include "Game\GameCamera.h"
#include "Game\Player.h"
#include "DebugCamera.h"
#include "GridFloor.h"

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game : public DX::IDeviceNotify
{
public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // IDeviceNotify
    virtual void OnDeviceLost() override;
    virtual void OnDeviceRestored() override;

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;
	//デバイスを取得
	ID3D11Device* GetDevice(){return m_deviceResources->GetD3DDevice();}

	//デバイスコンテキストを取得する関数
	ID3D11DeviceContext* GetContext(){return m_deviceResources->GetD3DDeviceContext();}

	//ステートを取得する関数
	DirectX::CommonStates* GetStates(){return m_states.get();}

	//ビュー行列を取得する関数
	const DirectX::SimpleMath::Matrix& GetView(){return m_view;}

	//プロジェクション行列を取得する関数
	const DirectX::SimpleMath::Matrix& GetProjection(){return m_projection;}

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();

    void CreateDeviceDependentResources();
    void CreateWindowSizeDependentResources();

    // Device resources.
    std::unique_ptr<DX::DeviceResources>    m_deviceResources;

    // Rendering loop timer.
    DX::StepTimer                           m_timer;

	// キーボード
	std::unique_ptr<DirectX::Keyboard> m_keyboard;

	// マウス
	std::unique_ptr<DirectX::Mouse> m_mouse;

	// コモンステート
	std::unique_ptr<DirectX::CommonStates> m_states;

	// スプライトバッチ
	std::unique_ptr<DirectX::SpriteBatch> m_sprites;

	// スプライトフォント
	std::unique_ptr<DirectX::SpriteFont> m_font;

	// ワールド行列
	DirectX::SimpleMath::Matrix m_world;

	// ビュー行列
	DirectX::SimpleMath::Matrix m_view;

	// 射影行列
	DirectX::SimpleMath::Matrix m_projection;

	//カメラ
	std::unique_ptr<GameCamera> m_camera;

	std::unique_ptr<DirectX::Model> m_modelPlane;
	std::unique_ptr<DirectX::Model> m_modelStage;
	//パーツモデルデータ
	std::unique_ptr<DirectX::Model> m_modelEngine;
	std::unique_ptr<DirectX::Model> m_modelCanon;
	std::unique_ptr<DirectX::Model> m_modelBody;

	Player * m_player;
};