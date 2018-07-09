//------------------------------------------------------------
//	カメラクラスの定義
//	Camera.h
//------------------------------------------------------------
#pragma once
#include <SimpleMath.h>

class Camera
{
//クラス変数
public:
	// カメラの距離
	static const float CAMERA_DISTANCE;
private:
	//視点
	DirectX::SimpleMath::Vector3 m_eyePos;
	//参照点
	DirectX::SimpleMath::Vector3 m_refPos;
	//上方向ベクトル
	DirectX::SimpleMath::Vector3 m_upVec;
	//生成されたビュー行列
	DirectX::SimpleMath::Matrix m_view;
	//ウィンドウのサイズ
	int m_scX, m_scY;

//クラス関数
public:
	//コンストラクタ
	Camera();
	Camera(int windowWidth, int windowHeight);
	//デストラクタ
	~Camera();

	//初期化関数
	void Init();
	void Init(DirectX::SimpleMath::Vector3 eyepos, DirectX::SimpleMath::Vector3 refpos, DirectX::SimpleMath::Vector3 upvec);
	//更新関数
	void Update();

	//設定関数
	void SetEyepos(DirectX::SimpleMath::Vector3 eyepos);
	void SetRefpos(DirectX::SimpleMath::Vector3 refpos);
	void SetWindowSize(int width, int height);
	//取得関数
	DirectX::SimpleMath::Vector3 GetEyepos();
	DirectX::SimpleMath::Vector3 GetRefpos();
	DirectX::SimpleMath::Matrix GetViewMatrix();
private:

};
