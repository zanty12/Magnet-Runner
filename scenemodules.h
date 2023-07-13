#pragma once

typedef enum {
	SCENE_TITLE = 0,
	SCENE_MENU,
	SCENE_GAME,
	SCENE_RESULT,
	SCENE_MAX
}SCENENO;

class Scenemngr;
class Scene;
class Title;
class Game;