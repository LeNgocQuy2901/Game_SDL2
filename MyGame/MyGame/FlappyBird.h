
#ifndef FLAPPY_BIRD_H_
#define FLAPPY_BIRD_H_

#include "HamDungChung.h"

class FlappyBird : public DoiTuongCoSo
{
public:
  FlappyBird();
  ~FlappyBird();

  bool NapHinhAnh(std::string path, SDL_Renderer* screen);
  void HienThi(SDL_Renderer* des);
  void XuLySuKienBanPhim(SDL_Event events, SDL_Renderer* screen); 

  void ThucHienRoiXuong(SDL_Renderer* des);
  bool LayTrangThaiDangRoi() const { return dangRoiXuong; }
  void DatTrangThaiDangRoi(bool isDangRoiXuong) { dangRoiXuong = isDangRoiXuong; }
  void DoGround(SDL_Renderer* screen);
  bool DoiTuongBiDie() const { return isKetThucMang; }
private:
  bool dangRoiXuong;
  float x_val_;
  float toaDoTrucY;
  bool isKetThucMang;
};


#endif