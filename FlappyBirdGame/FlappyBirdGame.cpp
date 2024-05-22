
#include "HamDungChung.h"
#include "FlappyBird.h"
#include "DongHo.h"
#include "OngKhoi.h"
#include "KhoiGachKep.h"
#include "QuanLyKhoiGach.h"
#include "QuanLyToaDo.h"


DoiTuongCoSo gAnhNen;
DoiTuongCoSo gNenDat;


TTF_Font* gFontHienThi = NULL;
TTF_Font* gFontMenu = NULL;


// Khởi tạo giao diện đồ hoạ
bool InitSDL(SDL_Window*& khungHienThi, SDL_Renderer*& butVe)
{
    BOOL bKhoiTaoThanhCong = true;

    // Gọi hàm khởi tạo của SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        HamDungChung::HienThiThongBaoLoi(std::cout, "SDL_Init", true);
        return false;
    }

    // Gọi hàm để scale giao diện 
    if (SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1") == SDL_FALSE) {
        HamDungChung::HienThiThongBaoLoi(std::cout, "SDL_SetHint", true);
    }

    // Tạo khung hiển thị
    khungHienThi = SDL_CreateWindow(TIEU_DE_KHUNG_HIEN_THI.c_str(),
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                CHIEU_RONG_KHUNG_HIEN_THI,
                                CHIEU_CAO_KHUNG_HIEN_THI,
                                SDL_WINDOW_OPENGL);

    // Nếu không tạo được khung hiển thị thì báo lỗi và kết thúc
    if (khungHienThi == nullptr) {
        HamDungChung::HienThiThongBaoLoi(std::cout, "SDL_CreateWindow", true);
        return false;
    }

    // Khởi tạo bút vẽ 
    butVe = SDL_CreateRenderer(khungHienThi, -1, SDL_RENDERER_ACCELERATED |
                                                SDL_RENDERER_PRESENTVSYNC);
    // Nếu không khởi tạo được bút vẽ
    if (butVe == NULL) {
        HamDungChung::HienThiThongBaoLoi(std::cout, "SDL_CreateRenderer", true);
        return false;
    }
        
    // Thiết lập màu bút vẽ
    SDL_SetRenderDrawColor(butVe, MAU_BUT_VE, 
                                   MAU_BUT_VE, 
                                   MAU_BUT_VE, 
                                   MAU_BUT_VE);
    
    // Khởi tạo hiển thị ảnh PNG
    if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
        HamDungChung::HienThiThongBaoLoi(std::cout, "IMG_Init", true);
        return false;
    }
 
    // Khởi tạo âm thanh
    if (Mix_OpenAudio(
        TAN_SO_AM_THANH, 
        MIX_DEFAULT_FORMAT, 
        SO_KENH_AM_THANH, 
        KHOI_AM_THANH) != 0)
    {
        HamDungChung::HienThiThongBaoLoi(std::cout, "Mix_OpenAudio", true);
        bKhoiTaoThanhCong = false;
    }


    // Khởi tạo hiển thị Font chữ True Type Font
    if (TTF_Init() != 0)
    {
        HamDungChung::HienThiThongBaoLoi(std::cout, "TTF_Init", true);
        bKhoiTaoThanhCong = false;
    }


    // Khởi tạo font hiển thị
    gFontHienThi = TTF_OpenFont("font//ARCADE.ttf", 38);

    if (gFontHienThi == NULL)
    {
        HamDungChung::HienThiThongBaoLoi(std::cout, "gTextFont_Init", true);
        return false;
    }

    // Khởi tạo font menu
    gFontMenu = TTF_OpenFont("font//ARCADE.ttf", 80);
    
    if (gFontMenu == NULL)
    {
        HamDungChung::HienThiThongBaoLoi(std::cout, "gMNUFont_Init", true);
        return false;
    }
    

    return bKhoiTaoThanhCong;
}


bool NapHinhAnhNen()
{
    bool ret = gAnhNen.NapHinhAnh("img//bkgn.png", gButVe);
    return ret;
}


void close()
{
    gAnhNen.GiaiPhongDoiTuong();
    SDL_DestroyRenderer(gButVe);
    gButVe = NULL;

    SDL_DestroyWindow(gKhungHienThi);
    gKhungHienThi = NULL;

    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{
    if (InitSDL(gKhungHienThi, gButVe) == false)
    {
        return -1;
    }

    DongHo dongHo;

    bool isKetThuc = false;

    // Hiển thị Menu lên màn hình
    int nguoiDungChon = HamDungChung::HienThiMenu(
        gButVe, 
        gFontMenu, 
        "Play ", 
        "Exit ", 
        "img//MENU.png");
    
    if (nguoiDungChon == 1)
        isKetThuc = true;

    if (!NapHinhAnhNen())
    {
        return -1;
    }

    if (!gNenDat.NapHinhAnh("img//ground2.png", gButVe))
        return -1;
    
    // Thiết lập vị trí cho nền đất

    gNenDat.SetToaDo(0, KICH_THUOC_BAN_DO);

nhan_vong_lap:

    // TextBox vòng chơi
    DoiTuongChu txtVongChoi;
    txtVongChoi.SetMauRGB(DoiTuongChu::WHITE_TEXT);

    // Load hình Flappy Bird
    FlappyBird bird;
    
    if (!bird.NapHinhAnh("img//fl_bird.png", gButVe))
        return -1;

    bird.SetToaDo(100, 100);

    QuanLyKhoiGach qlKhoiGach;
    if (!qlKhoiGach.KhoiTaoDanhSachKhoiGach(gButVe))
        return -1;

    while (!isKetThuc)
    {
        dongHo.Chay();

        while (SDL_PollEvent(&gSDLEvent) != 0)
        {
            if (gSDLEvent.type == SDL_QUIT)
            {
                isKetThuc = true;
            }

            bird.XuLySuKienBanPhim(gSDLEvent, gButVe);
        }

        SDL_SetRenderDrawColor(gButVe,
                                MAU_BUT_VE, 
                                MAU_BUT_VE, 
                                MAU_BUT_VE, 
                                MAU_BUT_VE);

        SDL_RenderClear(gButVe);

        gAnhNen.HienThi(gButVe, NULL);

        qlKhoiGach.DatToaDo(bird.LayToaDo());

        bool isDangRoi = bird.LayTrangThaiDangRoi();

        if (isDangRoi)
        {
            qlKhoiGach.SetDungDiChuyen(true);
        }

        qlKhoiGach.ChayChuyenDong(gButVe);

        bool ketThuc = qlKhoiGach.LayTrangThaiCot();
        
        if (ketThuc)
        {
            bird.DatTrangThaiDangRoi(true);
        }

        bird.ThucHienRoiXuong(gButVe);
        bird.HienThi(gButVe);

        // Vẽ vật thể
        DinhDangToaDo kichThuoc(0, 0, CHIEU_RONG_KHUNG_HIEN_THI, 30);
        DuLieuMauSac mauSac(36, 36, 36);
        QuanLyToaDo::VeHinhChuNhat(kichThuoc, mauSac, gButVe);
        // vẽ đường viền
        DinhDangToaDo kichThuocKhung(1, 1, CHIEU_RONG_KHUNG_HIEN_THI - 1, 28);
        DuLieuMauSac mauSacKhung(255, 255, 255);
        QuanLyToaDo::VeDuongVien(kichThuocKhung, mauSacKhung, gButVe);
        // Hiển thị chữ
        int count = qlKhoiGach.LaySoLuongKhoiGach();
        std::string strSLKhoiGach = std::to_string(count);
        txtVongChoi.SetNoiDung(strSLKhoiGach);
        txtVongChoi.HienThi(gFontHienThi, gButVe);
        txtVongChoi.HienThiChu(gButVe, CHIEU_RONG_KHUNG_HIEN_THI*0.5, 2);

        gNenDat.HienThi(gButVe);
        SDL_RenderPresent(gButVe);
        
        // Hiển thị giao diện kết thú trò chơi
        if (bird.DoiTuongBiDie())
        {
            Sleep(500);
            int ret_menu = HamDungChung::HienThiMenu(gButVe, gFontMenu,
                                                   "Player Again", "Exit",
                                                    "img//MENU END.png");
            // Nếu người dùng chọn kết thúc trò chơi
            if (ret_menu == 1)
            {
                isKetThuc = true;
                continue;
            }
            else // Ngược lại tiếp tục màn chơi mới
            {
                isKetThuc = false;
                qlKhoiGach.XoaDanhSachKhoi();
                goto nhan_vong_lap;
            }
        }

        // Thiết lập tỷ lệ khung hình

        int v = dongHo.LayThoiGian();
        
        if (dongHo.LayThoiGian() < 1000 / KHUNG_HINH_HIEN_THI)
        {
            int time = (1000 / KHUNG_HINH_HIEN_THI) - dongHo.LayThoiGian();
            SDL_Delay(time);
        }
    }

    close();
    return 0;
}
