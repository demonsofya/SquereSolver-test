/*!
\file
\brief Файл с функциями вывода

Содержит функцию вывода корней
*/
#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include "solving.h"
#include "Errors.h"

/// Вывод решения уравнения
///
/// \param roots Корни уравнения
///
/// \return NoError, если сканирование прошло успешно, OutputFuncError в ином случае
Errors Print(const Roots *roots);

#endif // OUTPUT_H_INCLUDED
