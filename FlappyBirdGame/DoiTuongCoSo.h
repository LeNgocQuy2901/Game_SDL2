#ifndef DOI_TUONG_CO_SO_H_
#define DOI_TUONG_CO_SO_H_

#include "HamDungChung.h"

class DoiTuongCoSo
{
public:
	DoiTuongCoSo();
	~DoiTuongCoSo();
	virtual bool NapHinhAnh(std::string path, SDL_Renderer* screen);
	void HienThi(SDL_Renderer* des, const SDL_Rect* clip = NULL);

	void GiaiPhongDoiTuong();
	void SetToaDo(const int& x, const int& y) { toaDoVatThe.x = x, toaDoVatThe.y = y; };
	SDL_Rect LayToaDo() const { return toaDoVatThe; }
	SDL_Texture* GetObject() { return conTroDoiTuong; }
protected:
	SDL_Texture* conTroDoiTuong;
	SDL_Rect toaDoVatThe;
};


#endif
