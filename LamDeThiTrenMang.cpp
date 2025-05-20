#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX = 50;

struct SanPham
{
	char maSP[5];
	char tenSP[100];
	int soLuong;
	double donGia;
	char phanLoai[100];
};

void nhap1SP(SanPham &sp)
{
	cout << "Nhap ma san pham: ";
	cin.getline(sp.maSP, 5);
	cout << "Nhap ten cua san pham: ";
	cin.getline(sp.tenSP, 100);
	cout << "Nhap so luong cua san pham: ";
	cin >> sp.soLuong;
	cout << "Nhap don gia cua san pham: ";
	cin >> sp.donGia;
	cin.ignore();
	cout << "Nhap phan loai cua san pham: ";
	cin.getline(sp.phanLoai, 100);
}

void xuat1SP(SanPham sp)
{
	cout << "Ma san pham la: " << sp.maSP << endl;
	cout << "Ten cua san pham la: " << sp.tenSP << endl;
	cout << "So luong cua san pham: " << sp.soLuong << endl;
	cout << "Don gia cua san pham la: " << sp.donGia << endl;
	cout << "Phan loai cua san pham: " << sp.phanLoai << endl;
}

void nhapDanhsachSP(SanPham *&sp, int &n)
{
	do
	{
		cout << "Nhap so luong san pham ( toi da " << MAX << " san pham ): ";
		cin >> n;
		cin.ignore();
		if (n <= 0 || n > MAX)
			cout << "So luong san pham khong hop le! Nhap lai: " << endl;
	} while (n <= 0 || n > MAX);

	sp = new SanPham[n];

	for (int i = 0; i < n; i++)
	{
		cout << "+ Nhap thong tin cua san pham thu " << i + 1 << " : " << endl;
		nhap1SP(sp[i]);
	}
}

void xuatDanhsachSP(SanPham *sp, int n)
{
	cout << "===Danh sach san pham===" << endl;
	for (int i = 0; i < n; i++)
	{
		xuat1SP(sp[i]);
	}
}

void locSP(SanPham *sp, int n)
{
	cout << "+ Danh sach san pham phan loai theo vat dung la: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (strcmp(sp[i].phanLoai, "Vat dung") == 0)
		{
			xuat1SP(sp[i]);
		}
	}
}

int demSP(SanPham *sp, int n)
{
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (strstr(sp[i].tenSP, "an") != NULL)
		{
			dem++;
		}
	}
	

	if (dem == 0)
	{
		cout << "Khong co san pham nao chua chuoi 'an' trong danh sach san pham!" << endl;
	}
	return dem;
}

void ghiSP(SanPham *sp, int n)
{
	ofstream outFile("BT.txt",ios::app);
	if (!outFile.is_open())
	{
		cout << "Ghi file khong thanh cong!" << endl;
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		if (strcmp(sp[i].phanLoai, "Vat dung") == 0)
		{
			outFile << "Ma san pham la: " << sp[i].maSP << endl;
			outFile << "Ten cua san pham la: " << sp[i].tenSP << endl;
			outFile << "So luong cua san pham: " << sp[i].soLuong << endl;
			outFile << "Don gia cua san pham la: " << sp[i].donGia << endl;
			outFile << "Phan loai cua san pham: " << sp[i].phanLoai << endl;
		}
	}

	cout << "Da ghi file thanh cong.Vui long kiem tra ket qua!" << endl;
	outFile.close();
}

double tongVon(SanPham *sp, int n)
{
	double a;
	for (int i = 0; i < n; i++)
	{
		a = sp[i].donGia * sp[i].soLuong;
	}
	return a;
}
int main()
{
	SanPham *sp;
	int n;

	nhapDanhsachSP(sp, n);
	xuatDanhsachSP(sp, n);

	/*locSP(sp, n);

	int x = demSP(sp, n);
	cout << "So san pham chua chuoi 'an' trong danh sach la: " << x << endl;

	ghiSP(sp, n);
	*/
	double y = tongVon(sp, n);
	cout << "Tong von can bo ra la: " << y << endl;

	delete[]sp;
	sp = nullptr;
	return 0;
}