/*!
\file
\brief Файл с функциями вводы

Содержит функцию вводы коэффициентов
*/
#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "solving.h"
#include "Errors.h"

/// Ввод коэффециентов уравнения
///
/// \param coeffs Коэффициенты квадратного уравнения
///
/// \return NoError, если сканирование прошло успешно, InputFuncError в ином случае
Errors Scan(Coeffs *coeffs);

#endif // INPUT_H_INCLUDED
