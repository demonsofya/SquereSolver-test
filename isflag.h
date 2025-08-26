#ifndef ISFLAG_H_INCLUDED
#define ISFLAG_H_INCLUDED

#include "test.h"

typedef int(*PtrToFlagFunction)(void);

/// ������� �������
int Help(void);

/// �������� ���������� � ������
struct FlagInfo {
    const char *short_name;    ///< �������� ��� �����
    const char *long_name;     ///< ������� ��� �����
    PtrToFlagFunction pointer;
};


/// ������ ������������ ������
const FlagInfo FLAGS_INFO[] = {
    {"-t", "--test", Test},  /// ������ ������
    {"-h", "--help", Help},  /// ������ �������
};

// TODO: array of structs FlagInfo with flags


/// ������� ���������, �������� �� ��������� ������� ������
int IsFlag(int argc, const char *argv[]);

#endif // ISFLAG_H_INCLUDED
