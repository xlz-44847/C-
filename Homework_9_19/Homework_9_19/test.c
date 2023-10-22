#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<assert.h>

void* my_memmove(void* dest, const char* src, size_t size)
{
	assert(dest && src);
	
	if (dest > src)
	{
		dest = (char*)dest + size - 1;
		src = (char*)src + size - 1;
		while (size--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest - 1;
			src = (char*)src - 1;
		}
	}
	else
	{
		while (size--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
}
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	my_memmove(arr + 3, arr, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	my_memmove(arr, arr + 3, 20);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}

//void* my_memcpy(void* dest, const void* src, size_t size)
//{
//	assert(dest && src);
//
//	while (size--)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//	}
//}
//
//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[] = { 1,2,3,4,5 };
//	my_memcpy(arr1, arr2, 20);
//	for (int i = 0; i < 5; i++)
//	{
//		printf("%d ", arr1[i]);
//	}
//	return 0;
//}