#include <QCoreApplication>
#include<iostream>
#include<measuremethod.h>
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MeasureMethod method;
    char str[7] = {'a','l','i','b','a','b','a'};
    int len=strlen(str);
//    char str1[7]={'a','l','i','b','a','b','a'};
    method.full_permutation(str,0,6);
    printf("count=%d",method.count);
//    string str1="abc";
//    method.Permutation(str);
//    printf("count=%d",ans(1));

    return a.exec();
}

int main1(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char m='djjidofaadsfdff45';
     char str[8] = {'a','l','i','b','a','b','a'};
    char *p=str;
    cout<<p<<endl;
    cout<<str<<endl;
    return a.exec();
}
