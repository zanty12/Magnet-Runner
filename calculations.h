//=============================================================================
//
// ���͏��� [calculations.h]
// Author :
//
//=============================================================================
#pragma once

#include "main.h"
#include "renderer.h"

//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

bool CheckHitBB(float ax, float ay, float aw, float ah, float bx, float by, float bw, float bh);

bool CheckHitBC(float ax, float ay, float ar, float bx, float by, float br);

bool CheckHitBCSq(float ax, float ay, float ar, float bx, float by, float br);