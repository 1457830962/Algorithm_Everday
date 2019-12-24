#include<map>
#include<string>
#include<iostream>
using namespace std;

void map_Value_type(map<int, string> &mapst);
void map_Pair(map<int, string> &mapst);
void map_Array(map<int, string> &mapst);
bool judgeSuccessInsert();

int main(){
	map<int, string> mapst;
	//mapst.clear();清空map
	//map_Value_type(mapst);
	map_Value_type(mapst);
	int nSize = mapst.size();//获取map的大小
	judgeSuccessInsert();//判断是否插入成功


	//如果要删除1,用迭代器删除  
	map<int, string>::iterator iter1;
	iter1 = mapst.find(1);//删除Key为1的项
	mapst.erase(iter1);

	int n = mapst.erase(1);//如果删除了会返回1，否则返回0
	map<int, string>::iterator it;
	for (it = mapst.begin(); it != mapst.end(); it++)
		cout << it->first << " " << it->second << endl;

	//反向输出
	map<int, string>::reverse_iterator iter;
	for (iter = mapst.rbegin(); iter != mapst.rend(); iter++)
		cout << iter->first << "  " << iter->second << endl;

	//数组形式输出
	for (int nindex = 1; nindex <= mapst.size(); nindex++)
		cout << mapst[nindex] << endl;


	system("pause");
	return 0;
}

//2. 用insert函数插入value_type
void map_Value_type(map<int, string> &mapst)
{
	mapst.insert(map<int, string>::value_type(1, "student1_Value"));
	mapst.insert(map<int, string>::value_type(2, "student2_Value"));
	mapst.insert(map<int, string>::value_type(3, "student3_Value"));
	return;
}
//1. 用insert插入pair数据 
void map_Pair(map<int, string> &mapst)
{
	mapst.insert(pair<int, string>(1, "student1_Pair"));
	mapst.insert(pair<int, string>(2, "student2_Pair"));
	mapst.insert(pair<int, string>(3, "student3_Pair"));
	return;
}
//3. 用数组方式插入
void map_Array(map<int, string> &mapst)
{
	mapst[1] = "student1_Array";
	mapst[2] = "student2_Array";
	mapst[3] = "student3_Array";	
	return;
}
//判断是否insert成功
bool judgeSuccessInsert()
{
	map<int, string> mapStudent;
	pair<map<int, string>::iterator, bool> Insert_Pair;
	mapStudent.insert(map<int, string>::value_type(1, "student_one"));
	Insert_Pair = mapStudent.insert(map<int, string>::value_type(1, "student_two"));
	return Insert_Pair.second;

}
