#include "item.h"

Item::Item() {
  texture_ = NULL;
}

Item::~Item() {
  SDL_DestroyTexture(texture_);
}

int Item::CreateTexture(const std::string& path,
                        const std::string& id,
                        SDL_Renderer* render) {
  id_ = id;

  SDL_Surface* sur = IMG_Load(path.c_str());
  if (!sur) {
    printf("Could not create surface from file. \n");
    return -1;
  }

	texture_ = SDL_CreateTextureFromSurface(render, sur);
  if (!texture_) {
    printf("Could not create texture from surface. \n");
    SDL_FreeSurface(sur);
    return -1;
  }

	SDL_FreeSurface(sur);
  return 0;
}

int Item::Draw(SDL_Renderer* render, SDL_RendererFlip flip) {
  SDL_Rect srcRect;
  SDL_Rect destRect;
  
  srcRect.x = 128 * int(((SDL_GetTicks() / 100) % 6));
  srcRect.y = 0;
  srcRect.w = destRect.w = 128;
  srcRect.h = destRect.h = 82;
  destRect.x = 110;
  destRect.y = 0;
    
  SDL_RenderCopyEx(render, texture_, &srcRect, &destRect, 0, 0, flip);
  return 0;
}

int Item::Update() {
  
  return 0;
}