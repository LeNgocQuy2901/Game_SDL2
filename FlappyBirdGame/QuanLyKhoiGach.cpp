#include "QuanLyKhoiGach.h"


int viTriHienThiKhoiGach[] = { 1250, 1500, 1750, 2000, 2250, 2500 };


QuanLyKhoiGach::QuanLyKhoiGach()
{
    toiDa = 0;
    dungDiChuyen = false;
    soLuongDaVuotQua = 0;
    laCot = false;
}

QuanLyKhoiGach::~QuanLyKhoiGach()
{
    XoaDanhSachKhoi();
}

void QuanLyKhoiGach::XoaDanhSachKhoi()
{
    for (int i = 0; i < danhSachKhoiGach.size(); i++)
    {
        KhoiGachKep* p = danhSachKhoiGach.at(i);
        delete p;
        p = NULL;
    }

    danhSachKhoiGach.clear();
}

bool QuanLyKhoiGach::KhoiTaoDanhSachKhoiGach(SDL_Renderer* screen)
{
    KhoiGachKep* b;

    for (int i = 0; i < 6; i++) {
         b = new KhoiGachKep();
        if (!b->KhoiTaoKhoiGach(screen, viTriHienThiKhoiGach[i])) {
            // Nếu có lỗi xảy ra thì xoá danh sách khối gạch và kết thúc
            XoaDanhSachKhoi();
            return false;
        }
        danhSachKhoiGach.push_back(b);
    }
    toiDa = danhSachKhoiGach.size() - 1;
    return true;
}

void QuanLyKhoiGach::SetDungDiChuyen(const bool& stop)
{
    dungDiChuyen = stop;
}

void QuanLyKhoiGach::ChayChuyenDong(SDL_Renderer* butVe)
{
    for (int bIndex = 0; bIndex < danhSachKhoiGach.size(); bIndex++)
    {
        KhoiGachKep* khoiGach = danhSachKhoiGach.at(bIndex);

        khoiGach->GetKichThuocKhoiGach();

        if (!dungDiChuyen)
        {
            khoiGach->ThucHienDiChuyen();

            bool result = khoiGach->TrangThaiDaVuotQuaKhoiGach();

            if (result)
            {
                KhoiGachKep* endBlock = danhSachKhoiGach.at(toiDa);
                SDL_Rect end_rect = endBlock->LayKichThuocKhoiGachTren();
                UINT xp = end_rect.x + 250;
                khoiGach->SetViTri(xp);
                khoiGach->SetDaDiQuaKhoiGach(false);
                khoiGach->SetDaVuotQua(false);
                toiDa = bIndex;
            }

            bool isCol = khoiGach->KiemTraCot(kichThuocBird);

            if (isCol)
            {
                laCot = true;
                Mix_Chunk* beep_sound = Mix_LoadWAV("sound//punch.wav");
                if (beep_sound != NULL)
                    Mix_PlayChannel(-1, beep_sound, 0);
                break;
            }

            result = khoiGach->KiemTraDaVuotQuaKhoiGach(kichThuocBird);
            
            if (result)
            {
                //khoiGach->SetDaVuotQua(true);

                /*if (khoiGach->DaVuotQuaKhoiGach())
                {*/
                    Mix_Chunk* amThanh = Mix_LoadWAV("sound//ting.wav");

                    if (amThanh != NULL)
                        Mix_PlayChannel(-1, amThanh, 0);
                    soLuongDaVuotQua++;
                    khoiGach->SetDaVuotQua(true);
                //}
            }
        }

        khoiGach->HienThiHinhAnh(butVe);

    }
}
