#include <QCoreApplication>

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    string str,res;
    cin>>str;

    //12345646
    int same_cnt=1,i=0;
    for ( i = 0; i < str.size()-1; ++i)
    {
        if(str[i]==str[i+1])
        {
            same_cnt++;
        }else
        {
            cout<<same_cnt;
            cout<<str[i];
            same_cnt=1;
        }
    }

    cout<<same_cnt;
    cout<<str[i];

    return a.exec();
}
