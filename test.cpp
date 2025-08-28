#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "mathematics.h"
#include "solving.h"
#include "test.h"
#include "Errors.h"

Errors FillUnitTests(FILE *fp, UnitTest *tests, size_t num_of_tests) {

    //assert(fp);
    ASSERT_ERROR(fp);

    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    NumberOfRoots nRoots = NoRoots;
    // fseek - return to very beginning


    // -------- UnitTest TESTS[lines_number] = {}; -- STOP!!!

    for (size_t i = 0; i < num_of_tests; i++) {
        fscanf(fp, "%lf %lf %lf %lf %lf %d\n", &a, &b, &c, &x1, &x2, (int *)&nRoots);

        tests[i].coeffs = {a, b, c};
        tests[i].roots = {x1, x2, nRoots};
    }

    return NoError;
}

Errors GetNumberOfUnitTests(FILE *fp, size_t *num_of_tests) {

    //assert(fp);
    ASSERT_ERROR(fp);

    num_of_tests = 0;

    while(fscanf(fp, "%*[^\n]%*c") != EOF) { //скипаю до \n, а \n как char принимаю и пропускаю *
        num_of_tests++;
    }

    return NoError;
}

Errors Test(void) {

    bool flag = true;

    Roots roots = {NAN, NAN, NoRoots};
    Coeffs coeffs = {NAN, NAN, NAN};

    //unsigned amount_of_tests = (sizeof(TESTS) / (sizeof(UnitTest)));
    //UnitTest lol[2] = {};

    FILE *fp = NULL;
    fp = fopen("UnitTests.txt", "r");
    //assert(fp);
    ASSERT_ERROR(fp);

    size_t num_of_tests = 0;
    RETURN_IF_ERROR(GetNumberOfUnitTests(fp, &num_of_tests));

    //UnitTest** tests = (UnitTest **) calloc(num_of_tests, sizeof(UnitTest *));
    UnitTest* tests = (UnitTest *) calloc(num_of_tests, sizeof(UnitTest));
    //assert(tests);
    if (tests == NULL)
        return TestFuncError;

    /* tests[i]->coeffs.a
    *UnitTest
    UnteTest -> coeffs = (*UnitTest).coeffs

    int a[4] = {};
    a[2]
    *(a + 2)


    (int *)((size_t) b + 1 * sizeof(int *))

    |    |    |    |    |    |

    |1000| 2343 |    |   |
    */

    fseek(fp, 0, SEEK_SET);

    RETURN_IF_ERROR(FillUnitTests(fp, tests, num_of_tests));

    fclose(fp);

    for (size_t test_num = 0; test_num < num_of_tests; test_num++) {
        coeffs = tests[test_num].coeffs;

        RETURN_IF_ERROR(SqrEq(&coeffs, &roots));

        bool is_root_right = true;
        RETURN_IF_ERROR(IsRootsRight(&roots, test_num, tests, &is_root_right));

        flag = flag && is_root_right;
    }

    if (flag) {
        printf("All tests passed\n");
    }

    free(tests);

    return NoError;
}

Errors IsRootsRight(const Roots *roots, int test_num, UnitTest* tests, bool *is_root_right) {

    //assert(roots);
    //assert(tests);
    ASSERT_ERROR(roots);
    ASSERT_ERROR(tests);

    if (roots == NULL || tests == NULL)
        return TestFuncError;

    switch (tests[test_num].roots.number_of_roots) {
        case TwoRoots:
            if (!(((((CompareDoubles(roots->x1, tests[test_num].roots.x1) && CompareDoubles(roots->x2, tests[test_num].roots.x2))) ||
                (((CompareDoubles(roots->x2, tests[test_num].roots.x1) && CompareDoubles(roots->x1, tests[test_num].roots.x2)))))
                && roots->number_of_roots == 2))) {

                RETURN_IF_ERROR(ErrorPrint(roots, test_num, tests));
                *is_root_right = false;
                return NoError;
            }

            break;

        case OneRoot:
            if (!((CompareDoubles(roots->x1, tests[test_num].roots.x1) || CompareDoubles(roots->x2, tests[test_num].roots.x1))
                && roots->number_of_roots == 1)){

                RETURN_IF_ERROR(ErrorPrint(roots, test_num, tests));
                *is_root_right = false;
                return NoError;
            }

            break;

        case Inf:
            if (roots->number_of_roots != Inf) {

                RETURN_IF_ERROR(ErrorPrint(roots, test_num, tests));
                *is_root_right = false;
                return NoError;
            }

            break;

        case NoRoots:
            if ((roots->number_of_roots) != 0) {

                RETURN_IF_ERROR(ErrorPrint(roots, test_num, tests));
                *is_root_right = false;
                return NoError;
            }

            break;

        default:
            *is_root_right = false;
            return NoError;
            break;

    }

    *is_root_right = true;
    return TestFuncError;
}

Errors ErrorPrint(const Roots *roots, int test_num, UnitTest *tests) {

    //assert(roots);
    //assert(tests);
    if (roots == NULL || tests == NULL)
        return TestFuncError;

    printf("The solve is cringe: x1 right = %lg, x2 right = %lg, number of Roots right = %d;\n",
            tests[test_num].roots.x1, tests[test_num].roots.x2, tests[test_num].roots.number_of_roots);
    printf("your x1 = %lg, x2 = %lg, number of Roots = %d\n", roots->x1, roots->x2, roots->number_of_roots);
    printf("Koeffs are: a = %lg, b = %lg, c = %lg",
            tests[test_num].coeffs.a, tests[test_num].coeffs.b, tests[test_num].coeffs.c);

    return NoError;
}
