//------------------------------------------------------------------------
//	階層構造の３Dオブジェクトのクラス
//	ObjParts.h
//------------------------------------------------------------------------
#pragma once
#include <vector>
#include "Obj3D.h"

class ObjParts : public Obj3D
{
private:
	// 変換行列
	DirectX::SimpleMath::Matrix m_transform;
	// 子へのポインタ
	ObjParts* m_child = nullptr;
	// 兄弟へのポインタ
	ObjParts* m_sibling = nullptr;
public:
	ObjParts();

	virtual void Init();

	virtual void Start();

	virtual bool Update(float elapsedTime);

	virtual void Render();

	//子、兄弟の設定
	void SetChild(ObjParts* child) { m_child = child; }
	void SetSibling(ObjParts* sib) { m_sibling = sib; }

	// 各パーツの初期位置行列を親の座標系に変換する関数
	static void SetupMatrix(ObjParts* parts, DirectX::SimpleMath::Matrix* offset)
	{
		if (parts->m_child) SetupMatrix(parts->m_child, &parts->m_initial.Invert());
		if (parts->m_sibling) SetupMatrix(parts->m_sibling, offset);
		if (offset) parts->m_initial *= *offset;
	}
	// 各パーツのワールド行列を更新する関数
	static void UpdateMatrix(ObjParts* parts, DirectX::SimpleMath::Matrix* parent)
	{
		parts->m_world = parts->m_transform * parts->m_initial;
		parts->m_world *= *parent;
		if (parts->m_child) UpdateMatrix(parts->m_child, &parts->m_world);
		if (parts->m_sibling) UpdateMatrix(parts->m_sibling, parent);
	}
};