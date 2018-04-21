#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<locale.h>
#include<time.h>
#include"totalService.h"

void main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");
	printf("Работа содержит 4 задания.\n");
	printf("Для завершения наберите 0.\n");
	int n;
	do
	{
		printf("Введите номер задания: ");
		scanf("%d", &n);
		switch (n)
		{
			case 1:
			{
				int count = 9, tempPr=1, month, k=0;
				NOTE1 *BLOCK = createNote(&count);
				NOTE1 *temp = createNote(&tempPr);
				lines();
				printf("***  Телефонный справочник.  ***\n");
				lines();
					for (int i = 0; i < count - 1; i++)
					{
						for (int j = i + 1; j < count; j++)
						{
							if (strcmp(BLOCK[i].Nm.lName, BLOCK[j].Nm.lName)>0)
							{
								*temp = BLOCK[i];
								BLOCK[i] = BLOCK[j];
								BLOCK[j] = *temp;
							}
						}
					}
				
				printInfoNote(BLOCK, count);
				lines();
				printf("Введите месяц рождения: ");				
				scanf("%d", &month);
				lines();
				for (int i = 0; i < count; i++)
				{
					if (BLOCK[i].btd.month == month)
					{
						printInfoNote(&BLOCK[i], 1);
						k++;
					}
				}
				lines();
				if (!k)
					printf("Таких людей нет.\n");
				system("pause");
				system("cls");
			}break;

			case 2:
			{

			}break;

	

		}
	} while (n != 0);
}