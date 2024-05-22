
#include "HamDungChung.h"

int HamDungChung::HienThiMenu(SDL_Renderer* butVe
                            , TTF_Font* ttfFont, 
                            const std::string& mnuIFunction, 
                            const std::string& mnuExit,
                            const std::string& imageFile)
{
    char* mnuFuncName = (char*)mnuIFunction.c_str();
    char* mnuExitName = (char*)mnuExit.c_str();
    char* imgFile = (char*)imageFile.c_str();

    int mnuFuncLength = mnuIFunction.length();
    int mnuExitLength = mnuExit.length();

    int stick = 0;
    int x = 0;
    int y = 0;
    const int kIdx = 2;
    char* mnuName[kIdx];

    mnuName[0] = new char [mnuFuncLength + 1];
    mnuName[1] = new char[mnuExitLength + 1];

    strcpy_s(mnuName[0], mnuFuncLength+1, mnuFuncName);
    strcpy_s(mnuName[1], mnuExitLength+1, mnuExitName);

    SDL_Texture* menu[kIdx];
    bool selected[kIdx] = { 0, 0 };
    
    SDL_Color color[2] = {
        { 255, 255, 255 },
        { 255, 0, 0 } 
    };

    DoiTuongChu mnuText[kIdx];

    mnuText[0].SetNoiDung(mnuName[0]);
    mnuText[0].SetMau(color[0].r, color[0].g, color[0].b);
    mnuText[0].HienThi(ttfFont, butVe);

    mnuText[1].SetNoiDung(mnuName[1]);
    mnuText[1].SetMau(color[0].r, color[0].g, color[0].b);
    mnuText[1].HienThi(ttfFont, butVe);


    SDL_Rect pos[kIdx];
    pos[0].x = KICH_THUOC_DO_RONG_MAN * 0.3 - 150;
    pos[0].y = KICH_THUOC_DO_CAO_MAN * 0.8 - 40;
    pos[1].x = KICH_THUOC_DO_RONG_MAN * 0.3 - 150;
    pos[1].y = KICH_THUOC_DO_CAO_MAN * 0.8 + 40;

    DoiTuongCoSo gBackground;
    gBackground.NapHinhAnh(imgFile, butVe);

    SDL_Event event;
    while (true)
    {
        stick = SDL_GetTicks();
        // Vòng lặp lấy chuột
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                mnuText[0].GiaiPhongVungNho();
                mnuText[1].GiaiPhongVungNho();
                gBackground.GiaiPhongDoiTuong();
                return 1;
            case SDL_MOUSEMOTION:
                x = event.motion.x;
                y = event.motion.y;
                for (int i = 0; i < kIdx; ++i)
                {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                        y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        if (!selected[i])
                        {
                            selected[i] = 1;
                            mnuText[i].SetNoiDung(mnuName[i]);
                            mnuText[i].SetMau(color[1].r, color[1].g, color[1].b);
                            mnuText[i].HienThi(ttfFont, butVe);
                        }
                    }
                    else
                    {
                        if (selected[i])
                        {
                            selected[i] = 0;
                            mnuText[i].GiaiPhongVungNho();
                            mnuText[i].SetNoiDung(mnuName[i]);
                            mnuText[i].SetMau(color[0].r, color[0].g, color[0].b);
                            mnuText[i].HienThi(ttfFont, butVe);
                        }
                    }
                }
                break;
            case SDL_MOUSEBUTTONDOWN:
                x = event.button.x;
                y = event.button.y;
                for (int i = 0; i < kIdx; ++i) {
                    if (x >= pos[i].x && x <= pos[i].x + pos[i].w &&
                        y >= pos[i].y && y <= pos[i].y + pos[i].h)
                    {
                        mnuText[0].GiaiPhongVungNho();
                        mnuText[1].GiaiPhongVungNho();
                        gBackground.GiaiPhongDoiTuong();
                        return i;
                    }
                }
                break;
            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE)
                {
                    mnuText[0].GiaiPhongVungNho();
                    mnuText[1].GiaiPhongVungNho();
                    gBackground.GiaiPhongDoiTuong();
                    return 1;
                }
            }
        }

        gBackground.HienThi(butVe, NULL);

        for (int i = 0; i < kIdx; ++i)
        {
            mnuText[i].HienThiChu(butVe, pos[i].x, pos[i].y);
            pos[i].w = mnuText[i].getWidth();
            pos[i].h = mnuText[i].getHeight();
        }


        SDL_RenderPresent(butVe);
        
        int delay = (1000 / 30) - (SDL_GetTicks() - stick);

        if (delay > 0)
            SDL_Delay(delay);
    }

    return 0;
}


int HamDungChung::NgauNhien(int from, int to)
{
    return rand() % (to - from + 1) + from;
}

bool HamDungChung::KiemTraVaCham(const SDL_Rect& toaDoDoiTuongNguon,
    const SDL_Rect& toaDoDoiTuongDich) 
{
  int x = toaDoDoiTuongNguon.x;
  int right_x = toaDoDoiTuongNguon.x + toaDoDoiTuongNguon.w;
  int y = toaDoDoiTuongNguon.y;
  int bottom_y = toaDoDoiTuongNguon.y + toaDoDoiTuongNguon.h;

  int x1 = toaDoDoiTuongDich.x;
  int right_x1 = toaDoDoiTuongDich.x + toaDoDoiTuongDich.w;
  int y1 = toaDoDoiTuongDich.y;
  int bottom_y1 = toaDoDoiTuongDich.y + toaDoDoiTuongDich.h;

  // Trường hợp đối tượng đi qua giữa 2 cột
  if ((x > x1 && x < right_x1)
      && (y > y1 && y < bottom_y1))
        return true;

  if ((x > x1 && x < right_x1) 
        && (bottom_y > y1 && bottom_y < bottom_y1))
      return true;

  if ((right_x > x1 && right_x < right_x1)
        && (y > y1 && y < bottom_y1))
      return true;

  if ((right_x > x1 && right_x < right_x1) 
        && (bottom_y > y1 && bottom_y < bottom_y1))
      return true;

  // Trường hợp đối tượng 1 < đối tượng 2
  if ((x1 > x && x1 < right_x) 
        && (y1 > y && y1 < bottom_y))
      return true;

  if ((x1 > x && x1 < right_x) && (bottom_y1 > y 
        && bottom_y1 < bottom_y))
      return true;

  if ((right_x1 > x && right_x1 < right_x) 
        && (y1 > y && y1 < bottom_y))
      return true;

  if ((right_x1 > x && right_x1 < right_x)
        && (bottom_y1 > y && bottom_y1 < bottom_y))
      return true;

  // Trường hợp đối tượng 1 == đối tượng 2
  if (y == y1 && right_x == right_x1 && bottom_y == bottom_y1)
      return true;

  return false;
}

void HamDungChung::HienThiThongBaoLoi(std::ostream& os,
    const std::string& msg, bool fatal)
{
    os << msg << " Loi : " << SDL_GetError() << std::endl;
    if (fatal) {
        SDL_Quit();
        exit(1);
    }
}

