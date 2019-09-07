#include<map>
#include<string>
#include<iostream>
using namespace std;
//1. 用insert插入pair数据 
int main(){
	map<int, string> mapst;
	mapst.insert(pair<int, string>(1, "student1"));
	mapst.insert(pair<int, string>(2, "student2"));
	mapst.insert(pair<int, string>(3, "student3"));
	map<int, string>::iterator it;
	for (it = mapst.begin(); it != mapst.end(); it++)
		cout << it->first << " " << it->second << endl;
	system("pause");
	return 0;
}


//2. 用insert函数插入value_type

int main1(){
	map<int, string> mapst;
	mapst.insert(map<int, string>::value_type(1, "student1"));
	mapst.insert(map<int, string>::value_type(2, "student2"));
	mapst.insert(map<int, string>::value_type(3, "student3"));
	map<int, string> ::iterator it;
	for (it = mapst.begin(); it != mapst.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}

//3. 用数组方式插入

int main2(){
	map<int, string> mapst;
	mapst[1] = "student1";
	mapst[2] = "student2";
	mapst[3] = "student3";
	map<int, string> ::iterator it;
	for (it = mapst.begin(); it != mapst.end(); it++)
		cout << it->first << " " << it->second << endl;
	return 0;
}