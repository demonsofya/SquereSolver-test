#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
//#include <TXLib.h>

#include "isflag.h"
#include "test.h"

// TODO: move to .h


//int lol(double a, double *b);

Flags IsFlag(int argc, const char **argv) {

    // int (*kek)(double, double *) = lol; // объ€вление укзател€ на фукнцию

    //FlagInfo k = {};
    //k.pointer = Test; // присвоение в перменную адреса функции
    //k.pointer(); // вызов функции, адрес которой в pointer

    assert(argv);

    if (argc == 1)
        return NO_FLAG;

    // argc == 1? если да, делаем обычну. программу

    //void* calloc(size_t NumOfElements, size_t SizeOfOneElement//выдеение куска пам€ти


    // переименовать!!!!!!!!!!!!!
    PtrToFlagFunction *FlagsArray = (PtrToFlagFunction *) calloc(argc - 1, sizeof(PtrToFlagFunction));  //выделение куска пам€ти на массив флагинфо
    //FlagsArray = {};

    unsigned int flags_size = sizeof(FLAGS_INFO) / sizeof(FlagInfo);
    //  есть флаг, который смотрит error ->  если есть, освобождаем массив, печатем ошибку, выходим
    bool is_error = true; // TODO: remove large
    //bool iserror_small = false;// TODO: remove small
    // счетчик на последний свободный элемент в массиве
    int scanned_flags_counter = 0;  // scanned_flags_counter
    // кладу указатели на функции в массив
    // обхожу его второй раз еслинет ошибок. вызываю функции
    //free(a);  // освобождение пам€ти
    // каллок занул€ет пам€ть автоматически, маллок нет
    //|   |   |    |    |    |   |

    // | heap | stack memory |

    for (int i = 1; i < argc; i++) {   // argv[1]
        // обход массива структур на сравнение с флагами
        is_error = true;

        for (unsigned int j = 0; j < flags_size; j++) {

            assert(argv[i]);
            assert(FLAGS_INFO[j].short_name);
            assert(FLAGS_INFO[j].long_name);

            if ((strcmp(argv[i], FLAGS_INFO[j].short_name) == 0) || (strcmp(argv[i], FLAGS_INFO[j].long_name) == 0)) {

                is_error = false;
                FlagsArray[scanned_flags_counter++] = FLAGS_INFO[j].pointer;
            }
        }

        if (is_error) {
            printf("ERRROR THE THING YOU JUST INTPUTED IS NOT A FLAG AAAAAAAA");
            free(FlagsArray);

            return FLAGS_SCAN_ERROR;
        }


        //if ((strcmp(argv[i], "-t") == 0) || (strcmp(argv[i], "--test") == 0))
        //    return 't';
        //
        //if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0))
        //    return 'h';

        //printf("ERRROR THE THING YOU JUST INTPUTED IS NOT A FLAG AAAAAAAA");
        //return 'E';
    }

    for (int j = 0; j < scanned_flags_counter; j++) {

        assert(FlagsArray[j]);

        FlagsArray[j]();
    }

    free(FlagsArray);

    return FLAGS_SCAN_SUCCESS;
}

int Help(void) {

    printf("--help: manual of programm\n"
           "--test: testing programm on internal tests\n"
           "--No command: enter three koeffs of an equation to solve\n");

    return 0;
}

