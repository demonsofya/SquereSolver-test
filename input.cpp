#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "solving.h"
#include "input.h"

int Scan(Coeffs *coeffs) {

    assert (coeffs != NULL);

    printf("The quadratic equation solver\n");
    printf("Enter three number: \n");

    int ReadenCount = 0;
    int NewSimbol = 0;

    while (true) {

        ReadenCount = 0;
        ReadenCount = scanf("%lf %lf %lf", &(coeffs->a), &(coeffs->b), &(coeffs->c));
        NewSimbol = getchar();

        if (ReadenCount != 3 || !(NewSimbol == EOF || isspace(NewSimbol))) {

            scanf ("%*[^\n]");
            printf("Try again\n");
            continue;

        }

        return 1;
    }

    return 0;
}
