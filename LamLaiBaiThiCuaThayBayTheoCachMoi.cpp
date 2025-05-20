#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct NhanVien
{
	string MaSo;
	string Hoten;
	double Luong;
	bool Gioitinh;
};

void sapXeptheoluong(NhanVien *nv, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (nv[i].Luong > nv[j].Luong)
			{
				NhanVien tam = nv[i];
				nv[i] = nv[j];
				nv[j] = tam;
			}
		}
	}
}

string vietHoaChuCaiDauMoiTu(string &s) {
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
	if (!s.empty() && s[0] != ' ') s[0] = toupper(s[0]);
	for (int i = 1; i < s.length(); i++) {
		if (s[i - 1] == ' ' && s[i] != ' ') {
			s[i] = toupper(s[i]);
		}
	}
	return s;
}

void docDulieu(NhanVien *&nv, int &n)
{
	ifstream inFile("data.txt");
	if (!inFile.is_open())
	{
		cout << "Khong mo file thanh cong!" << endl;
		exit(1);
	}

	n = 0;
	string dong;
	while (getline(inFile,dong))
	{
		if (!dong.empty()) n++;
	}
	inFile.close();

	nv = new NhanVien[n];
	inFile.open("data.txt");
	if (!inFile.is_open())
	{
		cout << "Khong mo file thanh cong!" << endl;
		delete[] nv;
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		string gioitinh, luong;

		getline(inFile, nv[i].MaSo, '#');
		getline(inFile, nv[i].Hoten, '#');
		getline(inFile, gioitinh, '#');
		getline(inFile, luong);

		nv[i].Hoten = vietHoaChuCaiDauMoiTu(nv[i].Hoten);
		nv[i].Gioitinh = (gioitinh == "1");
		nv[i].Luong = stod(luong);
	}
	inFile.close();
}

void xuat(NhanVien *nv, int n)
{
	sapXeptheoluong(nv, n);
	cout << "Ma so\tHo ten\t\t\tGioi tinh\tLuong\n";

	for (int i = 0; i < n; i++)
	{
		cout << nv[i].MaSo << "\t" << nv[i].Hoten << "\t\t" << (nv[i].Gioitinh ? "Nam" : "Nu") << "\t\t" << nv[i].Luong << endl;
	}
}

void xuatTheogioitinh(NhanVien *nv, int n)
{
	sapXeptheoluong(nv, n);
	cout << "Danh sach nam: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (nv[i].Gioitinh == 1)
		{
			cout << nv[i].MaSo << "\t" << nv[i].Hoten << "\t\t" << (nv[i].Gioitinh ? "Nam" : "Nu") << "\t\t" << nv[i].Luong << endl;
		}
	}

	cout << "Danh sach nu: " << endl;
	for (int i = 0; i < n; i++)
	{
		if (nv[i].Gioitinh == 0)
		{
			cout << nv[i].MaSo << "\t" << nv[i].Hoten << "\t\t" << (nv[i].Gioitinh ? "Nam" : "Nu") << "\t\t" << nv[i].Luong << endl;
		}
	}
}

void xoaTheoluong(NhanVien *& nv, int &n, double &x)
{
	do
	{
		cout << "Nhap muc luong can xoa: ";
		cin >> x;
		if (x <= 0)
			cout << "Luong can xoa khong hop le! Nhap lai: " << endl;
	} while (x <= 0);

	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (nv[i].Luong == x)
		{
			for (int j = i; j < n-1; j++)
			{
				nv[j] = nv[j + 1];
			}
			n--;
			dem++;
		}
	}

	if (dem == 0) {
		cout << "Khong tim thay muc luong de xoa!\n";
	}
	else {
		cout << "Danh sach sau khi xoa cac nhan vien co luong = " << x << ":\n";
		xuat(nv, n);
	}
}
int main()
{
	NhanVien *nv;
	int n;
	//Chuc nang 1:
	docDulieu(nv, n);
	xuat(nv, n);

	//Chuc nang 2:
	xuatTheogioitinh(nv, n);

	//Chuc nang 3:
	double x;
	xoaTheoluong(nv, n, x);

	delete[] nv;
	nv = nullptr;
	return 0;
}