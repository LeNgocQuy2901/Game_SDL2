
#include "DoiTuongCoSo.h"


DoiTuongCoSo::DoiTuongCoSo()
{
    conTroDoiTuong = NULL;
    toaDoVatThe.x = 0;
    toaDoVatThe.y = 0;
    toaDoVatThe.w = 0;
    toaDoVatThe.h = 0;
}

DoiTuongCoSo::~DoiTuongCoSo()
{
    GiaiPhongDoiTuong();
}

bool DoiTuongCoSo::NapHinhAnh(std::string duongDan, SDL_Renderer* render)
{
    // Giải phóng bộ nhớ đối tượng

    GiaiPhongDoiTuong();
    
    SDL_Texture* currentObject = NULL;

    // Nạp hình ảnh
    SDL_Surface* sf = IMG_Load(duongDan.c_str());

    if (sf != NULL)
    {
        // Thiết lập màu sắc hiển thị trong suốt
        Uint32 key = SDL_MapRGB(sf->format,
                                MAU_TRONG_SUOT_DO,
                                MAU_TRONG_SUOT_XANH_LA,
                                MAU_TRONG_SUOT_XANH_DUONG);
        // Hiển thị trong suốt
        SDL_SetColorKey(sf, SDL_TRUE, key);

        // Hiển thị đường viền

        currentObject = SDL_CreateTextureFromSurface(render, sf);
        
        if (currentObject != NULL)
        {
            // Lấy toạ độ
            toaDoVatThe.w = sf->w;
            toaDoVatThe.h = sf->h;
        }

        // Xoá vật thể cũ
        SDL_FreeSurface(sf);
    }

    conTroDoiTuong = currentObject;
    return conTroDoiTuong != NULL;
}

void DoiTuongCoSo::GiaiPhongDoiTuong()
{
    if (conTroDoiTuong == NULL)
        return;

    SDL_DestroyTexture(conTroDoiTuong);
    conTroDoiTuong = NULL;
    toaDoVatThe.w = 0;
    toaDoVatThe.h = 0;
}

void DoiTuongCoSo::HienThi(SDL_Renderer* render, const SDL_Rect* rect)
{
    SDL_Rect viTri = { 
        toaDoVatThe.x, 
        toaDoVatThe.y, 
        toaDoVatThe.w, 
        toaDoVatThe.h 
    };

    if (rect != NULL)
    {
        viTri.w = rect->w;
        viTri.h = rect->h;
    }

    SDL_RenderCopy(render, conTroDoiTuong, rect, &viTri);
}