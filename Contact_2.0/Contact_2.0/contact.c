#define _CRT_SECURE_NO_WARNINGS 

#include"contact.h"

void ContactInit(Contact* con)
{
	assert(con);

	con->data = NULL;
	con->capacity = 0;
	con->size = 0;
}

void ContactShow(Contact* con)
{
	assert(con);

	if (con->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-16s%-12s%-8s%-16s\n", "姓名", "性别", "年龄", "联系方式");
		for (int i = 0; i < con->size; i++)
		{
			printf("%-16s%-12s%-8d%-16s\n", con->data[i].name, con->data[i].sex, con->data[i].age, con->data[i].tele);
		}
	}
	system("pause");
}

void CheckCapacity(Contact* con)
{
	assert(con);

	if (con->capacity == con->size)
	{
		if (con->capacity == 0)
		{
			PeoInfo* tmp = (PeoInfo*)malloc(sizeof(PeoInfo));
			if (tmp == NULL)
			{
				perror("malloc");
			}
			else
			{
				con->data = tmp;
				con->capacity++;
			}
		}
		else
		{
			PeoInfo* tmp = (PeoInfo*)realloc(con->data,sizeof(PeoInfo)*(con->capacity)*2);
			if (tmp == NULL)
			{
				perror("realloc");
			}
			else
			{
				con->data = tmp;
				con->capacity *= 2;
			}
		}
	}
}

void ContactAdd(Contact* con)
{
	assert(con);

	CheckCapacity(con);

	printf("请输入联系人姓名：>");
	scanf("%s", &(con->data[con->size].name));
	printf("请输入联系人性别：>");
	scanf("%s", &(con->data[con->size].sex));
	printf("请输入联系人年龄：>");
	scanf("%d", &(con->data[con->size].age));
	printf("请输入联系人联系方式：>");
	scanf("%s", &(con->data[con->size].tele));

	con->size++;
	printf("录入联系人成功\n");
}

int FindByName(Contact* con, const char* name)
{
	assert(con);

	for (int i = 0; i < con->size; i++)
	{
		if (strcmp(con->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void ContactDelet(Contact* con)
{
	assert(con);

	char tmp[NAME_MAX] = { 0 };
	printf("请输入您要删除的联系人的姓名：>");
	scanf("%s", tmp);
	int pos = FindByName(con, tmp);
	if (pos == -1)
	{
		printf("您删除的联系人不存在\n");
	}
	else
	{
		for (int i = pos; i < con->size - 1; i++)
		{
			con->data[i] = con->data[i + 1];
		}
		con->size--;
		printf("联系人删除成功\n");
	}
}

void ContactSearch(Contact* con)
{
	assert(con);

	char tmp[NAME_MAX] = { 0 };
	printf("请输入您要查找的联系人的姓名：>");
	scanf("%s", tmp);
	int pos = FindByName(con, tmp);
	if (pos == -1)
	{
		printf("您查找的联系人不存在\n");
	}
	else
	{
		printf("%-16s%-12s%-8s%-16s\n", "姓名", "性别", "年龄", "联系方式");
		printf("%-16s%-12s%-8d%-16s\n", con->data[pos].name, con->data[pos].sex, con->data[pos].age, con->data[pos].tele);
		system("pause");
	}
}

void ContactModify(Contact* con)
{
	assert(con);

	char tmp[NAME_MAX] = { 0 };
	printf("请输入您要修改的联系人的姓名：>");
	scanf("%s", tmp);
	int pos = FindByName(con, tmp);
	if (pos == -1)
	{
		printf("被修改的联系人不存在\n");
	}
	else
	{
		printf("%-16s%-12s%-8s%-16s\n", "姓名", "性别", "年龄", "联系方式");
		printf("%-16s%-12s%-8d%-16s\n", con->data[pos].name, con->data[pos].sex, con->data[pos].age, con->data[pos].tele);
		
		printf("请输入联系人姓名：>");
		scanf("%s", &(con->data[pos].name));
		printf("请输入联系人性别：>");
		scanf("%s", &(con->data[pos].sex));
		printf("请输入联系人年龄：>");
		scanf("%d", &(con->data[pos].age));
		printf("请输入联系人联系方式：>");
		scanf("%s", &(con->data[pos].tele));

		printf("联系人修改成功\n");
	}
}

void sort_menu()
{
	printf("****************************************\n");
	printf("******     1.按姓名首字母升序     ******\n");
	printf("******     2.按姓名首字母降序     ******\n");
	printf("******     3.按年龄升序           ******\n");
	printf("******     4.按年龄降序           ******\n");
	printf("****************************************\n");
}

int cmp_by_name_up(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

int cmp_by_name_down(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e2)->name, ((PeoInfo*)e1)->name);
}

int cmp_by_age_up(const void* e1, const void* e2)
{
	return ((PeoInfo*)e1)->age - ((PeoInfo*)e2)->age;
}

int cmp_by_age_down(const void* e1, const void* e2)
{
	return ((PeoInfo*)e2)->age - ((PeoInfo*)e1)->age;
}

void ContactSort(Contact* con)
{
	assert(con);

	int input = 0;
	sort_menu();
	printf("请输入您的选择：>");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		qsort(con->data, con->size, sizeof(PeoInfo), cmp_by_name_up);
		break;
	case 2:
		qsort(con->data, con->size, sizeof(PeoInfo), cmp_by_name_down);
		break;
	case 3:
		qsort(con->data, con->size, sizeof(PeoInfo), cmp_by_age_up);
		break;
	case 4:
		qsort(con->data, con->size, sizeof(PeoInfo), cmp_by_age_down);
		break;
	}
}

void ContactDestroy(Contact* con)
{
	assert(con);

	free(con->data);
	con->data = NULL;
	con->capacity = 0;
	con->size = 0;
}