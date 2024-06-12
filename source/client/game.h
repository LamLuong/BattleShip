#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <map>

#include "img_object.h"

class Game {
 public:
	~Game();
	int Initital(const std::string& config_path);
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

	std::map<std::string, ImgObject*> objs_;
};

#endif /* GAME_H */