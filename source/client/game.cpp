#include "game.h"

#include <fstream>
#include <sstream>

Game *Game::instance_ = NULL;

Game::Game () {
  game_window_ = NULL;
  game_render_ = NULL;
}

Game::~Game () {
  if (game_render_) {
    SDL_DestroyRenderer(game_render_);
    game_render_ = NULL;
  }

  if (game_window_) {
    SDL_DestroyWindow(game_window_);
    game_window_ = NULL;
  }

  for (auto obj : objs_) {
    if (obj.second)
      delete obj.second;
    obj.second = NULL;
  }
  objs_.clear();

  SDL_Quit();
}

int Game::Initital(const std::string& config_path) {
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    printf("SDL Error: Failed to init SDL.\n");
    return -1;
  }

  game_window_ = SDL_CreateWindow("Hello Lam", SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, 670, 550,
                                  SDL_WINDOW_SHOWN);
  if (!game_window_) {
    printf("SDL Error: Failed to create window: %s .\n", SDL_GetError());
    return -1;
  }

  game_render_ = SDL_CreateRenderer(game_window_, -1, 0);
  if (!game_render_) {
    printf("SDL Error: Failed to create render: %s .\n", SDL_GetError());
    return -1;
  }
  is_running_ = true;

  std::ifstream fin(config_path);
	std::string line;
	std::string::size_type sz;
  ImgObject *img_obj = NULL;
	while (std::getline(fin, line)) {
		std::istringstream in(line);
		std::string option, id, path, x_val, y_val, n_part;

    in >> option >> id >> path >> x_val >> y_val >> n_part;
    if (option.compare("background") == 0) {
      img_obj = new Background();
    } else if (option.compare("coordinate") == 0) {
      img_obj = new CoordinateManager();
    }

    img_obj->CreateTexture(path, id, game_render_);
    img_obj->InitPosition(Point(std::atoi(x_val.c_str()),
                                     std::atoi(y_val.c_str())));
    img_obj->SetSlidePart(std::atoi(n_part.c_str()));
    objs_[id] = img_obj;
  }
  return 0;
}

int Game::Render() {
  SDL_RenderClear(game_render_);

  for (auto obj : objs_)
    obj.second->Draw(game_render_);

  SDL_RenderPresent(game_render_);
  return 0;
}

int Game::GameUpdate() {
  for (auto obj : objs_)
    obj.second->Update();
  return 0;
}

int Game::HandleEvents() {
  SDL_Event event;
  if (SDL_PollEvent(&event)) {
    int x_button_mouse = event.button.x;
	  int y_button_mouse = event.button.y;

	  int x_motion_mouse = event.motion.x;
	  int y_motion_mouse = event.motion.y;

    switch(event.type){
      case SDL_QUIT:
        is_running_ = false;
        break;
      case SDL_MOUSEBUTTONDOWN:
        
        break;

      case SDL_MOUSEMOTION:
        
        break;

      default:
        break;
    } 
  }
  return 0;
}