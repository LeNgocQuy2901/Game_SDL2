
#ifndef QUAN_LY_TOA_DO_H
#define QUAN_LY_TOA_DO_H

#include "HamDungChung.h"

class QuanLyToaDo
{
public:
   static void VeHinhChuNhat(const DinhDangToaDo& geo_size, const DuLieuMauSac& color, SDL_Renderer* screen);
   static void VeDuongVien(const DinhDangToaDo& geo_size, const DuLieuMauSac& color, SDL_Renderer* screen);
};


#endif