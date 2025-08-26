#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "solving.h"

/// Структура, хранящая одно уравнение
struct UnitTest {
    Coeffs coeffs;
    Roots roots;
};

/// Массив существующих тестов
/*UnitTest TESTS[6] =
{
        //coeffs        //roots
    {   {1, -5, 6},     {2, 3, 2}   },
    {   {0, 0, 0},      {0, 0, Inf} },
    {   {1, 0, -4},     {2, -2, 2}  },
    {   {1, 1, 1},      {2, -2, 0}  },
    {   {0, 1, 1},      {-1, -1, 1} },
    {   {1, -12, 36},   {6, 6, 1}   },
};*/

//unsigned int UnitTestFile(void);


//UnitTest TESTS[6] = {};

/*unsigned int UnitTestFile(void) {

    FILE *fp;
    fp = fopen("UnitTests.txt", "r");
    double a, b, c;
    double x1, x2;
    int nRoots;
    unsigned int lines_count = 0;
    while(fscanf(fp, "%lf %lf %lf %lf %lf %d", &a, &b, &c, &x1, &x2, &nRoots) != EOF) {
        TESTS[lines_count].coeffs = {a, b, c};
        TESTS[lines_count].roots = {x1, x2, nRoots};
        lines_count++;
    }
    fclose(fp);

    return lines_count;
} */

void FillUnitTests(FILE *fp, UnitTest *tests, size_t num_of_tests);

size_t GetNumberOfUnitTests(FILE *fp);

/// Запускает тест
int Test(void);

/// Функция, проверяющая корни на правильность
bool IsRootsRight(const Roots *roots, int test_num, UnitTest* tests);

/// Функция вывода ошибки
void ErrorPrint(const Roots *roots, int test_num, UnitTest *tests);

#endif // TEST_H_INCLUDED
