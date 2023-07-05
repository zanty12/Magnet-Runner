//=============================================================================
//
// “–‚½‚è”»’è [calculations.cpp]
// Author : 
//
//=============================================================================

#include "calculations.h"
#include "main.h"


bool CheckHitBB(float ax,float ay, float aw,float ah,float bx,float by,float bw,float bh) {
	float al = ax - aw / 2;
	float ar = ax + aw / 2;
	float at = ay - ah / 2;
	float ab = ay + ah / 2;
	float bl = bx - bw / 2;
	float br = bx + bw / 2;
	float bt = by - bh / 2;
	float bb = by + bh / 2;

	if (bl < ar) {
		if (br > al) {
			if (bt < ab) {
				if (bb > at) {
					return true;
				}
			}
		}
	}
	return false;
}

bool CheckHitBC(float ax, float ay,float ar,float bx,float by,float br) {

	D3DXVECTOR2 aPos = D3DXVECTOR2(ax,ay);
	D3DXVECTOR2 bPos = D3DXVECTOR2(bx, by);

	D3DXVECTOR2 dist = bPos - aPos;	
	float length = D3DXVec2Length(&dist);
	float r = ar + br;
	if (length < r) {
		return true;
	}
	
	return false;
}

bool CheckHitBCSq(float ax, float ay, float ar, float bx, float by, float br) {

	D3DXVECTOR2 aPos = D3DXVECTOR2(ax, ay);
	D3DXVECTOR2 bPos = D3DXVECTOR2(bx, by);

	D3DXVECTOR2 dist = bPos - aPos;
	float length = D3DXVec2LengthSq(&dist);
	float r = (ar + br) * (ar + br);
	if (length < r) {
		return true;
	}

	return false;
}