#include <math.h>
#include <stdio.h>

#include "mathematics.h"
#include "solving.h"

bool CompareDoubles(double a, double b) {   /*сравнение даблов */

    return (fabs(a - b) < EPS);
}
