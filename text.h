#include <string>
#include <iostream>
#include <vector>
#include "main.h"


typedef struct {
	char content;
	D3DXVECTOR2 pos;
} TEXT;

void InitText();
void PrintText(std::string text, D3DXVECTOR2 pos);
void DrawText();
void ClearText();