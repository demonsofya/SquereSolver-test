#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "mathematics.h"
#include "solving.h"
#include "test.h"

//UnitTest TESTS[6] = {}; -- // TODO: remove

void FillUnitTests(FILE *fp, UnitTest *tests, size_t num_of_tests) {

    assert(fp);

    //FILE *fp = NULL;
    //fp = fopen("UnitTests.txt", "r");

    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    NumberOfRoots nRoots = NoRoots;
    // fseek - return to very beginning

    /*while(fscanf(fp, "%*[^\n]%*c") != EOF) {
        num_of_tests++;
    } */

    // calloc (lines_number, sizeof(...))
    // -------- UnitTest TESTS[lines_number] = {}; -- STOP!!!

    for (size_t i = 0; i < num_of_tests; i++) {
        fscanf(fp, "%lf %lf %lf %lf %lf %d\n", &a, &b, &c, &x1, &x2, (int *)&nRoots);

        tests[i].coeffs = {a, b, c};
        tests[i].roots = {x1, x2, nRoots};

        //printf("%lf %lf %lf %lf %lf %d\n", a, b, c, x1, x2, nRoots);
    }
}

size_t GetNumberOfUnitTests(FILE *fp) {

    assert(fp);

    size_t num_of_tests = 0;

    while(fscanf(fp, "%*[^\n]%*c") != EOF) { //скипаю до \n, а \n как char принимаю и пропускаю *
        num_of_tests++;
    }

    return num_of_tests;
}

/*unsigned int UnitTestFile(void) {
    UnitTest TESTS[6];

    FILE *fp;
    fp = fopen("UnitTests.txt", "r");
    double a, b, c;
    double x1, x2;
    int nRoots;
    unsigned int lines_count = 0;
    while(fscanf(fp, "%lf %lf %lf %lf %lf %d", &a, &b, &c, &x1, &x2, &nRoots) != EOF) {
        TESTS[lines_count].coeffs = {a, b, c};
        TESTS[lines_count].roots = {x1, x2, nRoots};
        lines_count++;
    }
    fclose(fp);

    return lines_count;
} */

int Test(void) {

    bool flag = true;

    Roots roots = {NAN, NAN, NoRoots};
    Coeffs coeffs = {NAN, NAN, NAN};

    //unsigned amount_of_tests = (sizeof(TESTS) / (sizeof(UnitTest)));

    // TODO: FILE *

    // TODO: getNumberOfUnitTests(FILE *)

    FILE *fp = NULL;
    fp = fopen("UnitTests.txt", "r");
    assert(fp);

    size_t num_of_tests = GetNumberOfUnitTests(fp);
    //printf("%d\n", num_of_tests); // это оно правильно делает, победа

    UnitTest* tests = (UnitTest *) calloc(num_of_tests, sizeof(UnitTest));
    assert(tests);

    fseek(fp, 0, SEEK_SET);
    // TODO: fillUnitTests(FILE *, UnitTest *, size_t num_tests)
    FillUnitTests(fp, tests, num_of_tests);

    // fclose()
    fclose(fp);

    // TODO: remove unsigned int amount_of_tests = UnitTestFile();

    for (size_t test_num = 0; test_num < num_of_tests; test_num++) {

        //assert(tests[test_num].coeffs.a);
        //assert(tests[test_num].coeffs.b);
        //assert(tests[test_num].coeffs.c);

        //assert(tests[test_num].roots.x1);
        //assert(tests[test_num].roots.x2);
        //assert(tests[test_num].roots.number_of_roots);

        coeffs = tests[test_num].coeffs;   // TODO: TESTS to tests

        roots.number_of_roots = SqrEq(&coeffs, &roots);

        flag = flag && IsRootsRight(&roots, test_num, tests);
    }

    if (flag) {
        printf("All tests passed\n");
    }

    free(tests);

    return 0;
}

bool IsRootsRight(const Roots *roots, int test_num, UnitTest* tests) {

    assert(roots);
    assert(tests);

    switch (tests[test_num].roots.number_of_roots) {
        case TwoRoots:
            if (!(((((CompareDoubles(roots->x1, tests[test_num].roots.x1) && CompareDoubles(roots->x2, tests[test_num].roots.x2))) ||
                (((CompareDoubles(roots->x2, tests[test_num].roots.x1) && CompareDoubles(roots->x1, tests[test_num].roots.x2)))))
                && roots->number_of_roots == 2))) {

                ErrorPrint(roots, test_num, tests);
                return false;
            }

            break;

        case OneRoot:
            if (!((CompareDoubles(roots->x1, tests[test_num].roots.x1) || CompareDoubles(roots->x2, tests[test_num].roots.x1))
                && roots->number_of_roots == 1)){

                ErrorPrint(roots, test_num, tests);
                return false;
            }

            break;

        case Inf:
            if (roots->number_of_roots != Inf) {

                ErrorPrint(roots, test_num, tests);
                return false;
            }

            break;

        case NoRoots:
            if ((roots->number_of_roots) != 0) {

            ErrorPrint(roots, test_num, tests);
            return false;
            }

            break;

        default:
            return true;
            break;

    }

    return true;
}

void ErrorPrint(const Roots *roots, int test_num, UnitTest *tests) {

    assert(roots);
    assert(tests);

    printf("The solve is cringe: x1 right = %lg, x2 right = %lg, number of Roots right = %d;\n",
            tests[test_num].roots.x1, tests[test_num].roots.x2, tests[test_num].roots.number_of_roots);
    printf("your x1 = %lg, x2 = %lg, number of Roots = %d\n", roots->x1, roots->x2, roots->number_of_roots);
    printf("Koeffs are: a = %lg, b = %lg, c = %lg",
            tests[test_num].coeffs.a, tests[test_num].coeffs.b, tests[test_num].coeffs.c);
}
