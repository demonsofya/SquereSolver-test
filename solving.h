/*!
\file
\brief ���� � ��������� ������� ���������

�������� ����������� ��������� ���������� ������,
��������� �������������, ��������� ������

���� ������� ������� �������������, ����������� ���������, ��������� ���������
*/
#ifndef SOLVING_H_INCLUDED
#define SOLVING_H_INCLUDED

#include "Errors.h"

/// ������ �������� - ���������� ������
enum NumberOfRoots { //camel case   GetUserInput // ���������, �����, �������
    Inf = -1, ///< ����������� ���������� ������
    //snake case   get_user_input // ��������� ���������, ��������� �������
    NoRoots = 0, ///< ��� ������
    OneRoot = 1, ///< ���� ������
    TwoRoots = 2 ///< ��� �����
};

/// �����. ���������
struct Coeffs {
    double a;  ///< ����������� ��� ����� ������ �������
    double b;  ///< ����������� ��� ����� ������ �������
    double c;  ///< ��������� �����������
};

/// ����� + ���������� ������
struct Roots {
    double x1; ///< ������ ������
    double x2; ///< ������ ������
    NumberOfRoots number_of_roots;  ///< ���������� ������
};

/// ������� ��� ������� ��������� ���������
///
/// \param coeffs ������������ ���������
/// \param roots ����� ���������
///
/// \return NoError, ���� ������� ������ �������, SolvingFuncError �����
Errors Linear(const Coeffs *coeffs, Roots *roots);

/// ������� ��� ������� ����������� ���������
///
/// \param coeffs ������������ ���������
/// \param roots ����� ���������
///
/// \return NoError, ���� ������� ������ �������, SolvingFuncError �����
Errors Quadr(const Coeffs *coeffs, Roots *roots);

/// ������������� �������
///
/// \param coeffs ������������ ���������
/// \param roots ����� ���������
///
/// \return NoError, ���� ������� ������ �������, SolvingFuncError �����
Errors SqrEq(const Coeffs *coeffs, Roots *roots);

#endif // SOLVING_H_INCLUDED
