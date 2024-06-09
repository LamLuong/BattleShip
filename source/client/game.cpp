#include "game.h"

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

  if (item1) {
    delete item1;
    item1 = NULL;
  }

  SDL_Quit();
}

int Game::Initital(const char* name, int x, int y, int w, int h) {
  if (SDL_Init(SDL_INIT_EVERYTHING)) {
    printf("SDL Error: Failed to init SDL.\n");
    return -1;
  }

  game_window_ = SDL_CreateWindow(name, x, y, w, h, SDL_WINDOW_SHOWN);
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

  item1 = new Item();
  item1->CreateTexture("/home/lamlt/Downloads/animate-alpha.png", "item1", game_render_);

  return 0;
}

int Game::Render() {
  SDL_RenderClear(game_render_);

  item1->Draw(game_render_);
  SDL_RenderPresent(game_render_);
  return 0;
}

int Game::GameUpdate() {
  item1->Update();
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
        printf("%d %d %d %d \n", x_button_mouse, y_button_mouse, x_motion_mouse, y_motion_mouse);
        break;

      case SDL_MOUSEMOTION:
        printf("%d %d %d %d \n", x_button_mouse, y_button_mouse, x_motion_mouse, y_motion_mouse);
        break;

      default:
        break;
    } 
  }
  return 0;
}