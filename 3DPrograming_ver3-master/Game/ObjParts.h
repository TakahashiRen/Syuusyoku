//------------------------------------------------------------------------
//	階層構造の３Dオブジェクトのクラス
//	ObjParts.h
//------------------------------------------------------------------------
#pragma once
#include <vector>

class Obj3D;

class ObjParts
{
//クラス変数
protected:
	//オブジェクトデータ
	Obj3D* m_obj;
	//子へのポインタ
	std::vector<ObjParts*> m_child;

//クラス関数
public:
	//コンストラクタ
	ObjParts();
	//デストラクタ
	~ObjParts();

	//各パーツの初期位置行列を親の座標系に変換する関数
	void SetupInitMatrix(ObjParts* parts, DirectX::SimpleMath::Matrix* parent);
	//各パーツのワールド行列を更新する関数
	void UpdateMatrix(ObjParts* parts, DirectX::SimpleMath::Matrix* parent);

	//設定関数
	void SetObj(Obj3D* obj) { m_obj = obj; }
	void SetChild(ObjParts* child) { m_child.push_back(child); }

private:

};