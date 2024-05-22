
#include "FlappyBird.h"

FlappyBird::FlappyBird()
{
    dangRoiXuong = false;
    toaDoTrucY = 1;
}

FlappyBird::~FlappyBird()
{
  GiaiPhongDoiTuong();
}

void FlappyBird::XuLySuKienBanPhim(SDL_Event suKien, SDL_Renderer* butVe) 
{
  if( suKien.type == SDL_KEYDOWN )
  {
    switch( suKien.key.keysym.sym )
    {
    case SDLK_UP:
      {
        if (dangRoiXuong == false)
        {
            toaDoTrucY = -15;
        }
      }
    }
  }
  else if( suKien.type == SDL_KEYUP )
  {
    switch( suKien.key.keysym.sym )
    {
    case SDLK_UP:
        {
            toaDoTrucY = 5;
        }
        break;
    }
  }
}


bool FlappyBird::NapHinhAnh(std::string duongDan, SDL_Renderer* butVe)
{
    return DoiTuongCoSo::NapHinhAnh(duongDan, butVe);
}

void FlappyBird::HienThi(SDL_Renderer* butVe)
{
   DoiTuongCoSo::HienThi(butVe);
}

void FlappyBird::ThucHienRoiXuong(SDL_Renderer* butVe)
{
    toaDoVatThe.y += toaDoTrucY;

    if ((toaDoVatThe.y + toaDoVatThe.h) >= KICH_THUOC_BAN_DO)
    {
        NapHinhAnh("image//fl_bird2.png", butVe);
        dangRoiXuong = true;
        DoGround(butVe);
    }
}

void FlappyBird::DoGround(SDL_Renderer* butVe)
{
    toaDoTrucY = 0;
    toaDoVatThe.y = KICH_THUOC_BAN_DO - toaDoVatThe.h;
    isKetThucMang = true;
}