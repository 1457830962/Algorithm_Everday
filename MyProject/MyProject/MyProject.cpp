// MyProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BinarySearch.h"
#include "FullPermutation/measuremethod.h"

#include "log4cxx/logger.h"
#include "log4cxx/propertyconfigurator.h"

using namespace log4cxx;


int main()
{
	log4cxx::PropertyConfigurator::configure("./log4cxx/log4cxx(everyday).properties");//加载日志配置

	/**********************简单的二分查找应用*********************/
#if 0
	CBinarySearch method;
	method.Link_BinarySearch();
#endif
	/************************************************************/

	/***************************全排列应用************************/
#if 1
	MeasureMethod method;
	char str[7] = { 'a','l','i','b','a','b','a' };
	int len = strlen(str);
	int *p = &len;
	len = sizeof(p);

	for (int i = 0; i < 100; i++)
	{
		i = i;
	}
	method.full_permutation(str, 0, 6);
	printf("count=%d", method.count);
#endif
	/************************************************************/


	LOG4CXX_INFO(log4cxx::Logger::getLogger("main()"), "end...");
	LOG4CXX_ERROR(log4cxx::Logger::getLogger("main()"), "end...");
	system("pause");
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file