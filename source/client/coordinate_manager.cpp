#include "img_object.h"

CoordinateManager::CoordinateManager() : ImgObject() {}

CoordinateManager::~CoordinateManager() {}

int CoordinateManager::Update() {
  src_.x = src_.w * ((int)(SDL_GetTicks() / 100) % n_part_);
  return 0;
};

int MouseHover(const Point&) {
  return 0;
}