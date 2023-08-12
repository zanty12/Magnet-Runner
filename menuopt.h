#pragma once
#include <string>
#include "main.h"

class Menuopt
{
private:
	int bgTex_ = 0;
	int levelTex_ = 0;
	std::string level_ = "level 1";
	std::string mapFile_ = "data/MAP/map2.csv";
	bool chosen_ = false;
	D3DXVECTOR2 pos_ = { 0.0f,0.0f };
public:
	Menuopt() = default;
	Menuopt(int bgtex, int leveltex, std::string level,std::string mapFile,float x,float y) :bgTex_(bgtex), levelTex_(leveltex), level_(level),mapFile_(mapFile), pos_(D3DXVECTOR2(x, y)) {}
	~Menuopt() = default;
	void Draw();
	void SetChosen(bool chosen) { chosen_ = chosen; };
	bool GetChosen() { return chosen_; };
	std::string GetMapFile() { return mapFile_; };
};

