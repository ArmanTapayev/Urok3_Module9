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
				int count = 10,sum=0, tempPr=1;
				TOVAR *SPISOK = createProd(&count);
				TOVAR *temp = createProd(&tempPr);
				printInfoPrd(SPISOK, count);
				for (int i = 0; i < count - 1; i++)
				{
					for (int j = i + 1; j < count; j++)
					{
						if (SPISOK[i].price > SPISOK[j].price)
						{
							*temp = SPISOK[i];
							SPISOK[i] = SPISOK[j];
							SPISOK[j] = *temp;
						}
					}
				}
				printInfoPrd(SPISOK, count);
				for (int i = 0; i < count; i++)
				{
					sum += (SPISOK + i)->price;
					if (abs(((SPISOK + i)->date.month)- 4)>10 && (SPISOK+i)->date.year<=2017)
					{
						printInfoPrd((SPISOK + i), 1);
					}
				}
				printf("Средняя стоимость товара: %0.2f\n", (float)sum / count);
				system("pause");
				system("cls");
			}break;

			case 3:
			{
				int count = 10;
				char *place = (char*)malloc(5 * sizeof(char));
				MARSHRUT *mrsh = createMrsh(&count);
				lines();
				printf("Список всех маршрутов:\n");
				lines();
				printInfoMrs(mrsh, count);
				lines();
				maxLen(mrsh, count);
				lines();
				printf("Сортировка маршрутов пономерам:\n");
				sort(mrsh, count);
				lines();
				printInfoMrs(mrsh, count);
				lines();
				printf("Введите начальный или конечный пункт: ");
				scanf("%s", place);
				lines();
				findPlace(mrsh, place, count);
				lines();
				system("pause");
				system("cls");
			}break;

			case 4:
			{
				int count = 10;
				long long phn;
				ABON *ab = createAbn(&count);
				lines();
				printf("Список всех абонентов:\n");
				lines();
				printInfoAbn(ab, count);
				lines();
				sortAb(ab, count);
				printf("Записи по алфавиту :\n");
				lines();
				printInfoAbn(ab, count);
				lines();
				printf("Добавление 20 гр. на счета абонентов, которых подключили более 10 лет :\n");
				add(ab, count);
				lines();
				printInfoAbn(ab, count);
				lines();
				printf("Абоненты, у которых сумма на счету отрицательная после вычета начислений :\n");
				lines();
				neg(ab, count);
				lines();
				printf("Введите номер телефона: ");
				scanf("%lld", &phn);
				findNbr(ab, phn, count);
				lines();
				system("pause");
				system("cls");
			}break;

	

		}
	} while (n != 0);
}