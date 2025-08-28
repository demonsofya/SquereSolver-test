/*!
\file
\brief ���� � ��������� �����

�������� ������� ����� �������������
*/
#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "solving.h"
#include "Errors.h"

/// ���� ������������� ���������
///
/// \param coeffs ������������ ����������� ���������
///
/// \return NoError, ���� ������������ ������ �������, InputFuncError � ���� ������
Errors Scan(Coeffs *coeffs);

#endif // INPUT_H_INCLUDED
