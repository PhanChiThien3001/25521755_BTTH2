#include <iostream>
#include <iomanip>
using namespace std;
class GioPhutGiay {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    void Nhap();
    void Xuat();
    GioPhutGiay TinhCongThemMotGiay();
};
void GioPhutGiay::Nhap() {
    do {
        cout << "Nhap gio (0-23): "; cin >> iGio;
        cout << "Nhap phut (0-59): "; cin >> iPhut;
        cout << "Nhap giay (0-59): "; cin >> iGiay;
    } while (iGio < 0 || iGio > 23 || iPhut < 0 || iPhut > 59 || iGiay < 0 || iGiay > 59);
}

void GioPhutGiay::Xuat() {
    cout << setfill('0') << setw(2) << iGio << ":"
         << setfill('0') << setw(2) << iPhut << ":"
         << setfill('0') << setw(2) << iGiay;
}

GioPhutGiay GioPhutGiay::TinhCongThemMotGiay() {
    GioPhutGiay kq = *this;
    kq.iGiay++;
    if (kq.iGiay > 59) {
        kq.iGiay = 0;
        kq.iPhut++;
        if (kq.iPhut > 59) {
            kq.iPhut = 0;
            kq.iGio++;
            if (kq.iGio > 23) {
                kq.iGio = 0;
            }
        }
    }
    return kq;
}
int main() {
    GioPhutGiay time;
    cout << "--- Nhap thong tin thoi gian ---\n";
    time.Nhap();

    cout << "\nThoi gian hien tai: ";
    time.Xuat();

    GioPhutGiay nextTime = time.TinhCongThemMotGiay();
    cout << "\nThoi gian sau 1 giay: ";
    nextTime.Xuat();
    cout << endl;

    return 0;
}
