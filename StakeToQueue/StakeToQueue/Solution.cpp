#include "stdafx.h"
#include "Solution.h"

void Solution::push(int node) {
	stack1.push(node);
}

int Solution::pop()
{
	int tmp;
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			tmp = stack1.top();
			stack2.push(tmp);
			stack1.pop();
		}
	}
	tmp = stack2.top();
	stack2.pop();
	return tmp;
}

