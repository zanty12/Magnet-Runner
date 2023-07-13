//=============================================================================
//
// 入力処理 [calculations.h]
// Author :
//
//=============================================================================
#pragma once

#include "main.h"
#include "renderer.h"

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

bool CheckHitBB(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh);

bool CheckHitBC(float ax, float ay, float ar, float bx, float by, float br);

bool CheckHitBCSq(float ax, float ay, float ar, float bx, float by, float br);