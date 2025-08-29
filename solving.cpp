#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#include "solving.h"
#include "mathematics.h"
#include "Errors.h"

Errors Linear(const Coeffs *coeffs, Roots *roots) {

    ASSERT_ERROR(roots);
    ASSERT_ERROR(coeffs);

    if (CompareDoubles(coeffs->b, 0)) {
        if (CompareDoubles(coeffs->c, 0)) {
            roots->number_of_roots = Inf;
            return NoError;
        }

        roots->number_of_roots = NoRoots;
        return NoError;
    }

    roots->x1 = - coeffs->c / coeffs->b;
    roots->number_of_roots = OneRoot;

    return NoError;
}

Errors Quadr(const Coeffs *coeffs, Roots *roots) {

    ASSERT_ERROR(roots);
    ASSERT_ERROR(coeffs);

    const double discr = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c; /* discriminant */

    if (discr < 0) {
        roots->number_of_roots = NoRoots;
        return NoError;
    }

    if (CompareDoubles(discr, 0)) {
        roots->x1 = - coeffs->b / (2 * coeffs->a);
        roots->number_of_roots = OneRoot;
        return NoError;
    }

    const double sqr = sqrt(discr);
    roots->x1 = (-coeffs->b + sqr) / (2 * coeffs->a);
    roots->x2 = (-coeffs->b - sqr) / (2 * coeffs->a);

    roots->x1 = - coeffs->b / (2 * coeffs->a);
    roots->number_of_roots = TwoRoots;
    return NoError;
}

Errors SqrEq(const Coeffs *coeffs, Roots *roots) { /* function for solving squere equation */

    ASSERT_ERROR(roots);
    ASSERT_ERROR(coeffs);

    if (CompareDoubles(coeffs->a, 0)) { /*Linear variant */
        RETURN_IF_ERROR(Linear(coeffs, roots));
        return NoError;
    }

    RETURN_IF_ERROR(Quadr(coeffs, roots));
    return NoError;
}
