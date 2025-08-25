#include <stdio.h>
#include <math.h>

#include "test.h"
#include "input.h"
#include "output.h"
#include "solving.h"
#include "isflag.h"

//int main(int argc, char *argv[])

int main(int argc, char *argv[]) {

    int flag = IsFlag(argc, argv);

    if (flag == 't')
        return Test();
    if (flag == 'h')
        return Help();

    Coeffs input_coeffs = {NAN, NAN, NAN};
    Roots solved_roots = {NAN, NAN, 0};   // TODO: third  COMPLETED
    Test(); // TODO: capital letter!!!

    Scan(&input_coeffs);

    solved_roots.number_of_roots = SqrEq(&input_coeffs, &solved_roots);

    Print(&solved_roots);

    return 0;
}
