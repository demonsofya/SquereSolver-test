#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "mathematics.h"
#include "solving.h"


int Linear(const Coeffs *coeffs, Roots *roots) {

    assert (roots != NULL);
    assert (coeffs != NULL);

    if (CompareDoubles(coeffs->b, 0)) {
        if (CompareDoubles(coeffs->c, 0))
            return Inf;

        return NoRoots;
    }

    roots->x1 = - coeffs->c / coeffs->b;

    return OneRoot;
}

int Quadr(const Coeffs *coeffs, Roots *roots) {

    assert (roots != NULL);
    assert (coeffs != NULL);         //когда у меня strucs передан по указателю, надо бахать ->

    double discr = coeffs->b * coeffs->b - 4 * coeffs->a * coeffs->c; /* дискриминант */

    if (discr < 0)
        return NoRoots;

    if (CompareDoubles(discr, 0)) {
        roots->x1 = - coeffs->b / (2 * coeffs->a);
        return OneRoot;
    }

    double sqr = sqrt(discr);
    roots->x1 = (-coeffs->b + sqr) / (2 * coeffs->a);
    roots->x2 = (-coeffs->b - sqr) / (2 * coeffs->a);

    return TwoRoots;
}

int SqrEq(const Coeffs *coeffs, Roots *roots) { /* функция, которая решает квадратное уравнение */

    assert (roots != NULL);
    assert (coeffs != NULL);      /* ошибочки */

    if (CompareDoubles(coeffs->a, 0)) { /* вариант, когда уравнение линейное */
        return Linear(coeffs, roots);
    }

    return Quadr(coeffs, roots);
}
