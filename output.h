/*!
\file
\brief ���� � ��������� ������

�������� ������� ������ ������
*/
#ifndef OUTPUT_H_INCLUDED
#define OUTPUT_H_INCLUDED

#include "solving.h"
#include "Errors.h"

/// ����� ������� ���������
///
/// \param roots ����� ���������
///
/// \return NoError, ���� ������������ ������ �������, OutputFuncError � ���� ������
Errors Print(const Roots *roots);

#endif // OUTPUT_H_INCLUDED
