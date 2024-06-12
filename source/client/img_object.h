#ifndef IMG_OBJECT_H
#define IMG_OBJECT_H

#include <string>
#include <SDL2/SDL_image.h>

#include "utils/point.h"


class ImgObject {
 public:
  ImgObject();
  virtual ~ImgObject();
  int CreateTexture(const std::string& path,
                    const std::string& id,
                    SDL_Renderer* render);
  virtual void InitPosition(const Point& pos);
  void SetSlidePart(int);

  int Draw(SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
  virtual int Update() = 0;


 protected:
  SDL_Texture* texture_;

  std::string id_;

  int texture_w_, texture_h_;
  SDL_Rect src_, dst_;
  int n_part_;
};

class Background : public ImgObject {
 public:
  Background();
  ~Background();
  int Update();
};

class CoordinateManager : public ImgObject {
 public:
  CoordinateManager();
  ~CoordinateManager();
  
  int Update();
  int MouseHover(const Point&);
};

#endif /*IMG_OBJECT_H*/