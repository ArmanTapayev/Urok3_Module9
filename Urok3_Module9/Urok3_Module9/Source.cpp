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
				lines();
				printf("***  Телефонный справочник.  ***\n");
				lines();
				printInfoNote(BLOCK, count);
				lines();
				sortN(BLOCK, count);
				printf("Записи, упорядоченные по алфавиту :\n");
				lines();
				printInfoNote(BLOCK, count);
				lines();
				printf("Получение информации по месяцу рождения.\n");
				printf("Введите месяц рождения: ");				
				scanf("%d", &month);
				lines();
				searchNum(BLOCK, count, month);
				system("pause");
				system("cls");
			}break;

			case 2:
			{
				int count = 10;
				TOVAR *SPISOK = createProd(&count);
				lines();
				printf("Список всех товаров:\n");
				lines();
				printInfoPrd(SPISOK, count);
				lines();
				printf("Сортировка по возрастанию стоимости товаров:\n");
				lines();
				sortMrs(SPISOK, count);
				printInfoPrd(SPISOK, count);
				avrMrs(SPISOK, count);
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
				printf("Сортировка маршрутов по номерам:\n");
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
				printf("Получение информации по номеру телефона.\n");
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