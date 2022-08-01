#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void Nhap(int* arr, int size);
void Xuat(int* arr, int size);
void Them(int* arr, int* size, int pos, int val);
void Xoa(int* arr, int* size, int pos);

int main()
{
	return 0;
}

/*
 *\brief			
 *\param[in]
 *\return
 */
void Nhap(int* arr, int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("Nhap phan tu thu [%d] = ", i);
		scanf("%d", &arr[i]);
	}
}

/*
 *\brief			
 *\param[in]
 *\return
 */
void Xuat(int* arr, int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("%d	", arr[i]);
	}
	printf("\n");
} 

/*
 *\brief			
 *\param[in]
 *\return
 */
void Them(int* arr, int* size, int pos, int val)
{
	int i;
	realloc(arr, (*size + 1) * sizeof(int));
	for (i = *size - 1; i >= pos; i--)
	{
		arr[i + 1] = arr[i];
	}
	arr[pos] = val;
	(*size)++;
}

/*
 *\brief			
 *\param[in]
 *\return
 */
void Xoa(int* arr, int* size, int pos)
{
	int i;
	for(i = pos + 1; i < *size; i++)
	{
		arr[i - 1] = arr[i];
	}
	realloc(arr, (*size - 1)* sizeof(int));
	(*size)--;
}

