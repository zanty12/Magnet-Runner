#pragma once

typedef enum {
	SCENE_TITLE = 0,
	SCENE_MENU,
	SCENE_GAME,
	SCENE_RESULT_FAIL,
	SCENE_RESULT_CLEAR,
	SCENE_MAX
}SCENENO;

class Scenemngr;
class Scene;
class Title;
class Menu;
class Game;
class Fail;
class Result;