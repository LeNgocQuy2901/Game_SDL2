#ifndef ONG_KHOI_H_
#define ONG_KHOI_H_

#include "QuanLyToaDo.h"

class OngKhoi : DoiTuongCoSo
{
public:
    OngKhoi();
    ~OngKhoi();
    bool NapHinhAnh(std::string path, SDL_Renderer* screen);
    void SetViTri(const int& xp, const int& yp);
    void SetViTriX(const int& xp);
    SDL_Rect LayKichThuoc() const { return this->LayToaDo(); }
    void HienThiHinhAnh(SDL_Renderer* screen);
    void ThucHienDiChuyen(UINT& x_val);
    bool KhoiGachDaDiQua() const { return daVuotQua; }
    void SetDaDiQua(bool b) { daVuotQua = b; }
private:
    bool daVuotQua;
    int x_pos_;
    int y_pos_;
};

#endif
