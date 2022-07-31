#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void Nhap(int* mang, int sl);
void Xuat(int* mang, int sl);
void Them(int* mang, int* sl, int vt, int gt);
void Xoa(int* mang, int* sl, int vt);

int main()
{
	return 0;
}

/*
 *\brief			
 *\param[in]
 *\return
 */
void Nhap(int* mang, int sl)
{
	int i;
	for(i = 0; i < sl; i++)
	{
		printf("Nhap phan tu thu [%d] = ", i);
		scanf("%d", &mang[i]);
	}
}

/*
 *\brief			
 *\param[in]
 *\return
 */
void Xuat(int* mang, int sl)
{
	int i;
	for(i = 0; i < sl; i++)
	{
		printf("%d	", mang[i]);
	}
	printf("\n");
} 

/*
 *\brief			
 *\param[in]
 *\return
 */
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

/*
 *\brief			
 *\param[in]
 *\return
 */
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

