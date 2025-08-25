#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "mathematics.h"
#include "solving.h"
#include "test.h"

int Test(void) {

    bool flag = true;
    Roots roots = {NAN, NAN, 0};
    Coeffs coeffs = {NAN, NAN, NAN};

    unsigned amount_of_tests = (sizeof(TESTS) / (sizeof(Coeffs) + sizeof(Roots)));

    for (unsigned int test_num = 0; test_num < amount_of_tests; test_num++) {

        coeffs = TESTS[test_num].coeffs;

        roots.number_of_roots = SqrEq(&coeffs, &roots);

        flag = flag && IsRootsRight(&roots, test_num);
    }

    if (flag) {
        printf("All tests passed\n");
    }

    return 0;
}

bool IsRootsRight(const Roots *roots, int test_num) {

    assert(roots != NULL);

    switch (TESTS[test_num].roots.number_of_roots) {
        case TwoRoots:    // TODO: бахнуть контсанты COMPLETED
            if (!(((((CompareDoubles(roots->x1, TESTS[test_num].roots.x1) && CompareDoubles(roots->x2, TESTS[test_num].roots.x2))) ||
                (((CompareDoubles(roots->x2, TESTS[test_num].roots.x1) && CompareDoubles(roots->x1, TESTS[test_num].roots.x2)))))
                && roots->number_of_roots == 2))) {

                ErrorPrint(roots, test_num);
                return false;
            }

            break;

        case OneRoot:
            if (!((CompareDoubles(roots->x1, TESTS[test_num].roots.x1) || CompareDoubles(roots->x2, TESTS[test_num].roots.x1))
                && roots->number_of_roots == 1)){

                ErrorPrint(roots, test_num);
                return false;
            }

            break;

        case Inf:
            if (roots->number_of_roots != Inf) {

                ErrorPrint(roots, test_num);
                return false;
            }

            break;

        case NoRoots:
            if ((roots->number_of_roots) != 0) {

            ErrorPrint(roots, test_num);
            return false;
            }

            break;

        default:
            return true;
            break;

    }

    return true;

    /*if (TESTS[test_num].roots.number_of_roots == 2) {   // если корней два
        if (!(((CompareDoubles(roots->x1, TESTS[test_num].roots.x1) && CompareDoubles(roots->x2, TESTS[test_num].roots.x2)) ||
             ((CompareDoubles(roots->x2, TESTS[test_num].roots.x1) && CompareDoubles(roots->x1, TESTS[test_num].roots.x2))) &&
             roots->number_of_roots == 2))) {

            ErrorPrint(roots, test_num);
            return false;
        }
    } else if (TESTS[test_num].roots.number_of_roots == 1) {   // если корень один
        if (!((CompareDoubles(roots->x1, TESTS[test_num].roots.x1) || CompareDoubles(roots->x2, TESTS[test_num].roots.x1)) &&
             roots->number_of_roots == 1)){

            ErrorPrint(roots, test_num);
            return false;
        }
    } else if (TESTS[test_num].roots.number_of_roots == Inf) { // если корней бесконечность
        if (roots->number_of_roots != Inf) {

            ErrorPrint(roots, test_num);
            return false;
        }
    } else { // вариант когда корней нет (но через элзе)
        if ((roots->number_of_roots) != 0) {

            ErrorPrint(roots, test_num);
            return false;
        }
    }

    return true;
    */
}

void ErrorPrint(const Roots *roots, int test_num) { // TODO: const COMPLETED

    assert(roots != NULL);

    printf("The solve is cringe: x1 right = %lg, x2 right = %lg, number of Roots right = %d;\n",
            TESTS[test_num].roots.x1, TESTS[test_num].roots.x2, TESTS[test_num].roots.number_of_roots);
    printf("your x1 = %lg, x2 = %lg, number of Roots = %d\n", roots->x1, roots->x2, roots->number_of_roots);
    printf("Koeffs are: a = %lg, b = %lg, c = %lg",
            TESTS[test_num].coeffs.a, TESTS[test_num].coeffs.b, TESTS[test_num].coeffs.c);
}
