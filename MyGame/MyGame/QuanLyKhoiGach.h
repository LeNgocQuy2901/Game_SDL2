#ifndef QUAN_LY_KHOI_GACH_H
#define QUAN_LY_KHOI_GACH_H

#include "QuanLyToaDo.h"
#include "OngKhoi.h"
#include "KhoiGachKep.h"

class QuanLyKhoiGach
{
public:
    QuanLyKhoiGach();
    ~QuanLyKhoiGach();

    bool KhoiTaoDanhSachKhoiGach(SDL_Renderer* screen);
    void ChayChuyenDong(SDL_Renderer* screen);
    void SetDungDiChuyen(const bool& stop);
    void DatToaDo(SDL_Rect pRect) { kichThuocBird = pRect; }
    bool LayTrangThaiCot() const { return laCot; }
    INT LaySoLuongKhoiGach() const { return soLuongDaVuotQua; }
    void XoaDanhSachKhoi();
private:
    std::vector<KhoiGachKep*> danhSachKhoiGach;
    UINT toiDa;
    bool dungDiChuyen;
    SDL_Rect kichThuocBird;
    INT soLuongDaVuotQua;
    bool laCot;
};
#endif