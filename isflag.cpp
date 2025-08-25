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

/*int IsShortFlag(const char *flag) {

    assert(flag != NULL);

    if ((*flag)[0] == '-') {

        if ((*flag)[0] == 't' && (*flag)[1] == '\0')
            return 't';

        if ((*flag)[0] == 'h' && (*flag)[1] == '\0')
            return 'h';
    }

    return 0;
}

int IsLongFlag(flag_size, const char *flag) {
    if ((*flag)[0] == '-' && (*flag)[1] == '-') {

        if (flag_size == 6) {
            if ((*flag)[0] == 't' && (*flag)[1] == 'e' && (*flag)[2] == 's' && (*flag)[1] == 't' && (*flag)[2)
                return 't';

            if ((*flag)[0] == 'h' && (*flag)[1] == 'e')
                return 'h';
        }
    }
}
*/

