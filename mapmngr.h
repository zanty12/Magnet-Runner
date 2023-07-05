#pragma once
#include "map.h"
class Mapmngr
{
private:
	int* MapData_;
	Map* Map_;
public:
	Mapmngr() = default;
	~Mapmngr() { delete Map_; delete[] MapData_; };
	void LoadMap(const char* fileName);
	void DrawMap(){ Map_->Draw(); }
	Map* GetMap() {if (Map_ != nullptr) return Map_; }

};

