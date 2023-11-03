#pragma once

#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

#define NAME_MAX 16
#define SEX_MAX 12
#define TELE_MAX 16
#define MAX 20

enum option {
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;
	int size;
	int capacity;
}Contact;

void ContactInit(Contact* con);
void ContactShow(Contact* con);
void ContactAdd(Contact* con);
void ContactDelet(Contact* con);
void ContactSearch(Contact* con);
void ContactModify(Contact* con);
void ContactSort(Contact* con);
void ContactDestroy(Contact* con);