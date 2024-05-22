#include "OngKhoi.h"

OngKhoi::OngKhoi()
{
    daVuotQua = false;
}

OngKhoi::~OngKhoi()
{

}


bool OngKhoi::NapHinhAnh(std::string duongDan, SDL_Renderer* render)
{
    return DoiTuongCoSo::NapHinhAnh(duongDan, render);
}

void OngKhoi::SetViTri(const int& viTriX, const int& viTriY)
{
    this->SetToaDo(viTriX, viTriY);
}

void OngKhoi::SetViTriX(const int& viTriX)
{
    SDL_Rect toaDo = this->LayToaDo();
    this->SetToaDo(viTriX, toaDo.y);
}

void OngKhoi::HienThiHinhAnh(SDL_Renderer* render)
{
    this->HienThi(render);
}

void OngKhoi::ThucHienDiChuyen(UINT& giaTriX)
{
    this->toaDoVatThe.x += giaTriX;

    if (toaDoVatThe.x + toaDoVatThe.w < 0)
    {
        daVuotQua = true;
    }
}