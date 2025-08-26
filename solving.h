#ifndef SOLVING_H_INCLUDED
#define SOLVING_H_INCLUDED

/// Список констант - количество корней
enum ROOTS {
    Inf = -1,
    NoRoots = 0,
    OneRoot = 1,
    TwoRoots = 2
};

/// Коэфф. уравнения
struct Coeffs {
    double a;
    double b;
    double c;
};

/// Корни + количество корней
struct Roots {
    double x1;
    double x2;
    int number_of_roots;
};

/// Функция для решения линейного уравнения
int Linear(const Coeffs *coeffs, Roots *roots);

/// Фукнция для решения квадратного уравнения
int Quadr(const Coeffs *coeffs, Roots *roots);

/// Универсальная решалка
int SqrEq(const Coeffs *coeffs, Roots *roots);

#endif // SOLVING_H_INCLUDED
