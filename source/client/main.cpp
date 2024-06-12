#include <unistd.h>
#include "game.h"

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Please input config path file.\n");
    return -1;
  }

  Game::GetIns()->Initital(argv[1]);
  Game::GetIns()->Render();
 
  while(Game::GetIns()->IsRunning()) {
    Game::GetIns()->HandleEvents();
    Game::GetIns()->GameUpdate();
    Game::GetIns()->Render();
    usleep(10000);
  }

  delete Game::GetIns();
  return 0;
}