// StakeToQueue.cpp : �������̨Ӧ�ó������ڵ㡣
/************************************************************************/
/*  ���ܣ����ö�ջʵ�ֶ��е��Ƚ��ȳ�������                                                                   */
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
	cout << "������ֵ:" << a << endl;
	getchar();*/

	//ֵ����
		int a = 10;
		int b = 5;
		char*str_a = "hello world";
		char*str_b = "world hello";
		swap_int(a, b);
		swap_str(str_a, str_b);		
		printf("%d %d %s %s\n", a, b, str_a, str_b);//���ǰ�ֵ����  ����δ����ֵ����   ��Ҫ����ֵ�������Դ���ָ��ĵ�ַ���н���
		swap_int1(a, b);
		swap_str1(str_a, str_b);
		printf("%d %d %s %s\n", a, b, str_a, str_b);//���ǰ�ֵ����  ����δ����ֵ����   ��Ҫ����ֵ�������Դ���ָ��ĵ�ַ���н���
		getchar();
	return 0;
}

