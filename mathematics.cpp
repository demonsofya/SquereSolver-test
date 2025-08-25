#include <math.h>
#include <stdio.h>

#include "mathematics.h"
#include "solving.h"

bool CompareDoubles(double a, double b) {   /*Comparing double nums */

    return (fabs(a - b) < EPS);
}
