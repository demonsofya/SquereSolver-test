#include <string.h>
# include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
//#include <TXLib.h>

#include "isflag.h"
#include "test.h"

//int lol(double a, double *b);

int IsFlag(int argc, const char **argv) {

    // int (*kek)(double, double *) = lol; // ���������� �������� �� �������

    //FlagInfo k = {};
    //k.pointer = Test; // ���������� � ��������� ������ �������
    //k.pointer(); // ����� �������, ����� ������� � pointer

    assert(argv);

    if (argc == 1)
        return '\0';

    // argc == 1? ���� ��, ������ ������. ���������

    //void* calloc(size_t NumOfElements, size_t SizeOfOneElement//�������� ����� ������


    // �������������!!!!!!!!!!!!!
    PtrToFlagFunction *FlagsArray = (PtrToFlagFunction *) calloc(argc - 1, sizeof(PtrToFlagFunction));  //��������� ����� ������ �� ������ ��������
    //FlagsArray = {};

    unsigned int flags_size = (sizeof(FLAGS_INFO)) / (sizeof(const char *) + (sizeof(const char *) + sizeof(PtrToFlagFunction)));
    //  ���� ����, ������� ������� error ->  ���� ����, ����������� ������, ������� ������, �������
    int iserror_large = 1;
    int iserror_small = 0;
    // ������� �� ��������� ��������� ������� � �������
    int last_flag = 0;
    // ����� ��������� �� ������� � ������
    // ������ ��� ������ ��� ������� ������. ������� �������
    //free(a);  // ������������ ������
    // ������ �������� ������ �������������, ������ ���
    //|   |   |    |    |    |   |

    // | heap | stack memory |

    for (int i = 1; i < argc; i++) {   // argv[1]
        // ����� ������� �������� �� ��������� � �������
        iserror_small = 0;

        for (unsigned int j = 0; j < flags_size; j++) {

            assert(argv[i]);
            assert(FLAGS_INFO[j].short_name);
            assert(FLAGS_INFO[j].long_name);

            if ((strcmp(argv[i], FLAGS_INFO[j].short_name) == 0) || (strcmp(argv[i], FLAGS_INFO[j].long_name) == 0)) {
                iserror_small = 1;
                FlagsArray[last_flag] = FLAGS_INFO[j].pointer;
                last_flag++;
            }

        }

        iserror_large *= iserror_small;

        //if ((strcmp(argv[i], "-t") == 0) || (strcmp(argv[i], "--test") == 0))
        //    return 't';
        //
        //if ((strcmp(argv[i], "-h") == 0) || (strcmp(argv[i], "--help") == 0))
        //    return 'h';

        //printf("ERRROR THE THING YOU JUST INTPUTED IS NOT A FLAG AAAAAAAA");
        //return 'E';
    }

    if (!iserror_large) {

            printf("ERRROR THE THING YOU JUST INTPUTED IS NOT A FLAG AAAAAAAA");
            free(FlagsArray);
            return 'E';

    }


    for (int j = 0; j < last_flag; j++) {

        assert(FlagsArray[j]);
        FlagsArray[j]();

    }

    free(FlagsArray);
    return 'F';
}

int Help(void) {

    printf("--help: manual of programm\n"
           "--test: testing programm on internal tests\n"
           "--No command: enter three koeffs of an equation to solve\n");

    return 0;
}

