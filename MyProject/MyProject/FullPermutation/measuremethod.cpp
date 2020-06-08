#include "measuremethod.h"
#include <set>
#include <algorithm>
using namespace std;

int MeasureMethod::count = 0;

MeasureMethod::MeasureMethod()
{

}

void MeasureMethod::swap(char* str, int a, int b)
{
	char tmp = str[a];
	str[a] = str[b];
	str[b] = tmp;
}


//判断从子串的第一个字符串开始，直到k-1位置，看是否有重复的字符
int MeasureMethod::is_swap(char *str, int begin, int k)
{
	int i, flag;
	for (i = begin, flag = 1; i < k; i++)
	{
		if (str[i] == str[k])
		{
			flag = 0;
			break;
		}
	}
	return flag;
}

void MeasureMethod::full_permutation(char* str, int begin, int end)
{
	if (begin == end)
	{
		count++;//此处可以输出字符串或者记录字符串
		return;
	}
	else
	{
		int i;
		for (i = begin; i <= end; i++)
		{
			if (is_swap(str, begin, i))
			{
				swap(str, begin, i);
				full_permutation(str, begin + 1, end);
				swap(str, begin, i);
			}
		}
	}
}


void MeasureMethod::PermutationHelp(vector<string> &ans, int k, string str) //遍历第k位的所有可能
{
	//   if(k == str.size() - 1)
	//       ans.push_back(str);
	   //unordered_set<char> us;  //记录出现过的字符
	//   sort(str.begin() + k, str.end());  //保证按字典序输出
	//   for(int i = k; i < str.size(); i++)
	//   {
	//       if(us.find(str[i]) == us.end()) //只和没交换过的换
	//       {
	//           us.insert(str[i]);
	//           swap(str[i], str[k]);
	//           PermutationHelp(ans, k + 1, str);
	//           swap(str[i], str[k]);  //复位
	//       }
	//   }
}

vector<string> MeasureMethod::Permutation(string str)
{
	vector<string> ans;
	PermutationHelp(ans, 0, str);
	return ans;
}

void MeasureMethod::Execute()
{
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
}