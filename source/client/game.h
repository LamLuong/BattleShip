#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#include "item.h"

class Game {
 public:
	~Game();
	int Initital(const char* name, int x, int y, int w, int h);
	int Render();
	int HandleEvents();
	int GameUpdate();

	bool IsRunning() {
		return is_running_;
	}

	static Game* GetIns() { 
		if (!instance_)
			instance_ = new Game;
		return instance_;
	}
 private:
	Game();
	bool is_running_;
	SDL_Window* game_window_;
	SDL_Renderer* game_render_;
	static Game* instance_;

	Item* item1;
};

#endif /* GAME_H */