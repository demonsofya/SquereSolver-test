#ifndef ISFLAG_H_INCLUDED
#define ISFLAG_H_INCLUDED

#include "test.h"

typedef int(*PtrToFlagFunction)(void);

/// Выводит справку
int Help(void);

/// Содержит информацию о флагах
struct FlagInfo {
    const char *short_name;    ///< Короткое имя флага
    const char *long_name;     ///< Длинное имя флага
    PtrToFlagFunction pointer;
};


/// Массив существующих флагов
const FlagInfo FLAGS_INFO[] = {
    {"-t", "--test", Test},  /// Запуск тестов
    {"-h", "--help", Help},  /// Запуск справки
};

// TODO: array of structs FlagInfo with flags


/// Функция проверяет, являются ли введенные символы флагом
int IsFlag(int argc, const char *argv[]);

#endif // ISFLAG_H_INCLUDED
