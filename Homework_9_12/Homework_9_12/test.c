#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(void* e1, void* e2, int size)
{
	for (int i = 0; i < size; i++)
	{
		char tmp = *((char*)e1 + i);
		*((char*)e1 + i) = *((char*)e2 + i);
		*((char*)e2 + i) = tmp;
	}
}

void my_qsort(void* arr, size_t sz, size_t size, int(*cmp)(const void* e1, const void* e2))
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)arr + j * size, (char*)arr + (j + 1) * size) > 0)
			{
				swap((char*)arr + j * size, (char*)arr + (j + 1) * size, size);
			}
		}
	}
}

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

struct stu {
	char name[10];
	int age;
};

int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp(((struct stu*)e1)->name, ((struct stu*)e2)->name);
}

int cmp_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

int main()
{
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	printf("排序前:");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	my_qsort(arr, sz, sizeof(arr[0]), cmp_int);
	printf("排序后:");
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	struct stu arrs[3] = { {"Wuyifan",20},{"Lily",26},{"Sweet",33} };
	int szs = sizeof(arrs) / sizeof(arrs[0]);
	printf("排序前:");
	for (int i = 0; i < szs; i++)
	{
		printf("{%s %d} ", arrs[i].name,arrs[i].age);
	}
	printf("\n");
	my_qsort(arrs, szs, sizeof(arrs[0]), cmp_by_name);
	printf("按姓名排序后:");
	for (int i = 0; i < szs; i++)
	{
		printf("{%s %d} ", arrs[i].name, arrs[i].age);
	}
	printf("\n");
	my_qsort(arrs, szs, sizeof(arrs[0]), cmp_by_age);
	printf("按年龄排序后:");
	for (int i = 0; i < szs; i++)
	{
		printf("{%s %d} ", arrs[i].name, arrs[i].age);
	}
	printf("\n");
	return 0;
}