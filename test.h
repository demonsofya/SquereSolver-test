/*!
\file
\brief Файл с функциями UnitTest

Содержит определение структуры UnitTest,
функцию вызова тестирования, функцию проверки правильности корней,
Две функции для заполнения массива из файла
*/
#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "solving.h"

/// Структура, хранящая одно уравнение
struct UnitTest {
    Coeffs coeffs; ///< Коэффициенты уравнения
    Roots roots;   ///< Корни уравнения
};

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

/// Заполняет массив UnitTest из файла
void FillUnitTests(FILE *fp, UnitTest *tests, size_t num_of_tests);

/// Возвращает количество строк в файле
size_t GetNumberOfUnitTests(FILE *fp);

/// Запускает тест
int Test(void);

/// Функция, проверяющая корни на правильность
bool IsRootsRight(const Roots *roots, int test_num, UnitTest* tests);

/// Функция вывода ошибки
void ErrorPrint(const Roots *roots, int test_num, UnitTest *tests);

#endif // TEST_H_INCLUDED
