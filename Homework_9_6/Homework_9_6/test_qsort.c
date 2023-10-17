#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void test1()
{
	int arr[10] = { 4,1,0,7,2,20,3,12,9,5 };
	size_t sz = sizeof(arr) / sizeof(arr[0]);
	printf("≈≈–Ú«∞£∫");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	printf("≈≈–Ú∫Û£∫");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

struct stu {
	char name[10];
	int age;
};
struct stu arr[3] = { {"Peter",29 },{"Lily",16},{"Wuyifan",22} };
size_t sz = sizeof(arr) / sizeof(arr[0]);

int cmp_by_name(const void* e1, const void* e2)
{
	return strcmp((((struct stu*)e1)->name), (((struct stu*)e2)->name));
}


void test2()
{
	printf("≈≈–Ú«∞£∫");
	for (int i = 0; i < 3; i++)
	{
		printf("{%s ", arr[i].name);
		printf("%d} ", arr[i].age);
	}
	printf("\n");
	qsort(arr, sz, sizeof(arr[0]), cmp_by_name);
	printf("≈≈–Ú∫Û£∫");
	for (int i = 0; i < 3; i++)
	{
		printf("{%s ", arr[i].name);
		printf("%d} ", arr[i].age);
	}
	printf("\n");
}

int cmp_by_age(const void* e1, const void* e2)
{
	return ((struct stu*)e1)->age - ((struct stu*)e2)->age;
}

void test3()
{
	printf("≈≈–Ú«∞£∫");
	for (int i = 0; i < 3; i++)
	{
		printf("{%s ", arr[i].name);
		printf("%d} ", arr[i].age);
	}
	printf("\n");
	qsort(arr, sz, sizeof(arr[0]), cmp_by_age);
	printf("≈≈–Ú∫Û£∫");
	for (int i = 0; i < 3; i++)
	{
		printf("{%s ", arr[i].name);
		printf("%d} ", arr[i].age);
	}
	printf("\n");
}

int main()
{
	test1();
	test2();
	test3();
	return 0;
}