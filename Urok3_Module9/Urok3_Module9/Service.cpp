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

/* Задание 2 */
void generateDatePrd(DATA *date)
{
	date->day = 1 + rand() % 31;
	date->month = 1 + rand() % 12;
	date->year = 2016 + rand() % 2;
}
void printInfoPrd(TOVAR *prd, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("#%d. Наименование: %s, Количество: %d, Стоимость: %d, Дата поступления: %d.%d.%d\n",
			i + 1,
			(prd + i)->name,
			(prd + i)->quantity,
			(prd + i)->price,
			(prd + i)->date.day,
			(prd + i)->date.month,
			(prd + i)->date.year);
	}
	
}

TOVAR *createProd(int *count)
{
	TOVAR * prd = (TOVAR*)calloc(*count, sizeof(TOVAR));
	if (prd != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			createName((prd + i)->name, 10);
			(prd + i)->quantity = 100 + rand() % 300;
			(prd + i)->price = 1000 + rand() % 2000;
			generateDatePrd(&(prd + i)->date);
		
		}
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return prd;
}

/* Задание 3 */
void printInfoMrs(MARSHRUT *mrsh, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("Номер маршрута №%d, Начальный пункт: %s, Конечный пункт: %s, Длина маршрута: %d\n",
			(mrsh + i)->number,
			(mrsh + i)->first,
			(mrsh + i)->last,
			(mrsh + i)->length);
	}
}

MARSHRUT *createMrsh(int *count)
{
	MARSHRUT *mrsh = (MARSHRUT*)calloc(*count, sizeof(MARSHRUT));
	if (mrsh != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			(mrsh + i)->number = 1+rand()%100;
			createName((mrsh + i)->first, 5);
			createName((mrsh + i)->last, 5);
			(mrsh + i)->length = 1000 + rand() % 2000;

		}
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return mrsh;
}

void maxLen(MARSHRUT *mrs, int len)
{
	int lenMax = 0, ind;
	for (int i = 0; i < len; i++)
	{
		if ((mrs + i)->length > lenMax)
		{
			lenMax = (mrs + i)->length;
			ind = i;
		}
	}
	printf("Маршрут с максимальной длиной:\n");
	printInfoMrs((mrs + ind), 1);
}

void sort(MARSHRUT *mrs, int len)
{
	int tempPr = 1;
	MARSHRUT *temp = createMrsh(&tempPr);
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if ((mrs+i)->number >(mrs + j)->number)
			{
				*temp = *(mrs+i);
				*(mrs + i) = *(mrs + j);
				*(mrs + j) = *temp;
			}
		}
	}
}

void findPlace(MARSHRUT *mrs, char *pls, int len)
{
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if (strcmp((mrs + i)->first, pls) == 0 || strcmp((mrs + i)->last, pls) == 0)
		{
			printInfoMrs((mrs + i), 1);
			flag = 1;
		}		
	}
		if(!flag)
			printf("Пункт не найден.\n");
}

/* Задание 3 */
void printInfoAbn(ABON*ab, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("#%d. ФИО: %s %s.%s., Тел: %lld, Дата подключения: %d.%d.%d, Оплата: %d, Баланс: %d\n",
			i + 1,
			(ab + i)->abnNm.lName,
			(ab + i)->abnNm.fName,
			(ab + i)->abnNm.mName,
			(ab + i)->phone,
			(ab + i)->conDate.day,
			(ab + i)->conDate.month,
			(ab + i)->conDate.year,
			(ab + i)->payment,
			(ab + i)->balance);
	}
}


ABON *createAbn(int *count)
{
	ABON *abn = (ABON*)calloc(*count, sizeof(ABON));
	if (abn != NULL)
	{
		for (int i = 0; i < *count; i++)
		{
			createName((abn + i)->abnNm.lName, 10);
			createName((abn + i)->abnNm.fName, 2);
			createName((abn + i)->abnNm.mName, 2);
			(abn+i)->phone= 87000000000 + rand() % 100000;
			generateDate(&(abn + i)->conDate);
			(abn + i)->balance = 1000 + rand() % 500;
			(abn + i)->payment = 1000 + rand() % 500;
		}
	}
	else
	{
		printf("Ошибка!");
		exit(1);
	}
	return abn;
}

void sortAb(ABON *ab, int len)
{
	int tempPr = 1;
	ABON *temp = createAbn(&tempPr);
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (strcmp(ab[i].abnNm.lName, ab[j].abnNm.lName)>0)
			{
				*temp = *(ab + i);
				*(ab + i) = *(ab + j);
				*(ab + j) = *temp;
			}
			else if (strcmp(ab[i].abnNm.lName, ab[j].abnNm.lName) == 0)
				{
					if (strcmp(ab[i].abnNm.fName, ab[j].abnNm.fName)>0)
					{
						*temp = *(ab + i);
						*(ab + i) = *(ab + j);
						*(ab + j) = *temp;
					}
				}
				else if (strcmp(ab[i].abnNm.fName, ab[j].abnNm.fName) == 0)
					{
						if (strcmp(ab[i].abnNm.mName, ab[j].abnNm.mName)>0)
						{
							*temp = *(ab + i);
							*(ab + i) = *(ab + j);
							*(ab + j) = *temp;
						}
					}
		}
	}
}

void add(ABON*ab, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (2018 - (ab + i)->conDate.year > 10)
			(ab + i)->balance += 20;
	}
}

void neg(ABON*ab, int len)
{
	for (int i = 0; i < len; i++)
	{
		if ((ab + i)->balance - (ab + i)->payment < 0)
			printInfoAbn((ab + i), 1);
	}
}

void findNbr(ABON *ab, long long phn, int len)
{
	int flag = 0;
	for (int i = 0; i < len; i++)
	{
		if ((ab + i)->phone == phn)
		{
			printInfoAbn((ab + i), 1);
			flag = 1;
		}
	}
	if (!flag)
		printf("Телефон не найден.\n");
}