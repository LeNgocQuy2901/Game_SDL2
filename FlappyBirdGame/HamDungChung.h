

#ifndef HAM_DUNG_CHUNG_H
#define HAM_DUNG_CHUNG_H

#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "DoiTuongChu.h"
#include "DoiTuongCoSo.h"

using namespace std;

static SDL_Window* gKhungHienThi = NULL;
static SDL_Renderer* gButVe = NULL;
const string TIEU_DE_KHUNG_HIEN_THI = "Flappy Bird Game";

#define CHIEU_RONG_KHUNG_HIEN_THI 1280
#define CHIEU_CAO_KHUNG_HIEN_THI 640


static SDL_Event gSDLEvent;

#define TAN_SO_AM_THANH 22050
#define SO_KENH_AM_THANH 2
#define KHOI_AM_THANH 4096

#define KICH_THUOC_BAN_DO 600

const int MAU_TRONG_SUOT_DO = 180;
const int MAU_TRONG_SUOT_XANH_LA = 180;
const int MAU_TRONG_SUOT_XANH_DUONG = 180;
const int MAU_BUT_VE = 0XFF;
const int KHUNG_HINH_HIEN_THI = 55;
const int KICH_THUOC_DO_RONG_MAN = 1280;
const int KICH_THUOC_DO_CAO_MAN = 640;

typedef struct DinhDangToaDo
{
public:
    DinhDangToaDo(
        int left, 
        int top,
        int width, 
        int height) 
    { 
        Left = left; 
        Top = top; 
        Width = width; 
        Height = height;
    }
    
    int Left;
    int Top;
    int Width;
    int Height;
};

typedef struct DuLieuMauSac
{
public:
    DuLieuMauSac(Uint8 r, 
        Uint8 g, 
        Uint8 b) 
    {
        R = r, G = g, B = b;
    }
    Uint8 R;
    Uint8 G;
    Uint8 B;
};

namespace HamDungChung
{
    void HienThiThongBaoLoi(std::ostream& os,
        const std::string& msg, bool fatal = false);

    bool KiemTraVaCham(const SDL_Rect& object1, const SDL_Rect& object2);

    int HienThiMenu(SDL_Renderer* render, TTF_Font* font, 
                      const std::string& mnuFunc, 
                      const std::string& mnuExit,
                      const std::string& img_name);
    int NgauNhien(int from, int to);
}

#endif