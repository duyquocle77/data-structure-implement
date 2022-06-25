#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void Nhap(int* mang, int sl);
void Xuat(int* mang, int sl);
void Them(int* mang, int* sl, int vt, int gt);
void Xoa(int* mang, int* sl, int vt);

int main()
{
	int *mang, sl;
	
	do 
	{
		printf("Nhap so luong phan tu = ");
		scanf("%d", &sl);
		
		if(sl <= 0)
			printf("So luong khong hop le !");
	} while (sl <= 0);
	
	mang = (int *)calloc(sl, sizeof(int));
	
	printf("Nhap mang :\n");
	Nhap(mang, sl);
	
	printf("Xuat mang :\n");
	Xuat(mang, sl);
	
	int vt, gt;
	printf("Them phan tu co gia tri :");
	scanf("%d", &gt);

	printf("Them phan tu tai vi tri :");
	scanf("%d", &vt);
	
	Them(mang, &sl, vt, gt);
	
	printf("Mang sau khi them :");
	Xuat(mang, sl);
	
	int vtr;

	printf("Them phan tu tai vi tri :");
	scanf("%d", &vtr);
	
	Xoa(mang, &sl, vtr);
	
	printf("Mang sau khi xoa :");
	Xuat(mang, sl);
	
	free(mang);
	getch();
	return 0;
}

void Nhap(int* mang, int sl)
{
	int i;
	for(i = 0; i < sl; i++)
	{
		printf("Nhap phan tu thu [%d] = ", i);
		scanf("%d", &mang[i]);
	}
}

void Xuat(int* mang, int sl)
{
	int i;
	for(i = 0; i < sl; i++)
	{
		printf("%d	", mang[i]);
	}
	printf("\n");
} 

void Them(int* mang, int* sl, int vt, int gt)
{
	int i;
	(int *)realloc(mang, (*sl + 1) * sizeof(int));
	for (i = *sl - 1; i >= vt; i--)
	{
		mang[i + 1] = mang[i];
	}
	mang[vt] = gt;
	(*sl)++;
}

void Xoa(int* mang, int* sl, int vt)
{
	int i;
	for(i = vt + 1; i < *sl; i++)
	{
		mang[i - 1] = mang[i];
	}
	(int *)realloc(mang, (*sl - 1)* sizeof(int));
	(*sl)--;
}

