
#ifndef DONG_HO_H_
#define DONG_HO_H_

class DongHo
{
public:
  DongHo();
  void Chay();
  void KetThuc();
  void TamDung();
  void TiepTucChay();
  int LayThoiGian();
  bool IsDangChay();
  bool IsDangDung();
private:
  int thoiGianBatDau;
  int thoiGianDung;
  bool isDangDung;
  bool isDangChay;
};

#endif