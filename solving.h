#ifndef SOLVING_H_INCLUDED
#define SOLVING_H_INCLUDED

enum ROOTS {
    Inf = -1,
    NoRoots = 0,
    OneRoot = 1,
    TwoRoots = 2
};

struct Coeffs {
    double a;
    double b;
    double c;
};

struct Roots {
    double x1;
    double x2;
    int number_of_roots;
};

int Linear(const Coeffs *coeffs, Roots *roots);

int Quadr(const Coeffs *coeffs, Roots *roots);

int SqrEq(const Coeffs *coeffs, Roots *roots);

#endif // SOLVING_H_INCLUDED
