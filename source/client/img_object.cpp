#include "img_object.h"

ImgObject::ImgObject() {
  texture_ = NULL;
  n_part_ = 1;
}

ImgObject::~ImgObject() {
  SDL_DestroyTexture(texture_);
}

int ImgObject::CreateTexture(const std::string& path,
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
  src_.x = 0;
  src_.y = 0;
  texture_w_ = sur->w;
  texture_h_ = sur->h;

	SDL_FreeSurface(sur);
  return 0;
}

void ImgObject::InitPosition(const Point& pos) {
  dst_.x = pos.x;
  dst_.y = pos.y;
  src_.x = 0;
  src_.y = 0;

  dst_.w = src_.w = texture_w_;
  dst_.h = src_.h = texture_h_;

}

int ImgObject::Draw(SDL_Renderer* render, SDL_RendererFlip flip) {
  SDL_RenderCopyEx(render, texture_, &src_, &dst_, 0, 0, flip);
  return 0;
}

// int ImgObject::Update() {
//   return 0;
// }

void ImgObject::SetSlidePart(int n) {
  n_part_ = n;
  dst_.w = texture_w_ / n_part_;
  src_.w = texture_w_ / n_part_;
}