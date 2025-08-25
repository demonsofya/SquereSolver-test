#include <string.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#include "isflag.h"

int IsFlag(int argc, const char **argv) {

    assert(argv);

    for (int i = 1; i < argc; i++) {

        if ((strcmp(argv[i], "-t") == 0) || (strcmp(argv[i], "--test") == 0))
            return 't';

        if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0))
            return 'h';

        printf("ERRROR THE THING YOU JUST INTPUTED IS NOT A FLAG AAAAAAAA");
        return 'E';
    }

    return '\0';
}

int Help(void) {

    printf("--help: manual of programm\n"
           "--test: testing programm on internal tests\n"
           "--No command: enter three koeffs of an equation to solve");

    return 0;
}

