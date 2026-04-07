#include <iostream>
#include <iomanip>
using namespace std;
class SoPhuc {
private:
    double iThuc;
    double iAo;

public:
    void Nhap();
    void Xuat();
    SoPhuc Tong(SoPhuc sp);
    SoPhuc Hieu(SoPhuc sp);
    SoPhuc Tich(SoPhuc sp);
    SoPhuc Thuong(SoPhuc sp);
};
void SoPhuc::Nhap() {
    cout << "Nhap phan thuc: "; cin >> iThuc;
    cout << "Nhap phan ao: "; cin >> iAo;
}
void SoPhuc::Xuat() {
    if (iAo >= 0)
        cout << iThuc << " + " << iAo << "i";
    else
        cout << iThuc << " - " << -iAo << "i";
}
SoPhuc SoPhuc::Tong(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc + sp.iThuc;
    kq.iAo = iAo + sp.iAo;
    return kq;
}
SoPhuc SoPhuc::Hieu(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc - sp.iThuc;
    kq.iAo = iAo - sp.iAo;
    return kq;
}
SoPhuc SoPhuc::Tich(SoPhuc sp) {
    SoPhuc kq;
    kq.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
    kq.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
    return kq;
}
SoPhuc SoPhuc::Thuong(SoPhuc sp) {
    SoPhuc kq;
    double mau = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
    if (mau != 0) {
        kq.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / mau;
        kq.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / mau;
    } else {
        cout << "Loi chia cho 0!" << endl;
        kq.iThuc = 0; kq.iAo = 0;
    }
    return kq;
}
int main() {
    SoPhuc sp1, sp2;
    cout << "Nhap so phuc 1:\n";
    sp1.Nhap();
    cout << "Nhap so phuc 2:\n";
    sp2.Nhap();

    cout << "\nSo phuc 1: "; sp1.Xuat();
    cout << "\nSo phuc 2: "; sp2.Xuat();

    SoPhuc tong = sp1.Tong(sp2);
    SoPhuc hieu = sp1.Hieu(sp2);
    SoPhuc tich = sp1.Tich(sp2);
    SoPhuc thuong = sp1.Thuong(sp2);

    cout << "\n\nTong: "; tong.Xuat();
    cout << "\nHieu: "; hieu.Xuat();
    cout << "\nTich: "; tich.Xuat();
    cout << "\nThuong: "; thuong.Xuat();
    cout << endl;

    return 0;
}
