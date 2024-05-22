#ifndef KHOI_GACH_KEP_H
#define KHOI_GACH_KEP_H

#include "QuanLyToaDo.h"
#include "OngKhoi.h"

class KhoiGachKep
{
public:
    KhoiGachKep();
    ~KhoiGachKep();
    bool KhoiTaoKhoiGach(SDL_Renderer* screen, const int& xp);
    void HienThiHinhAnh(SDL_Renderer* screen);
    void ThucHienDiChuyen();
    bool TrangThaiDaVuotQuaKhoiGach() const { return daDiQuaKhoiGach; }
    void SetDaDiQuaKhoiGach(bool isBack);
    SDL_Rect LayKichThuocKhoiGachTren();
    void SetViTri(const UINT& xp);
    void GetKichThuocKhoiGach();
    void VeDuongVien(SDL_Renderer* des);
    bool KiemTraDaVuotQuaKhoiGach(SDL_Rect rect);
    bool DaVuotQuaKhoiGach() const { return daVuotQua; }
    void SetDaVuotQua(const bool& pp) { daVuotQua = pp; }
    bool KiemTraCot(SDL_Rect pl_rect);
private:
    OngKhoi khoiGachTren;
    OngKhoi khoiGachDuoi;
    UINT viTriX;
    bool daDiQuaKhoiGach;
    SDL_Rect kichThuocVatThe;
    bool daVuotQua;
};
#endif