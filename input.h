/*!
\file
\brief Файл с функциями вводы

Содержит функцию вводы коэффициентов
*/
#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "solving.h"

/// Ввод коэффециентов уравнения
///
/// \param coeffs Коэффициенты квадратного уравнения
///
/// \return 1, если сканирование прошло успешно, 0 в ином случае
int Scan(Coeffs *coeffs);

#endif // INPUT_H_INCLUDED
