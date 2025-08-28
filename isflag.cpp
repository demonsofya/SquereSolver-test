#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
//#include <TXLib.h>

#include "isflag.h"
#include "test.h"
#include "Errors.h"

//int lol(double a, double *b);

Errors IsFlag(int argc, const char **argv, Flags *flag) {

    // int (*kek)(double, double *) = lol; // объ€вление укзател€ на фукнцию

    //FlagInfo k = {};
    //k.pointer = Test; // присвоение в перменную адреса функции
    //k.pointer(); // вызов функции, адрес которой в pointer

    //assert(argv); у мен€ теперь вместо ассертов проверка на ошибки
    ASSERT_ERROR(argv);

    if (argc == 1) {
        *flag = NO_FLAG;
        return NoError;
        //return NO_FLAG;
    }

    //void* calloc(size_t NumOfElements, size_t SizeOfOneElement//выдеение куска пам€ти

    PtrToFlagFunction *FlagsArray = (PtrToFlagFunction *) calloc(argc - 1, sizeof(PtrToFlagFunction));  //выделение куска пам€ти на массив флагинфо

    size_t flags_size = sizeof(FLAGS_INFO) / sizeof(FlagInfo);

    bool is_error = true;

    int scanned_flags_counter = 0;

    for (size_t i = 1; i < (size_t) argc; i++) {
        // обход массива структур на сравнение с флагами
        is_error = true;

        for (unsigned int j = 0; j < flags_size; j++) {

            //assert(argv[i]);
            if (argv[i] == NULL || FLAGS_INFO[j].short_name == NULL
                                || FLAGS_INFO[j].long_name == NULL)
                return IsflagFuncError;
            //assert(FLAGS_INFO[j].short_name);
            //assert(FLAGS_INFO[j].long_name);

            if ((strcmp(argv[i], FLAGS_INFO[j].short_name) == 0) ||
                (strcmp(argv[i], FLAGS_INFO[j].long_name)  == 0)) {

                is_error = false;
                FlagsArray[scanned_flags_counter++] = FLAGS_INFO[j].pointer;
            }
        }

        if (is_error) {
            printf("ERRROR THE THING YOU JUST INTPUTED IS NOT A FLAG AAAAAAAA");
            free(FlagsArray);
            *flag = FLAGS_SCAN_ERROR;

            return IsflagFuncError;
        }

    }

    for (int i = 0; i < scanned_flags_counter; i++) {

        //assert(FlagsArray[j]);
        if (FlagsArray[i] == NULL)
            return IsflagFuncError;

        CHECK_ERRORS(FlagsArray[i]());
    }

    free(FlagsArray);
    *flag = FLAGS_SCAN_SUCCESS;

    return NoError;
}

Errors Help(void) {

    printf("--help: manual of programm\n"
           "--test: testing programm on internal tests\n"
           "--No command: enter three koeffs of an equation to solve\n");

    return NoError;
}

