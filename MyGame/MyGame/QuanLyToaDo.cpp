

#include "QuanLyToaDo.h"

void QuanLyToaDo::VeHinhChuNhat(const DinhDangToaDo& size
    , const DuLieuMauSac& color, SDL_Renderer* screen)
{
    SDL_Rect fillRect = {size.Left, size.Top, size.Width, size.Height};
    SDL_SetRenderDrawColor(screen, color.R, color.G, color.B, 0xFF);        
    SDL_RenderFillRect(screen, &fillRect );
}

void QuanLyToaDo::VeDuongVien(const DinhDangToaDo& size
    , const DuLieuMauSac& color, SDL_Renderer* screen)
{
    SDL_Rect outlineRect = {size.Left, size.Top, size.Width, size.Height};
    SDL_SetRenderDrawColor(screen, color.R, color.G, color.B, 0xFF);
    SDL_RenderDrawRect(screen, &outlineRect );
}