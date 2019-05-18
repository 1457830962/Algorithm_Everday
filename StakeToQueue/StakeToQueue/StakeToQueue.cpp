// StakeToQueue.cpp : 定义控制台应用程序的入口点。
/************************************************************************/
/*  功能：利用堆栈实现队列的先进先出的特性                                                                   */
/************************************************************************/


#include "stdafx.h"
#include "Solution.h"

int main()
{
	Solution test;
	test.push(113);
	test.push(112);
	int a = test.pop();
	cout << "弹出的值:" << a << endl;
	getchar();
	return 0;
}

