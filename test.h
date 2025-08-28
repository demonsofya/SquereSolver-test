/*!
\file
\brief ���� � ��������� UnitTest

�������� ����������� ��������� UnitTest,
������� ������ ������������, ������� �������� ������������ ������,
��� ������� ��� ���������� ������� �� �����
*/
#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include "solving.h"
#include "Errors.h"

/// ���������, �������� ���� ���������
struct UnitTest {
    Coeffs coeffs; ///< ������������ ���������
    Roots roots;   ///< ����� ���������
};

/*UnitTest TESTS[6] =
{
        //coeffs        //roots
    {   {1, -5, 6},     {2, 3, 2}   },
    {   {0, 0, 0},      {0, 0, Inf} },
    {   {1, 0, -4},     {2, -2, 2}  },
    {   {1, 1, 1},      {2, -2, 0}  },
    {   {0, 1, 1},      {-1, -1, 1} },
    {   {1, -12, 36},   {6, 6, 1}   },
};*/

/// ��������� ������ UnitTest �� �����
///
/// \param fp ��������� �� ����, �� �������� ��������� ������������
/// \param tests ��������� �� ������, � ������� ��������� ������������
/// \param num_of_tests ���������� ������ � �����
///
/// \return NoError, ���� ���������� ������ �������, TestFuncError �����
Errors FillUnitTests(FILE *fp, UnitTest *tests, size_t num_of_tests);

/// ���������� ���������� ����� � �����
///
/// \param fp ��������� �� ����, � ������� ������� ������
///
/// \return NoError, ���� ������� ������ �������, TestFuncError �����
size_t GetNumberOfUnitTests(FILE *fp);

/// ��������� ����
///
/// \return NoError, ���� ������������ ������ �������, TestFuncError �����
Errors Test(void);

/// �������, ����������� ����� �� ������������
///
/// \param roots ����� ���������
/// \param test_num ����� �����
/// \param tests ������ ������
/// \param is_root_right ��������� �� ���, � ������� ������������ ���������� �� ����
///
/// \return NoError, ���� �������� ������ �������, TestFuncError �����
Errors IsRootsRight(const Roots *roots, int test_num, UnitTest* tests, bool *is_root_right);

/// ������� ������ ������
///
/// \param roots ����� ���������
/// \param test_num ����� �����
/// \param tests ������ ������
///
/// \return NoError, ���� ����� ������ �������, TestFuncError �����
Errors ErrorPrint(const Roots *roots, int test_num, UnitTest *tests);

#endif // TEST_H_INCLUDED
