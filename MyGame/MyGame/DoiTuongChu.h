

#ifndef TEXT_OBJECT_H_
#define TEXT_OBJECT_H_
#include "HamDungChung.h"

class DoiTuongChu
{
public:
  DoiTuongChu(void);
  ~DoiTuongChu(void);

  enum TextColor
  {
    RED_TEXT  = 0,
    WHITE_TEXT = 1,
    BLACK_TEXT = 2,
  };

  bool HienThi(TTF_Font* gFont, SDL_Renderer* screen);
  void GiaiPhongVungNho();

  void SetMau(Uint8 red, Uint8 green, Uint8 blue);
  void SetMauRGB(int type);

  void HienThiChu(SDL_Renderer* screen, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

  int getWidth() const {return chieuRong;}
  int getHeight() const {return chieuCao;}
  void SetNoiDung(const std::string& text) {str = text;}
  std::string GetText() const {return str;}

private:
  std::string str;
  SDL_Color mauSac;
  SDL_Texture* doiTuong;
  int chieuRong;
  int chieuCao;

};

#endif

