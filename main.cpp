#include <stdio.h>
#include <math.h>
//#include <TXLib.h>

#include "input.h"
#include "output.h"
#include "solving.h"
#include "isflag.h"


int main(int argc, const char *argv[]) {

    Flags flag = IsFlag(argc, argv);// TODO: fix return value

    if (flag == FLAGS_SCAN_ERROR || flag == FLAGS_SCAN_SUCCESS)
        return 0;

    // TODO: what if flag is incorrect?
    while(true) {
        Coeffs input_coeffs = {NAN, NAN, NAN}; // TODO: ask once more
        Roots solved_roots = {NAN, NAN, NoRoots};

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
