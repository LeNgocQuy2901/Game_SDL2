
#include "DongHo.h"
#include "HamDungChung.h"

DongHo::DongHo()
{
  thoiGianBatDau = 0;
  thoiGianDung = 0;
  isDangDung = false;
  isDangChay = false;
}

void DongHo::Chay()
{
  isDangChay = true;
  isDangDung = false;
  thoiGianBatDau = SDL_GetTicks();
}

void DongHo::KetThuc()
{
  isDangChay = false;
  isDangDung = false;
}

void DongHo::TamDung()
{
    if (!isDangChay)
        return;

    isDangDung = true;
    thoiGianDung = SDL_GetTicks() - thoiGianBatDau;
}

void DongHo::TiepTucChay()
{
    if (!isDangDung)
        return;

    isDangDung = false;
    thoiGianBatDau = SDL_GetTicks() - thoiGianDung;
    thoiGianDung = 0;
}

int DongHo::LayThoiGian()
{
    if (!isDangChay) return 0;

    if (isDangDung)
    {
      return thoiGianDung;
    }
    
    return SDL_GetTicks() - thoiGianBatDau;
}

bool DongHo::IsDangChay()
{
  return isDangChay;
}

bool DongHo::IsDangDung()
{
  return isDangDung;
}