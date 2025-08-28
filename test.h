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
#include "Errors.h"

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
///
/// \param fp указатель на файл, из которого считывает коэффициенты
/// \param tests указатель на массив, в который вписывает коэффициенты
/// \param num_of_tests количество тестов в файле
///
/// \return NoError, если заполнение прошло успешно, TestFuncError иначе
Errors FillUnitTests(FILE *fp, UnitTest *tests, size_t num_of_tests);

/// Возвращает количество строк в файле
///
/// \param fp указатель на файл, в котором считает строки
///
/// \return NoError, если подсчет прошел успешно, TestFuncError иначе
size_t GetNumberOfUnitTests(FILE *fp);

/// Запускает тест
///
/// \return NoError, если тестирование прошло успешно, TestFuncError иначе
Errors Test(void);

/// Функция, проверяющая корни на правильность
///
/// \param roots корни уравнения
/// \param test_num номер теста
/// \param tests массив тестов
/// \param is_root_right указатель на бул, в который записывается правильный ли тест
///
/// \return NoError, если проверка прошла успешно, TestFuncError иначе
Errors IsRootsRight(const Roots *roots, int test_num, UnitTest* tests, bool *is_root_right);

/// Функция вывода ошибки
///
/// \param roots корни уравнения
/// \param test_num номер теста
/// \param tests массив тестов
///
/// \return NoError, если вывод прошел успешно, TestFuncError иначе
Errors ErrorPrint(const Roots *roots, int test_num, UnitTest *tests);

#endif // TEST_H_INCLUDED
