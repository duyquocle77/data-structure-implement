#include <iostream>
using namespace std;

void Nhap(int* mang, int sl);
void Xuat(int* mang, int sl);
void Them(int* mang, int& sl, int vt, int gt);
void Xoa(int* mang, int& sl, int vt);

int main()
{
	int *mang, sl;
	
	do 
	{
		cout << "Nhap so luong phan tu = ";
		cin >> sl;
		
		if(sl <= 0)
			cout << "So luong khong hop le";
	} while (sl <= 0);
	
	mang = new int[sl];
	
	cout << "Nhap mang :\n";
	Nhap(mang, sl);
	
	cout << "Xuat mang :\n";
	Xuat(mang, sl);
	
	int vt, gt;
	cout << "Them phan tu co gia tri :";
	cin >> gt;

	cout << "Them phan tu tai vi tri :";
	cin >> vt;
	
	Them(mang, sl, vt, gt);
	
	cout << "Mang sau khi them :";
	Xuat(mang, sl);
	
	int vtr;

	cout << "Them phan tu tai vi tri :";
	cin >> vtr;
	
	Xoa(mang, sl, vtr);
	
	cout << "Mang sau khi xoa :";
	Xuat(mang, sl);
	
	delete[] mang;
	return 0;
}

void Nhap(int* mang, int sl)
{
	for(int i = 0; i < sl; i++)
	{
		cout << "Nhap phan tu thu [" << i << "] = ";
		cin >> mang[i];
	}
}
void Xuat(int* mang, int sl)
{
	for(int i = 0; i < sl; i++)
	{
		cout << mang[i] << " ";
	}
	cout << endl;
}
void Them(int* mang, int& sl, int vt, int gt)
{
	int *temp = new int[sl];
	for(int i = 0; i < sl; i++)
	{
		temp[i] = mang[i];
	}
	delete[] mang;
	mang = new int[sl + 1];
	for(int i = 0; i < sl; i++)
	{
		mang[i] = temp[i];
	}
	delete[] temp; 
	
	for(int i = sl - 1; i >= vt; i--)
	{
		mang[i + 1] = mang[i];
	}
	mang[vt] = gt;
	sl++;
}
void Xoa(int* mang, int& sl, int vt)
{
	for(int i = vt + 1; i < sl; i++)
	{
		mang[i - 1] = mang[i];
	}
	int *temp = new int[sl];
	for(int i = 0; i < sl; i++)
	{
		temp[i] = mang[i];
	}
	delete[] mang;
	mang = new int[sl - 1];
	for(int i = 0; i < sl; i++)
	{
		mang[i] = temp[i];
	}
	delete[] temp;
	sl--;
}
