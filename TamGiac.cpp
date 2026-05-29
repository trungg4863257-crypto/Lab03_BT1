#include <iostream>
#include <cmath>
#include <windows.h>
#include "TamGiac.h"
using namespace std;

/*
ham nhap toa do cac diem cua tam giac
input: toa do hoanh va tung cua 3 diem A, B, C
*/
void TamGiac::Nhap() {
	cout << "Nhap toa do diem A(x, y): ";
	cin >> a.iHoanh >> a.iTung;
	cout << "Nhap toa do diem B(x, y): ";
	cin >> b.iHoanh >> b.iTung;
	cout << "Nhap toa do diem C(x, y): ";
	cin >> c.iHoanh >> c.iTung;
}

/*
ham xuat toa do cac diem cua tam giac
output: toa do hoanh va tung cua 3 diem A, B, C
*/
void TamGiac::Xuat() {
	cout << "Toa do diem A: (" << a.iHoanh << ", " << a.iTung << ")" << endl;
	cout << "Toa do diem B: (" << b.iHoanh << ", " << b.iTung << ")" << endl;
	cout << "Toa do diem C: (" << c.iHoanh << ", " << c.iTung << ")" << endl;
}

/*
ham tinh do dai cac canh cua tam giac
output: do dai canh AB, AC, BC
*/
void TamGiac::TinhDoDaiCanh(float& AB, float& AC, float& BC) {
	AB = sqrt(pow(b.iHoanh - a.iHoanh, 2) + pow(b.iTung - a.iTung, 2));
	AC = sqrt(pow(c.iHoanh - a.iHoanh, 2) + pow(c.iTung - a.iTung, 2));
	BC = sqrt(pow(c.iHoanh - b.iHoanh, 2) + pow(c.iTung - b.iTung, 2));
	cout << "Do dai canh AB: " << AB << endl;
	cout << "Do dai canh AC: " << AC << endl;
	cout << "Do dai canh BC: " << BC << endl;
}

/*
ham kiem tra loai tam giac
output: loai tam giac (deu, can, vuong, thuong)
*/
void TamGiac::KiemTraTamGiac() {

	float AB, AC, BC;
	TinhDoDaiCanh(AB, AC, BC);

	if (AB + AC > BC && AB + BC > AC && AC + BC > AB) {
		if (AB == AC && AC == BC) {
			cout << "Tam giac deu." << endl;
		}
		else if (AB == AC || AB == BC || AC == BC) {
			cout << "Tam giac can." << endl;
		}
		else if (pow(AB, 2) == pow(AC, 2) + pow(BC, 2) ||
			pow(AC, 2) == pow(AB, 2) + pow(BC, 2) ||
			pow(BC, 2) == pow(AB, 2) + pow(AC, 2)) {
			cout << "Tam giac vuong." << endl;
		}
		else {
			cout << "Tam giac thuong." << endl;
		}
	}
	else {
		cout << "Ba diem A, B, C khong tao thanh tam giac." << endl;
	}
}

/*
ham tinh chu vi tam giac
output: chu vi tam giac
*/
float TamGiac::TinhChuVi() {

	float AB, AC, BC;
	TinhDoDaiCanh(AB, AC, BC);

	float chuVi = AB + AC + BC;
	cout << "Chu vi tam giac: " << chuVi << endl;
	return chuVi;
}

/*
ham tinh dien tich tam giac su dung cong thuc Heron
output: dien tich tam giac
*/
float TamGiac::TinhDienTich() {

	float AB, AC, BC;
	TinhDoDaiCanh(AB, AC, BC);

	float p = (AB + AC + BC) / 2;
	float dienTich = sqrt(p * (p - AB) * (p - AC) * (p - BC));

	cout << "Dien tich tam giac: " << dienTich << endl;
	return dienTich;
}

/*
ham tinh tien tam giac
input: dx, dy (khoang cach tinh tien theo truc hoanh va truc tung)
output: toa do moi cua 3 diem A, B, C sau khi tinh tien
*/
void TamGiac::TinhTien() {
	cout << "Nhap khoang cach tinh tien (dx, dy): ";
	float dx, dy;
	cin >> dx >> dy;
	a.iHoanh += dx;
	a.iTung += dy;
	b.iHoanh += dx;
	b.iTung += dy;
	c.iHoanh += dx;
	c.iTung += dy;
	cout << "Toa do diem A sau khi tinh tien: (" << a.iHoanh << ", " << a.iTung << ")" << endl;
	cout << "Toa do diem B sau khi tinh tien: (" << b.iHoanh << ", " << b.iTung << ")" << endl;
	cout << "Toa do diem C sau khi tinh tien: (" << c.iHoanh << ", " << c.iTung << ")" << endl;
}

/*
ham quay tam giac quanh goc toa do O(0, 0) mot goc alpha
input: alpha (goc quay theo do)
output: toa do moi cua 3 diem A, B, C sau khi quay
*/
void TamGiac::Quay() {
	float angle;
	cout << "Nhap goc quay (do): ";
	cin >> angle;

	float rad = angle * 3.14159265 / 180;

	auto rotate = [&](ToaDo& p) {
		float x = p.iHoanh;
		float y = p.iTung;

		p.iHoanh = x * cos(rad) - y * sin(rad);
		p.iTung = x * sin(rad) + y * cos(rad);
		};

	rotate(a);
	rotate(b);
	rotate(c);
}

/*
ham phong to tam giac
input: k (he so phong to)
output: toa do moi cua 3 diem A, B, C sau khi phong to
*/
void TamGiac::PhongTo() {
	cout << "Nhap he so phong to: ";
	float k;
	cin >> k;
	a.iHoanh *= k;
	a.iTung *= k;
	b.iHoanh *= k;
	b.iTung *= k;
	c.iHoanh *= k;
	c.iTung *= k;
	cout << "Toa do diem A sau khi phong to: (" << a.iHoanh << ", " << a.iTung << ")" << endl;
	cout << "Toa do diem B sau khi phong to: (" << b.iHoanh << ", " << b.iTung << ")" << endl;
	cout << "Toa do diem C sau khi phong to: (" << c.iHoanh << ", " << c.iTung << ")" << endl;
}

/*
ham thu nho tam giac
input: k (he so thu nho)
output: toa do moi cua 3 diem A, B, C sau khi thu nho
*/
void TamGiac::ThuNho() {
	cout << "Nhap he so thu nho: ";
	float k;
	cin >> k;
	a.iHoanh /= k;
	a.iTung /= k;
	b.iHoanh /= k;
	b.iTung /= k;
	c.iHoanh /= k;
	c.iTung /= k;
	cout << "Toa do diem A sau khi thu nho: (" << a.iHoanh << ", " << a.iTung << ")" << endl;
	cout << "Toa do diem B sau khi thu nho: (" << b.iHoanh << ", " << b.iTung << ")" << endl;
	cout << "Toa do diem C sau khi thu nho: (" << c.iHoanh << ", " << c.iTung << ")" << endl;
}

/*
ham ve tam giac su dung thu vien windows.h
output: hinh
*/
void TamGiac::VeTamGiac() {
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);

	// scale + dời gốc về giữa màn hình
	int ox = 400;
	int oy = 300;
	int scale = 1;

	POINT p[3];

	p[0].x = ox + a.iHoanh * scale;
	p[0].y = oy - a.iTung * scale;

	p[1].x = ox + b.iHoanh * scale;
	p[1].y = oy - b.iTung * scale;

	p[2].x = ox + c.iHoanh * scale;
	p[2].y = oy - c.iTung * scale;

	// vẽ tam giác
	MoveToEx(hdc, p[0].x, p[0].y, NULL);
	LineTo(hdc, p[1].x, p[1].y);
	LineTo(hdc, p[2].x, p[2].y);
	LineTo(hdc, p[0].x, p[0].y);

	ReleaseDC(hwnd, hdc);
	Sleep(3000);
}
