#include<iostream>
using namespace std;
class PhanSo {
private: double tuso;
	   double mauso;
public:
	PhanSo() {
	}
	~PhanSo() {

	}
	PhanSo(double tuso, double mauso) {
		this->mauso = mauso;
		this->tuso = tuso;
	}
	PhanSo Nhan(PhanSo a, PhanSo b) {
		PhanSo temp;
		temp.tuso = a.tuso * b.tuso;
		temp.mauso = a.mauso * b.mauso;
		return temp;
	}
	void nhap() {
		cout << "Nhap phan so: ";
		cin >> tuso >> mauso;
	}
	void xuat() {
		cout << "Phan so:" <<  tuso << "/" << mauso<<endl;
	}
};
int main() {
	int n;
	cin >> n;
	PhanSo a[1000];
	PhanSo tich = PhanSo(1,1);
	for (int i = 0; i < n; i++) {
		a[i].nhap();
	}
	for (int i = 0; i < n; i++) {
		tich = tich.Nhan(tich,a[i]);
	}
	tich.xuat();
}