#include <string>
#include <iostream>
#include <vector>
#include "main.h"


typedef struct {
	char content;
	D3DXVECTOR2 pos;
	float scale;
} TEXT;

void InitText();
float GetTextWidth(std::string text, float scale = 1.0f);
void PrintText(std::string text, D3DXVECTOR2 pos);
void PrintText(std::string text, D3DXVECTOR2 pos, float scale);
void DrawText();
void ClearText();