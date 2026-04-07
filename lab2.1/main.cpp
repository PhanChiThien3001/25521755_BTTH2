#include <iostream>
#include <iomanip>
using namespace std;
class NgayThangNam {
private:
    int iNgay;
    int iThang;
    int iNam;

public:
    void Nhap();
    void Xuat();
    bool KiemTraNamNhuan();
    int SoNgayTrongThang();
    NgayThangNam NgayThangNamTiepTheo();
};
void NgayThangNam::Nhap() {
    cout << "Nhap ngay: "; cin >> iNgay;
    cout << "Nhap thang: "; cin >> iThang;
    cout << "Nhap nam: "; cin >> iNam;
}

void NgayThangNam::Xuat() {
    cout << iNgay << "/" << iThang << "/" << iNam;
}

bool NgayThangNam::KiemTraNamNhuan() {
    return (iNam % 4 == 0 && iNam % 100 != 0) || (iNam % 400 == 0);
}

int NgayThangNam::SoNgayTrongThang() {
    int ngayTrongThang[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (iThang == 2 && KiemTraNamNhuan()) {
        return 29;
    }
    return ngayTrongThang[iThang];
}

NgayThangNam NgayThangNam::NgayThangNamTiepTheo() {
    NgayThangNam ngayTiepTheo = *this;
    ngayTiepTheo.iNgay++;

    if (ngayTiepTheo.iNgay > ngayTiepTheo.SoNgayTrongThang()) {
        ngayTiepTheo.iNgay = 1;
        ngayTiepTheo.iThang++;
        if (ngayTiepTheo.iThang > 12) {
            ngayTiepTheo.iThang = 1;
            ngayTiepTheo.iNam++;
        }
    }
    return ngayTiepTheo;
}
int main() {
    NgayThangNam date;
    cout << "--- Nhap thong tin Ngay Thang Nam ---\n";
    date.Nhap();

    cout << "\nNgay hien tai: ";
    date.Xuat();

    NgayThangNam nextDate = date.NgayThangNamTiepTheo();
    cout << "\nNgay tiep theo: ";
    nextDate.Xuat();
    cout << endl;

    return 0;
}
