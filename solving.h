/*!
\file
\brief Файл с функциями решения уравнения

Содержит определение структуру количества корней,
структуру коэффициентов, структуру корней

Есть функция решения универсальная, квадратного уравнения, линейного уравнения
*/
#ifndef SOLVING_H_INCLUDED
#define SOLVING_H_INCLUDED

#include "Errors.h"

/// Список констант - количество корней
enum NumberOfRoots { //camel case   GetUserInput // структуры, енамы, функции
    Inf = -1, ///< Бесконечное количество корней
    //snake case   get_user_input // локальные перменные, аргументы фнкциии
    NoRoots = 0, ///< Нет корней
    OneRoot = 1, ///< Один корень
    TwoRoots = 2 ///< Два корня
};

/// Коэфф. уравнения
struct Coeffs {
    double a;  ///< Коэффициент при члене второй степени
    double b;  ///< Коэффициент при члене первой степени
    double c;  ///< Свободный коэффициент
};

/// Корни + количество корней
struct Roots {
    double x1; ///< Первый корень
    double x2; ///< Второй корень
    NumberOfRoots number_of_roots;  ///< Количество корней
};

/// Функция для решения линейного уравнения
///
/// \param coeffs коэффициенты уравнения
/// \param roots корни уравнения
///
/// \return NoError, если решение прошло успешно, SolvingFuncError иначе
Errors Linear(const Coeffs *coeffs, Roots *roots);

/// Фукнция для решения квадратного уравнения
///
/// \param coeffs коэффициенты уравнения
/// \param roots корни уравнения
///
/// \return NoError, если решение прошло успешно, SolvingFuncError иначе
Errors Quadr(const Coeffs *coeffs, Roots *roots);

/// Универсальная решалка
///
/// \param coeffs коэффициенты уравнения
/// \param roots корни уравнения
///
/// \return NoError, если решение прошло успешно, SolvingFuncError иначе
Errors SqrEq(const Coeffs *coeffs, Roots *roots);

#endif // SOLVING_H_INCLUDED
