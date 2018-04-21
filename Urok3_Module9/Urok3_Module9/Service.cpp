#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<locale.h>
#include "totalService.h"

/* Задание 1 */
void lines()
{
	printf("--------------------------------------\n");
}

void createName(char * name, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		if (i == 0)
			*(name + i) = (char)(65 + rand() % 24);
		else
			*(name + i) = (char)(97 + rand() % 24);
	}
	*(name + len) = '\0';
}

void generateDate(DATA *date)
{
	date->day = 1 + rand() % 31;
	date->month = 1 + rand() % 12;
	date->year = 1940 + rand() % 60;
}

void printInfoNote(NOTE1 * note, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("#%d. ФИО: %s %s.%s., тел: %lld, Д/Р: %d.%d.%d\n",
			i+1,
			note[i].Nm.lName,
			note[i].Nm.fName,
			note[i].Nm.mName,
			note[i].TELE,
			note[i].btd.day,
			note[i].btd.month,
			note[i].btd.year);
	}
}

NOTE1 *createNote(int *count)
{
	NOTE1 *nt = (NOTE1*)calloc(*count, sizeof(NOTE1));
	if (nt != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			createName(nt[i].Nm.lName, 15);
			createName(nt[i].Nm.fName, 2);
			createName(nt[i].Nm.mName, 2);
			nt[i].TELE = 87000000000 + rand() % 100000;
			generateDate(&nt[i].btd);
		}
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return nt;
}