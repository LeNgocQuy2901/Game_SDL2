#include "DoiTuongChu.h"


DoiTuongChu::DoiTuongChu(void)
{
  mauSac.r = 255;
  mauSac.g = 255;
  mauSac.b = 255;
}


DoiTuongChu::~DoiTuongChu(void)
{
}


bool DoiTuongChu::HienThi(TTF_Font* gFont, SDL_Renderer* butVe)
{
  SDL_Surface* sf = TTF_RenderText_Solid(gFont, str.c_str(), mauSac);

  if( sf != NULL )
  {
    doiTuong = SDL_CreateTextureFromSurface(butVe, sf);

    if( doiTuong != NULL )
    {
      // Lấy kích thước hình ảnh
      chieuRong = sf->w;
      chieuCao = sf->h;
    }

    // Xoá vùng hiển thị cũ
    SDL_FreeSurface( sf );
  }

  return doiTuong != NULL;
}

void DoiTuongChu::GiaiPhongVungNho()
{
    if (doiTuong == NULL)
        return;
  
    SDL_DestroyTexture(doiTuong);
    doiTuong = NULL;
  
}

void DoiTuongChu::SetMau(Uint8 red, Uint8 green, Uint8 blue)
{
  mauSac.r = red;
  mauSac.g = green;
  mauSac.b = blue;
}

void DoiTuongChu::SetMauRGB(int type)
{
  if (type == RED_TEXT)
  {
    SDL_Color color = {255, 0, 0};
    mauSac = color;
  }
  else if (type == WHITE_TEXT)
  {
    SDL_Color color = {255, 255, 255};
    mauSac = color;
  }
  else
  {
    SDL_Color color = {0, 0, 0};
    mauSac = color;
  }
}
void DoiTuongChu::HienThiChu(
        SDL_Renderer* butVe
        , int toaDoX
        , int toaDoY
        , SDL_Rect* toaDo 
        , double gocNghieng 
        , SDL_Point* center 
        , SDL_RendererFlip xoay)
{

  SDL_Rect rect = { 
      toaDoX, 
      toaDoY, 
      chieuRong, 
      chieuCao 
  };

  if( toaDo != NULL )
  {
    rect.w = toaDo->w;
    rect.h = toaDo->h;
  }

  // Hiển thị ra màn hình
  SDL_RenderCopyEx(
       butVe, 
      doiTuong, 
      toaDo, 
      &rect, 
      gocNghieng, 
      center, 
      xoay 
  );
}
