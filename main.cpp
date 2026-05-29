#include <iostream>
#include <windows.h>
#include "TamGiac.h"
using namespace std;

int main() {
	TamGiac tamgiac;

	// nhập + xuất
	tamgiac.Nhap();
	tamgiac.Xuat();

	// kiểm tra tam giác
	tamgiac.KiemTraTamGiac();

	// chu vi + diện tích
	tamgiac.TinhChuVi();
	tamgiac.TinhDienTich();

	// biến đổi hình
	tamgiac.TinhTien();
	tamgiac.Xuat();

	tamgiac.Quay();
	tamgiac.Xuat();

	tamgiac.PhongTo();
	tamgiac.Xuat();

	tamgiac.ThuNho();
	tamgiac.Xuat();

	// vẽ (nếu có)
	tamgiac.VeTamGiac();

	return 0;
}
