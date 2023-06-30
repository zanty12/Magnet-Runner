#include "mapmngr.h"
#include <fstream>
#include <sstream>
#include <string>


void Mapmngr::LoadMap(const char* fileName)
{
	//load a csv file with the first line being the map size and create a map with that size
	//then load the map from the csv file
	std::ifstream file(fileName);
	//abort if failed to open file
	if (!file)
	{
		return;
	}
	std::string line;
	std::getline(file,line);
	std::stringstream ss(line);
	std::string item;
	std::getline(ss,item,',');
	int width = stoi(item);
	std::getline(ss,item,',');
	int height = stoi(item);
	Map_ = new Map(width,height);
	MapData_ = new int[width * height];
	int y = 0;
	while(std::getline(file,line))
	{
		std::stringstream ss(line);
		std::string item;
		int x = 0;
		while(std::getline(ss,item,','))
		{
			MapData_[y * width + x] = stoi(item);
			Map_->PutCell(x,y,stoi(item));
			x++;
		}
		y++;
	}
	file.close();
    



}
