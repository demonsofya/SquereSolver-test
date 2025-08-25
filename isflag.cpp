#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "isflag.h"

int IsFlag(int argc, char *argv[]) {

    assert(argv != NULL);

    for (int i = 1; i < argc; i++) {

        const char* str_t = "-t";
        const char* str_t_long = "--test";

        const char* str_h = "-h";
        const char* str_h_long = "--help";

        if ((strcoll(argv[i], str_t) == 0) || (strcoll(argv[i], str_t_long) == 0))
            return 't';

        if ((strcoll(argv[i], str_h) == 0) || (strcoll(argv[i], str_h_long) == 0))
            return 'h';

        printf("Not a flag");
    }

    return 'X';
}

int Help(void) {

    printf("--help: manual of programm\n"
           "--test: testing programm on internal tests\n"
           "--No command: enter three koeffs of an equation to solve");

    return 0;
}

