#pragma once
#include "map.h"
class Mapmngr
{
private:
	int* mapData_;
	Map* map_;
public:
	Mapmngr() = default;
	~Mapmngr() { delete map_; delete[] mapData_; };
	void LoadMap(const char* fileName);
	void UpdateMap() { map_->Update(); }
	void DrawMap() { map_->Draw(); }
	Map* GetMap() { if (map_ != nullptr) return map_; }
};
