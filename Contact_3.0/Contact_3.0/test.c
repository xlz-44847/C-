#define _CRT_SECURE_NO_WARNINGS 

#include"contact.h"

void menu()
{
	printf("*****************************************\n");
	printf("******    1.Add           2.Del    ******\n");
	printf("******    3.Search        4.Modify ******\n");
	printf("******    5.Show          6.Sort   ******\n");
	printf("******    0.Exit                   ******\n");
	printf("*****************************************\n");
}

int main()
{
	Contact con;
	ContactInit(&con);
	int input = 0;
	do {
		menu();
		printf("����������ѡ��>");
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:
			ContactSave(&con);
			ContactDestroy(&con);
			printf("�˳�ͨѶ¼\n");
			break;
		case ADD:
			ContactAdd(&con);
			break;
		case DEL:
			ContactDelet(&con);
			break;
		case SEARCH:
			ContactSearch(&con);
			break;
		case MODIFY:
			ContactModify(&con);
			break;
		case SHOW:
			ContactShow(&con);
			break;
		case SORT:
			ContactSort(&con);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	} while (input);
	return 0;
}