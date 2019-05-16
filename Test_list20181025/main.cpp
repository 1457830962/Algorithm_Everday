#include <QCoreApplication>
#include <iostream>

#include <stdio.h>
using namespace std;



#ifndef _STDIO_H
#define _size_  (5)
#endif




int main(int argc, char *argv[])
{
    QCoreApplication aa(argc, argv);

    int array[_size_] = {0};

    printf("    array = %p\n", array);
    printf("    &array = %p\n", &array);
    printf("    array + 1 = %p\n", array + 1);
    printf("    &array[0] + 1 = %p\n",&array[0] + 1);
    printf("    &array + 1 = %p\n", &array + 1);

    printf("\n");

    printf(" sizeof(array) = %d\n",sizeof(array));
    printf(" sizeof(&array) = %d\n",sizeof(&array));

    printf("\n");

    return aa.exec();
}

