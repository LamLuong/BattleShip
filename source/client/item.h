#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <SDL2/SDL_image.h>

class Item {
 public:
  Item();
  ~Item();
  int CreateTexture(const std::string& path,
                    const std::string& id,
                    SDL_Renderer* render);

  int Draw(SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  int Update();

 private:
  SDL_Texture* texture_;
  std::string id_;
};

#endif /*ITEM_H*/