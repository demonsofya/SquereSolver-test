#ifndef ERRORS_H_INCLUDED
#define ERRORS_H_INCLUDED

#include <string.h>

/// Ошибки для возрата, под каждый cpp файл
enum Errors {
    SolvingFuncError,  ///< Ошибка в функции решения
    InputFuncError,    ///< Ошибка в функции ввода
    IsflagFuncError,    ///< Ошибка в функции проверки флага
    TestFuncError,      ///< Ошибка в функции UnitTest'ирования
    OutputFuncError,   ///< Ошибка в функции вывода
    NoError             ///< Нет ошибки
};

/// Заменяет ASSERT_ERROR на функцию ассерта
#define ASSERT_ERROR(bool_result, file_name) \
    {  \
        if (!bool_result) {\
            if (strcmp(file_name, "solving.cpp") == 0 || strcmp(file_name, "solving.h") == 0) \
                return SolvingFuncError; \
            if (strcmp(file_name, "input.cpp") == 0 || strcmp(file_name, "input.h") == 0) \
                return InputFuncError; \
            if (strcmp(file_name, "output.cpp") == 0 || strcmp(file_name, "output.h") == 0) \
                return OutputFuncError; \
            if (strcmp(file_name, "isflag.cpp") == 0 || strcmp(file_name, "isflag.h") == 0) \
                return IsflagFuncError; \
            if (strcmp(file_name, "test.cpp") == 0 || strcmp(file_name, "test.h") == 0) \
                return TestFuncError; \
        }\
    }



/// Заменяет CHECK_ERRORS на функцию, которая проверяет, какая вернулась ошибка
#define CHECK_ERRORS(func_result) \
    { \
        Errors current_error = func_result; \
        switch(current_error) {\
            case NoError: \
                break; \
            case SolvingFuncError: \
                printf("\nError in solving function");\
                return SolvingFuncError; \
                break; \
            case InputFuncError: \
                printf("\nError in input function");\
                return InputFuncError; \
                break; \
            case TestFuncError: \
                printf("\nError in test function");\
                return TestFuncError; \
                break; \
            case OutputFuncError: \
                printf("\nError in output function");\
                return OutputFuncError; \
                break; \
            case IsflagFuncError: \
                printf("\nError in isflag function");\
                return IsflagFuncError; \
                break; \
            default:   \
                break; \
        }\
    }


/// заменяет RETURN_IF_ERROR на фукнцию, которая проверяет вернулась ли ошибка
#define RETURN_IF_ERROR(func_result) \
    { \
        Errors current_if_error = func_result; \
        if (current_if_error != NoError) \
            return current_if_error; \
    }

//#define RETURN_NO_ERROR RETURN_IF_ERROR(NoError)


#endif // ERRORS_H_INCLUDED
