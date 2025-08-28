/*!
\file
\brief ���� � ��������� ��������, �������� �� �������� � ������� ������

�������� ��������� ������,
��������� ���� �����

���� �������, ��������� ������� � ��������� �� �������, ������� ���������� ���� ��
*/
#ifndef ISFLAG_H_INCLUDED
#define ISFLAG_H_INCLUDED

#include "test.h"
#include "Errors.h"

/// Enum ���� �����
enum Flags {
    FLAGS_SCAN_ERROR,   ///< ������
    FLAGS_SCAN_SUCCESS, ///< ���� ������
    NO_FLAG             ///< ������ �� ����
};

typedef Errors(*PtrToFlagFunction)(void);

/// ������� �������
///
/// \return NoError ���� ��� ������ �������, IsflagFuncError � ���� ������
Errors Help(void);

/// �������� ���������� � ������
struct FlagInfo {
    const char *short_name;    ///< �������� ��� �����
    const char *long_name;     ///< ������� ��� �����
    PtrToFlagFunction pointer; ///< ��������� �� �������, ������� ����������� ������
};


/// ������ ������������ ������
const FlagInfo FLAGS_INFO[] = {
    {"-t", "--test", Test},  ///< ������ ������
    {"-h", "--help", Help}   ///< ������ �������
};


/// ������� ���������, �������� �� ��������� ������� ������
///
/// \param argc ������ ������� argv
/// \param argv ��������� �� ������ ��������� �����
/// \param flag ��������� �� ����, � ������� ��������� �������� �� ����
///
/// \return NoError, ���� ������������ ������ �������, IsflagFuncError � ���� ������
Errors IsFlag(int argc, const char *argv[], Flags *flag);

#endif // ISFLAG_H_INCLUDED
