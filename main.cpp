#include <stdio.h>
#include <math.h>
//#include <TXLib.h>

#include "input.h"
#include "output.h"
#include "solving.h"
#include "isflag.h"
#include "Errors.h"

// TODO: file errors.h with enum Errors {}
// TODO: macros CHECK_ERROR, RETURN_ERROR and RETURN_NO_ERROR
// TODO:

int main(int argc, const char *argv[]) {

    Flags flag = NO_FLAG;
    CHECK_ERRORS(IsFlag(argc, argv, &flag));

    if (flag == FLAGS_SCAN_ERROR || flag == FLAGS_SCAN_SUCCESS)
        return int(NoError);

    while(true) {
        Coeffs input_coeffs = {NAN, NAN, NAN};
        Roots solved_roots = {NAN, NAN, NoRoots};

        CHECK_ERRORS(Scan(&input_coeffs));

        CHECK_ERRORS(SqrEq(&input_coeffs, &solved_roots));

        CHECK_ERRORS(Print(&solved_roots));

        int symbol = 0;

        printf("\nDo you want to continue? y/n\n");

        if ((symbol = getchar()) != 'y')
            return int(NoError);

        printf("\n");
    }

    return int(NoError);
}
