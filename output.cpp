#include <stdio.h>
#include <assert.h>
#include <windows.h>

#include "solving.h"
#include "output.h"
#include "Errors.h"

Errors Print(const Roots *roots) {

    ASSERT_ERROR(roots);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole,
                            FOREGROUND_RED | FOREGROUND_GREEN | BACKGROUND_BLUE);

    switch (roots->number_of_roots) {
        case NoRoots:
            printf("No Roots");
            break;
        case OneRoot:
            printf("x = %lg", roots->x1);
            break;
        case TwoRoots:
            printf("x1 = %lg, x2 = %lg", roots->x1, roots->x2);
            break;
        case Inf:
            printf("Infinity");
            break;
        default:
            printf ("Error");
            return OutputFuncError;
    }

    SetConsoleTextAttribute(hConsole,
    FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

    return NoError;
}
