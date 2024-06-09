#include <unistd.h>
#include "game.h"

int main(int argc, char* args[]) {
  Game::GetIns()->Initital("Hello Lam", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 670, 550);
  Game::GetIns()->Render();
 
  while(Game::GetIns()->IsRunning()) {
    Game::GetIns()->HandleEvents();
    Game::GetIns()->Render();
    usleep(10000);
  }
  return 0;
}