#include"01_NOTE1.h"
#include"02_TOVAR.h"
#include"03_MARSHRUT.h"
#include"04_ABON.h"

/* Задание 1 */
void lines();
void createName(char * name, int len);
void generateDate(DATA *date);
void printInfoNote(NOTE1 * note, int len);
NOTE1 *createNote(int *count);
void sortN(NOTE1 *BLOCK, int len);
void searchNum(NOTE1 *BLOCK, int len, int month);

/* Задание 2 */
void printInfoPrd(TOVAR *prd, int len);
TOVAR *createProd(int *count);
void generateDatePrd(DATA *date);
void sortMrs(TOVAR *mrs, int len);
void avrMrs(TOVAR *mrs, int len);

/* Задание 3 */
void printInfoMrs(MARSHRUT *mrsh, int len);
MARSHRUT *createMrsh(int *count);
void maxLen(MARSHRUT *mrs, int len);
void sort(MARSHRUT *mrs, int len);
void findPlace(MARSHRUT *mrs, char *pls, int len);

/* Задание 4 */
void printInfoAbn(ABON*ab, int len);
ABON *createAbn(int *count);
void sortAb(ABON *ab, int len);
void add(ABON*ab, int len);
void neg(ABON*ab, int len);
void findNbr(ABON *ab, long long phn, int len);
