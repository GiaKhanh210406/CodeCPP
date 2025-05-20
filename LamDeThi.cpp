#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

struct MonHoc
{
	char MaMonHoc[7];
	string TenMonHoc;
	char KhoaMon[20];
	int TinChi;
	double DonGia;
	double hocPhi;
};

void docDuLieu(MonHoc*& mh, int& n)
{
	ifstream inFile("data3.txt");
	if (!inFile)
	{
		cout << "Khong mo file thanh cong!" << endl;
		exit(1);
	}

	n = 0;
	string dong;
	while (getline(inFile, dong))
	{
		if (!dong.empty())
			n++;
	}
	inFile.close();

	mh = new MonHoc[n];

	inFile.open("data3.txt");
	if (!inFile)
	{
		cout << "Không mở lại file thành công!" << endl;
		delete[] mh;
		exit(1);
	}

	for (int i = 0; i < n; i++)
	{
		string tinChi, donGia, maMonHoc, khoaMon;

	
		getline(inFile, maMonHoc, '#');
		strcpy(mh[i].MaMonHoc, maMonHoc.c_str());

		getline(inFile, mh[i].TenMonHoc, '#');

		getline(inFile, khoaMon, '#');
		strcpy(mh[i].KhoaMon, khoaMon.c_str());

		getline(inFile, tinChi, '#');
		getline(inFile, donGia);

		mh[i].TinChi = stoi(tinChi);
		mh[i].DonGia = stod(donGia);
	}
	inFile.close();
}

void xuatThongtin(MonHoc* mh, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << mh[i].MaMonHoc << "#" << mh[i].TenMonHoc << "#" << mh[i].KhoaMon << "#" << mh[i].TinChi << "#" << mh[i].DonGia << endl;
	}
}

void timKiemtheohocphi(MonHoc *mh, int n)
{
	int x, dem = 0;
	do
	{
		cout << "Nhap hoc phi muon loc: ";
		cin >> x;
		if (x <= 0)
			cout << "Hoc phi khong hop le! Nhap lai: " << endl;
	} while (x <= 0);

	for (int i = 0; i < n; i++)
	{
		if (mh[i].DonGia == x)
		{
			dem++;
			cout << mh[i].MaMonHoc << "#" << mh[i].TenMonHoc << "#" << mh[i].KhoaMon << "#" << mh[i].TinChi << "#" << mh[i].DonGia << endl;
		}
	}
	if (dem == 0)
		cout << "Khong tim thay hoc phi! Vui long kiem tra lai!" << endl;
}

void timKiemtheomamonhoc(MonHoc *mh, int n)
{
	string ma;
	int dem = 0;
	cout << "Nhap ma mon hoc muon loc: ";
	cin.ignore();
	getline(cin, ma);
	
	for (int i = 0; i < n; i++)
	{
		if (strcmp(mh[i].MaMonHoc,ma.c_str()) == 0)
		{
			dem++;
			cout << mh[i].MaMonHoc << "#" << mh[i].TenMonHoc << "#" << mh[i].KhoaMon << "#" << mh[i].TinChi << "#" << mh[i].DonGia << endl;
		}
	}
	if (dem == 0)
		cout << "Khong tim thay ma mon hoc! Vui long kiem tra lai!" << endl;
}

void timKiemtheotenmonhoc(MonHoc *mh, int n)
{
	string ten;
	int dem = 0;
	cout << "Nhap ten muon hoc muon loc: ";
	getline(cin, ten);

	for (int i = 0; i < n; i++)
	{
		if (mh[i].TenMonHoc == ten)
		{
			dem++;
			cout << mh[i].MaMonHoc << "#" << mh[i].TenMonHoc << "#" << mh[i].KhoaMon << "#" << mh[i].TinChi << "#" << mh[i].DonGia << endl;
		}
	}
	if (dem == 0)
		cout << "Khong tim thay ten mon hoc! Vui long kiem tra lai!" << endl;
}

void timKiemtheokhoamon(MonHoc *mh, int n)
{
	string khoa;
	int dem = 0;
	cout << "Nhap ten khoa muon loc: ";
	getline(cin, khoa);

	for (int i = 0; i < n; i++)
	{
		if (mh[i].KhoaMon == khoa)
		{
			dem++;
			cout << mh[i].MaMonHoc << "#" << mh[i].TenMonHoc << "#" << mh[i].KhoaMon << "#" << mh[i].TinChi << "#" << mh[i].DonGia << endl;
		}
	}

	if (dem == 0)
		cout << "Khong tim thay khoa! Vui long kiem tra lai!" << endl;
}

void timKiemtheotinchi(MonHoc *mh, int n)
{
	int tc, dem = 0;
	do
	{
		cout << "Nhap so tin chi muon loc: ";
		cin >> tc;
		if (tc <= 0)
			cout << "So tin chi khong hop le! Vui long kiem tra lai!" << endl;
	} while (tc <= 0);

	for (int i = 0; i < n; i++)
	{
		if (mh[i].TinChi == tc)
		{
			dem++;
			cout << mh[i].MaMonHoc << "#" << mh[i].TenMonHoc << "#" << mh[i].KhoaMon << "#" << mh[i].TinChi << "#" << mh[i].DonGia << endl;
		}
	}

	if (dem == 0)
		cout << "Khong tim thay tin chi hop le! Vui long kiem tra lai!" << endl;
}

void timKiemtheodongia(MonHoc *mh, int n)
{
	double dg, dem = 0;
	do
	{
		cout << "Nhap don gia muon loc: ";
		cin >> dg;
		if (dg <= 0)
			cout << "Khong tim thay don gia hop le! Vui long kiem tra lai!" << endl;
	} while (dg <= 0);

	for (int i = 0; i < n; i++)
	{
		if (mh[i].DonGia == dg)
		{
			dem++;
			cout << mh[i].MaMonHoc << "#" << mh[i].TenMonHoc << "#" << mh[i].KhoaMon << "#" << mh[i].TinChi << "#" << mh[i].DonGia << endl;
		}
	}

	if (dem == 0)
		cout << "Khong tim thay don gia hop le! Vui long kiem tra lai!" << endl;
}

double tongHocPhi_DeQuy(MonHoc* mh, int n)
{
	if (n == 0)
		return 0;
	return mh[n - 1].TinChi * mh[n - 1].DonGia + tongHocPhi_DeQuy(mh, n - 1);
}

double HocPhiTrungBinh(MonHoc *ds, int n)\
{
	double tong = tongHocPhi_DeQuy(ds, n);
	return (n == 0) ? 0 : tong / n;
}

double tinhHocphitungmon(MonHoc mh, int n)
{
	return mh.TinChi * mh.DonGia;
}

int main()
{
	MonHoc* mh;
	int n;

	docDuLieu(mh, n);
	cout << "===DANH SACH MON DOC DUOC TU FILE DU LIEU===" << endl;
	xuatThongtin(mh, n);
	/*
	cout << "+ Danh sach mon hoc loc theo hoc phi la: " << endl;
	timKiemtheohocphi(mh, n);
	
	cout << "+ Danh sach mon loc theo ma mon hoc la: " << endl;
	timKiemtheomamonhoc(mh, n);
	
	cout << "+ Danh sach mon loc theo ten mon hoc la: " << endl;
	timKiemtheotenmonhoc(mh, n);

	cout << "+ Danh sach mon loc theo khoa mon la: " << endl;
	timKiemtheokhoamon(mh, n);

	cout << "+ Danh sach mon loc theo so tin chi la: " << endl;
	timKiemtheotinchi(mh, n);

	cout << "+ Danh sach mon loc theo don gia: " << endl;
	timKiemtheodongia(mh, n);
	*/

	double x = tongHocPhi_DeQuy(mh, n);
	cout << fixed << setprecision(2); // in 2 chữ số thập phân, có thể điều chỉnh
	cout << "Tong hoc phi cua tat ca mon hoc la: " << x << endl;

	cout << "Hoc phi trung binh cua ban la: " << HocPhiTrungBinh(mh, n) << endl;
	delete[] mh;
	mh = nullptr;

	return 0;
}
