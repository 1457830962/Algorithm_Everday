// MyProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "BinarySearch.h"
#include "FullPermutation/measuremethod.h"


int main()
{
	/**********************简单的二分查找应用*********************/
	//CBinarySearch method;
	//method.Link_BinarySearch();
	/************************************************************/

	MeasureMethod method;
	char str[7] = { 'a','l','i','b','a','b','a' };
	int len = strlen(str);
	int *p = &len;
	len = sizeof(p);
	//    char str1[7]={'a','l','i','b','a','b','a'};
	method.full_permutation(str, 0, 6);
	printf("count=%d", method.count);

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