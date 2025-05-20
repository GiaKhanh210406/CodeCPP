#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct NhanVien
{
	string maSo;
	string hoTen;
	int tuoi;
	int namLam;
};

void docDulieu(NhanVien *&nv, int &n)
{
	ifstream inFile("data.txt");
	if (!inFile.is_open())
	{
		cout << "Khong mo file thanh cong!" << endl;
		exit(1);
	}

	inFile >> n;
	inFile.ignore();

	nv = new NhanVien[n];
	string tuoi, namlam;
	for (int i = 0; i < n; i++)
	{
		getline(inFile, nv[i].maSo, '#');
		getline(inFile, nv[i].hoTen, '#');
		getline(inFile, tuoi, '#');
		getline(inFile, namlam);

		nv[i].tuoi = stoi(tuoi);
		nv[i].namLam = stoi(namlam);
	}

	cout << "Da doc file thanh cong!Vui long kiem tra thong tin!" << endl;
	inFile.close();
}

void xuat1nv(NhanVien nv)
{
	cout << "Ma nhan vien la: " << nv.maSo << endl;
	cout << "Ho va ten cua nhan vien la: " << nv.hoTen << endl;
	cout << "Tuoi cua nhan vien la: " << nv.tuoi << endl;
	cout << "Nam vao lam cua nhan vien la: " << nv.namLam << endl;
}
void xuat(NhanVien *nv, int n)
{
	
	for (int i = 0; i < n; i++)
	{
		xuat1nv(nv[i]);
	}
}

void timKiemtheomanv(NhanVien *nv, int n)
{
	string ma;
	cout << "Nhap ma nhan vien can tim kiem: ";
	getline(cin, ma);
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (nv[i].maSo == ma)
		{
			xuat1nv(nv[i]);
			dem++;
		}
	}

	if (dem == 0)
	{
		cout << "Khong tim thay ma nhan vien trong danh sach!Vui long kiem tra lai!" << endl;
	}
}

void sapXeptheotuoi(NhanVien *nv, int n)
{
	for (int i = 0; i < n-1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (nv[i].tuoi > nv[j].tuoi)
			{
				NhanVien tam = nv[i];
				nv[i] = nv[j];
				nv[j] = tam;
			}
		}
	}
}

void suaThongtinnv(NhanVien *&nv, int &n)
{
	string manv;
	cout << "Nhap ma nhan vien can sua thong tin: ";
	getline(cin, manv);

	bool check = false;
	for (int i = 0; i < n; i++)
	{
		if (nv[i].maSo == manv)
		{
			cout << "Nhap ho va ten moi cua nhan vien: ";
			getline(cin, nv[i].hoTen);
			cout << "Nhap tuoi moi cua nhan vien: ";
			cin >> nv[i].tuoi;
			cout << "Nhap nam vao lam moi cua nhan vien: ";
			cin >> nv[i].namLam;
			cin.ignore(); 
			check = true;

			cout << "+ Da sua thong tin thanh cong. Thong tin moi cua nhan vien:" << endl;
			xuat1nv(nv[i]);
			break; 
		}
	}

	if (!check)
	{
		cout << "Khong tim thay ma nhan vien de sua thong tin! Vui long kiem tra lai!" << endl;
	}
}

void xoaNvtheotuoi(NhanVien *&nv, int &n)
{
	int x;
	do
	{
		cout << "Nhap tuoi can xoa: ";
		cin >> x;
		if (x <= 0)
			cout << "Tuoi khong hop le! Nhap lai: " << endl;
	} while (x <= 0);
	int dem = 0;
	for (int i = 0; i < n; i++)
	{
		if (nv[i].tuoi == x)
		{
			for (int j = i; j < n - 1; j++)
			{
				nv[j] = nv[j + 1];
			}
			n--;
			dem++;
		}
	}

	if (dem == 0)
	{
		cout << "Khong tim thay tuoi de xoa! Vui long kiem tra lai!" << endl;
	}
}
int main()
{
	NhanVien *nv;
	int n;

	docDulieu(nv, n);
	cout << "===Danh sach nhan vien doc duoc===" << endl;
	xuat(nv, n);

	/*timKiemtheomanv(nv, n);

	cout << "+ Danh sach nhan vien sap xep theo tuoi tang dan la: " << endl;
	sapXeptheotuoi(nv, n);
	xuat(nv, n);

	suaThongtinnv(nv, n);
	*/

	xoaNvtheotuoi(nv, n);
	cout << "+ Danh sach nhan vien sau khi xoa tuoi la: " << endl;
	xuat(nv, n);
	delete[]nv;
	nv = nullptr;

	return 0;
}