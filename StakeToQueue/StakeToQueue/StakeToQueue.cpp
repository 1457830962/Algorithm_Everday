// StakeToQueue.cpp : 定义控制台应用程序的入口点。
/************************************************************************/
/*  功能：利用堆栈实现队列的先进先出的特性                                                                   */
/************************************************************************/


#include "stdafx.h"
#include "Solution.h"


void swap_int(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap_int1(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}


void swap_str(char*a, char*b)
{
	char*temp = a;
	a = b;
	b = temp;
}

void swap_str1(char*&a, char*&b)
{
	char*temp = a;
	a = b;
	b = temp;
}

int main()
{
	/*Solution test;
	test.push(113);
	test.push(112);
	int a = test.pop();
	cout << "弹出的值:" << a << endl;
	getchar();*/

	//值传递
		int a = 10;
		int b = 5;
		char*str_a = "hello world";
		char*str_b = "world hello";
		swap_int(a, b);
		swap_str(str_a, str_b);		
		printf("%d %d %s %s\n", a, b, str_a, str_b);//都是按值传递  所以未进行值交换   如要进行值交换可以传递指针的地址进行交换
		swap_int1(a, b);
		swap_str1(str_a, str_b);
		printf("%d %d %s %s\n", a, b, str_a, str_b);//都是按值传递  所以未进行值交换   如要进行值交换可以传递指针的地址进行交换
		getchar();
	return 0;
}

