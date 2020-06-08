#ifndef MEASUREMETHOD_H
#define MEASUREMETHOD_H

#include<vector>
using namespace std;
class MeasureMethod
{
public:
     static int count ;
    MeasureMethod();
    void swap(char* str,int a,int b);
    int is_swap(char *str, int begin, int k);
    void full_permutation(char* str,int begin,int end);

    //Second way
    void PermutationHelp(vector<string> &ans, int k, string str); //遍历第k位的所有可能
    vector<string>  Permutation(string str);

	void Execute();
};


#endif // MEASUREMETHOD_H
