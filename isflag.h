/*!
\file
\brief Файл с функциями проверки, является ли вводимое в консоли флагом

Содержит структуру флагов,
структуру типа флага

Есть функции, вызваемые флагами и указатель на функцию, которая определяет флаг ли
*/
#ifndef ISFLAG_H_INCLUDED
#define ISFLAG_H_INCLUDED

#include "test.h"
#include "Errors.h"

/// Enum типа флага
enum Flags {
    FLAGS_SCAN_ERROR,   ///< Ошибка
    FLAGS_SCAN_SUCCESS, ///< Флаг найден
    NO_FLAG             ///< Флагов не было
};

typedef Errors(*PtrToFlagFunction)(void);

/// Выводит справку
///
/// \return NoError если все прошло успешно, IsflagFuncError в ином случае
Errors Help(void);

/// Содержит информацию о флагах
struct FlagInfo {
    const char *short_name;    ///< Короткое имя флага
    const char *long_name;     ///< Длинное имя флага
    PtrToFlagFunction pointer; ///< Указатель на функцию, которая запускается флагом
};


/// Массив существующих флагов
const FlagInfo FLAGS_INFO[] = {
    {"-t", "--test", Test},  ///< Запуск тестов
    {"-h", "--help", Help}   ///< Запуск справки
};


/// Функция проверяет, являются ли введенные символы флагом
///
/// \param argc Размер массива argv
/// \param argv указатель на массив введенных строк
/// \param flag указатель на флаг, в котором храниться прочитан ли флаг
///
/// \return NoError, если сканирование прошло успешно, IsflagFuncError в ином случае
Errors IsFlag(int argc, const char *argv[], Flags *flag);

#endif // ISFLAG_H_INCLUDED
