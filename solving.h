#ifndef SOLVING_H_INCLUDED
#define SOLVING_H_INCLUDED

/// Список констант - количество корней
enum NumberOfRoots { //camel case   GetUserInput // структуры, енамы, функции
    Inf = -1,        //snake case   get_user_input // локальные перменные, аргументы фнкциии
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
    NumberOfRoots number_of_roots;
};

/// Функция для решения линейного уравнения
NumberOfRoots Linear(const Coeffs *coeffs, Roots *roots);

/// Фукнция для решения квадратного уравнения
NumberOfRoots Quadr(const Coeffs *coeffs, Roots *roots);

/// Универсальная решалка
NumberOfRoots SqrEq(const Coeffs *coeffs, Roots *roots);

#endif // SOLVING_H_INCLUDED
