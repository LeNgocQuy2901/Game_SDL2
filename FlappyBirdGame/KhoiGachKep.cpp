#include "KhoiGachKep.h"


KhoiGachKep::KhoiGachKep()
{
    viTriX = -3;
    daDiQuaKhoiGach = false;
    daVuotQua = false;
}

KhoiGachKep::~KhoiGachKep()
{

}

bool KhoiGachKep::KhoiTaoKhoiGach(SDL_Renderer* render, const int& vX)
{
    int rnd = HamDungChung::NgauNhien(1, 10);
    int j = rnd;
    rnd = rnd * 14;

    bool khoiGachTrenDuocNap = khoiGachTren.NapHinhAnh("img//topblock2.png", render);
    bool khoiGachDuoiDuocNap = khoiGachDuoi.NapHinhAnh("img//bottomblock2.png", render);

    if (j % 2 == true)
    {
        khoiGachTren.SetViTri(vX, -350 - rnd);
        khoiGachDuoi.SetViTri(vX, KICH_THUOC_BAN_DO - 220 - rnd);
    }
    else
    {
        khoiGachTren.SetViTri(vX, -350 + rnd);
        khoiGachDuoi.SetViTri(vX, KICH_THUOC_BAN_DO - 220 + rnd);
    }

    if (khoiGachTrenDuocNap && khoiGachDuoiDuocNap)
        return true;
    return false;
}

void KhoiGachKep::HienThiHinhAnh(SDL_Renderer* butVe)
{
    khoiGachTren.HienThiHinhAnh(butVe);
    khoiGachDuoi.HienThiHinhAnh(butVe);
}

void KhoiGachKep::ThucHienDiChuyen()
{
    khoiGachTren.ThucHienDiChuyen(viTriX);
    khoiGachDuoi.ThucHienDiChuyen(viTriX);

    if (khoiGachTren.KhoiGachDaDiQua() || khoiGachDuoi.KhoiGachDaDiQua())
    {
        daDiQuaKhoiGach = true;
    }
}

SDL_Rect KhoiGachKep::LayKichThuocKhoiGachTren()
{
    return khoiGachTren.LayKichThuoc();
}

void KhoiGachKep::SetViTri(const UINT& xp)
{
    khoiGachTren.SetViTriX(xp);
    khoiGachDuoi.SetViTriX(xp);
}

void KhoiGachKep::SetDaDiQuaKhoiGach(bool isBack)
{
    daDiQuaKhoiGach = isBack;
    khoiGachTren.SetDaDiQua(isBack);
    khoiGachDuoi.SetDaDiQua(isBack);
}

void KhoiGachKep::GetKichThuocKhoiGach()
{
    SDL_Rect kichThuocKhoiGachTren = khoiGachTren.LayKichThuoc();

    kichThuocVatThe.x = kichThuocKhoiGachTren.x + kichThuocKhoiGachTren.w;
    kichThuocVatThe.y = kichThuocKhoiGachTren.y + kichThuocKhoiGachTren.h;
    kichThuocVatThe.w = 5;
    kichThuocVatThe.h = 160;
}

void KhoiGachKep::VeDuongVien(SDL_Renderer* butVe)
{
    DinhDangToaDo kichThuocDuongVien(kichThuocVatThe.x, kichThuocVatThe.y, kichThuocVatThe.w, kichThuocVatThe.h);
    DuLieuMauSac color(255, 255, 255);
    QuanLyToaDo::VeDuongVien(kichThuocDuongVien, color, butVe);
}

bool KhoiGachKep::KiemTraDaVuotQuaKhoiGach(SDL_Rect rect)
{
    return HamDungChung::KiemTraVaCham(rect, kichThuocVatThe);
}

bool KhoiGachKep::KiemTraCot(SDL_Rect pl_rect)
{
    bool vaChamTren = HamDungChung::KiemTraVaCham(pl_rect, khoiGachTren.LayKichThuoc());
    bool vaChamDuoi = HamDungChung::KiemTraVaCham(pl_rect, khoiGachDuoi.LayKichThuoc());

    if (vaChamTren || vaChamDuoi)
    {
        return true;
    }

    return false;
}