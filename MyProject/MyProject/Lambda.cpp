#include "Lambda.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#include "log4cxx/logger.h"
#include "log4cxx/propertyconfigurator.h"
using namespace log4cxx;

bool cmp(int a, int b)
{
	return  a < b;
}

CLambda::CLambda() 
{
}

CLambda::~CLambda(void)
{
}

void CLambda::Execute()
{
	vector<int> myvec{ 3, 2, 5, 7, 3, 2 };
	vector<int> lbvec(myvec);

	sort(myvec.begin(), myvec.end(), cmp); // 旧式做法
	cout << "predicate function:" << endl;
	for (int it : myvec)
		cout << it << ' ';
	cout << endl;

	sort(lbvec.begin(), lbvec.end(), [](int a, int b) -> bool { return a < b; });   // Lambda表达式
	cout << "lambda expression:" << endl;
	for (int it : lbvec)
		cout << it << ' ';
	cout << endl;
}