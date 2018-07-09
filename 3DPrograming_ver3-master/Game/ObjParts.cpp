//---------------------------------------------------------------------
//	階層構造の３Dオブジェクトの実装
//	ObjParts.cpp
//---------------------------------------------------------------------
#include "../pch.h"
#include "Obj3D.h"
#include "ObjParts.h"

//
//	コンストラクタ	
//
ObjParts::ObjParts()
	: m_obj(nullptr)
{
	m_child.resize(5);
}

//
//	デストラクタ
//
ObjParts::~ObjParts()
{
}

//
//各パーツの初期位置行列を親の座標系に変換する関数
//
void ObjParts::SetupInitMatrix(ObjParts * parts, DirectX::SimpleMath::Matrix * parent)
{
	for (std::vector<ObjParts*>::iterator ite = m_child.begin(); ite != m_child.end(); ite++)
	{
		if (parent)
		{
			
		}
	}
}

//
//各パーツのワールド行列を更新する関数
//
void ObjParts::UpdateMatrix(ObjParts * parts, DirectX::SimpleMath::Matrix * parent)
{
}
