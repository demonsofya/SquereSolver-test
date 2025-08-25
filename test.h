#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "solving.h"

struct UnitTest {
    Coeffs coeffs;
    Roots roots;
};

const UnitTest TESTS[6] = {
        //coeffs        //roots
    {   {1, -5, 6},     {2, 3, 2}   },
    {   {0, 0, 0},      {0, 0, Inf} },
    {   {1, 0, -4},     {2, -2, 2}  },
    {   {1, 1, 1},      {2, -2, 0}  },
    {   {0, 1, 1},      {-1, -1, 1} },
    {   {1, -12, 36},   {6, 6, 1}   },
};

int Test(void);

bool IsRootsRight(const Roots *roots, int test_num);

void ErrorPrint(const Roots *roots, int test_num);

#endif // TEST_H_INCLUDED
