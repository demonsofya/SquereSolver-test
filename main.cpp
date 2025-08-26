#include <stdio.h>
#include <math.h>
//#include <TXLib.h>

#include "test.h"
#include "input.h"
#include "output.h"
#include "solving.h"
#include "isflag.h"


int main(int argc, const char *argv[]) {

    int flag = IsFlag(argc, argv);

    if (flag == 'F' || flag == 'E')
        return 0;

    // TODO: what if flag is incorrect?
    while(true) {
        Coeffs input_coeffs = {NAN, NAN, NAN}; // TODO: ask once more
        Roots solved_roots = {NAN, NAN, 0};

        Scan(&input_coeffs);

        solved_roots.number_of_roots = SqrEq(&input_coeffs, &solved_roots);

        Print(&solved_roots);

        int symbol = 0;

        printf("\nDo you want to continue? y/n\n");

        if ((symbol = getchar()) != 'y')
            return 0;

        printf("\n");
    }

    return 0;
}
