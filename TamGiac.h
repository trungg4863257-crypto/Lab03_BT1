#pragma once
#ifndef TAMGIAC_H
#define TAMGIAC_H
#include "ToaDo.h"

class TamGiac {
private:
	ToaDo a, b, c;
public:
	void Nhap();
	void Xuat();
	void TinhDoDaiCanh(float &AB, float &AC, float &BC);
	void KiemTraTamGiac();
	float TinhChuVi();
	float TinhDienTich();
	void TinhTien();
	void Quay();
	void PhongTo();
	void ThuNho();
	void VeTamGiac();
};

#endif
