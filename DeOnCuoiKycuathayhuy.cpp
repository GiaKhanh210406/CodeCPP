#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ifstream inFile;
ofstream outFile;

struct SinhVien
{
	string maSV;
	string tenSV;
	int namSinh;
	double diem1, diem2, diem3;

	SinhVien()
	{
		maSV = "Khong co";
		tenSV = "Khong co";
		namSinh = 0;
		diem1 = diem2 = diem3 = 0;
	}

	SinhVien(string ma, string ten, int nam, double d1, double d2, double d3)
	{
		maSV = ma;
		tenSV = ten;
		namSinh = nam;
		diem1 = d1;
		diem2 = d2;
		diem3 = d3;
	}

	double diemTB()
	{
		return (diem1 + diem2 + diem3) / 3;
	}

	void nhapSV()
	{
		cout << "Nhap ma SV: ";
		getline(cin, maSV);
		cout << "Nhap ten SV: ";
		getline(cin, tenSV);
		cout << "Nhap nam sinh: ";
		cin >> namSinh;
		cout << "Nhap diem: ";
		cin >> diem1 >> diem2 >> diem3;
		cin.ignore();
	}

	void xuatSV()
	{
		cout << maSV << " - " << tenSV << " - " << namSinh << " - "
			<< diem1 << ", " << diem2 << ", " << diem3 << endl;
	}

	void ghiSV()
	{
		outFile << maSV << " - " << tenSV << " - " << namSinh << " - "
			<< diem1 << ", " << diem2 << ", " << diem3 << endl;
	}
};

struct LopHoc
{
	SinhVien* sv;  // Cấp phát động mảng SinhVien
	int n;

	LopHoc(int soSinhVien = 40)  // Hàm khởi tạo để cấp phát bộ nhớ động
	{
		sv = new SinhVien[soSinhVien];
		n = soSinhVien;
	}

	~LopHoc()  // Giải phóng bộ nhớ khi đối tượng LopHoc bị hủy
	{
		delete[] sv;
	}

	void docDuLieu()
	{
		inFile.open("data2.txt", ios::in);
		if (!inFile.is_open())
		{
			cerr << "Khong the mo file de doc\n";
			return;
		}

		int sl = 0;
		while (!inFile.eof())
		{
			string s;
			getline(inFile, s);
			if (isdigit(s[0])) // Sinh vien
			{
				char* cs = new char[s.length() + 1]; // +1 vi co ky tu \0
				strcpy(cs, s.c_str());

				char* token = strtok(cs, "-");
				char* arr[6];
				int i = 0;
				while (token != NULL)
				{
					arr[i++] = token;
					token = strtok(NULL, "-");
				}
				SinhVien tmp(arr[0], arr[1], atoi(arr[2]), atof(arr[3]), atof(arr[4]), atof(arr[5]));
				sv[sl] = tmp;
				sl++;
			}
		}

		inFile.close();
	}

	void xuatLop()
	{
		for (int i = 0; i < n; i++)
		{
			cout << "================================\n";
			cout << "SV thu " << i + 1 << ":\n";
			sv[i].xuatSV();
		}
	}

	void timKiem()
	{
		string ten;
		cout << "Nhap ten sv muon tim: ";
		getline(cin, ten);

		for (int i = 0; i < n; i++)
			if (sv[i].tenSV == ten)
				sv[i].xuatSV();
	}

	void xoaSV()
	{
		string ma;
		cout << "Nhap ma sv muon xoa: ";
		getline(cin, ma);

		for (int i = 0; i < n; i++)
			if (sv[i].maSV == ma)
			{
				xoa(i);
				cout << "Xoa thanh cong\n";
				return;
			}
	}

	void xoa(int vt)
	{
		for (int i = vt; i < n - 1; i++)
			sv[i] = sv[i + 1];
		n--;
	}

	void xuatSVtheoDiem()
	{
		double d;
		cout << "Nhap d: ";
		cin >> d;
		for (int i = 0; i < n; i++)
			if (sv[i].diemTB() > d)
				sv[i].xuatSV();
	}

	void swap(SinhVien& a, SinhVien& b)
	{
		SinhVien tmp = a;
		a = b;
		b = tmp;
	}

	void sapXep()
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = i + 1; j < n; j++)
				if (sv[i].diemTB() < sv[j].diemTB())
					swap(sv[i], sv[j]);
	}

	void ghiLop()
	{
		outFile.open("SV.txt", ios::out);
		if (!outFile.is_open())
		{
			cerr << "Khong the mo file\n";
			return;
		}

		for (int i = 0; i < n; i++)
			sv[i].ghiSV();
	}
};

int main()
{
	LopHoc lop1;
	lop1.docDuLieu();
	lop1.xuatLop();
	lop1.ghiLop();
	system("pause");
	return 0;
}
