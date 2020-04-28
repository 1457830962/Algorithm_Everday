#include "Pointer.h"
#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct str_t {
	long long len;
	char data[32];
};
struct data1_t {
	long long len;
	int data[2];
};
struct data2_t {
	long long len;
	char *data[1];
};
struct data3_t {
	long long len;
	void *data[];
};



Pointer::Pointer()
{

}

int Pointer::len(char *str)
{
	int i = 0;
	while (*(str))     //用while判断字符数组元素不为0
	{
		str++;
		i++;           // i的值就是当前字符数组的长度
	}
	return i;
}


void Pointer::change(int*ab, int&b, int c)
{
	//cout << "被调函数修改前ab：" << &ab << endl;
	//cout << &c << endl;
	//c = *ab;
	//cout << &c << endl;
	//b = 30;
	//*ab = 20;
	//cout << &ab << endl;
}

char Pointer::f(char *s)
{
	char ch = 'A';
	return ch;
}

int Pointer::TestOne()
{

	//    int *p = NULL;
	//    int aa = 1;
	//    printf("p指针存储的地址：%p\n", p);
	//    printf("p指针的地址：%p\n", &p);
	//    cout<<endl;

	//    p = &aa;
	//    printf("p指针存储的a地址：%p\n", p);
	//    printf("p指针的地址：%p\n", &p);
	//    cout<<endl;

	//    *p = 2;
	//    printf("p指针存储的对a重新赋值时地址：%p\n", p);
	//    printf("p指针的地址：%p\n", &p);
	//    cout<<endl;

	//    int b = 2;
	//    p = &b;
	//    printf("p指针存储的b地址：%p\n", p);
	//    printf("p指针的地址：%p\n", &p);

	//    int ab=10, b=20, c=30;
	//    cout<<"主函数修改前ab："<<&ab<<endl;
	//    cout<<&c<<endl;
	//    change(&ab,b,c);
	//    cout<<&c<<endl;
	//    cout<<&ab<<endl;
	//    printf ("%d,%d,%d",ab,b,c);

	//    const int i = 0;
	//    int *j = (int *) &i;
	//    *j = 1;
	//    printf("%d,%d,", i, *j);
	int intarray[] = { 1,2,3 };
	int *p = intarray;
	*p++;
	(*p)++;
	*p++;
	(*p)++;
	for (int i = 0; i < 3; i++)
		cout << intarray[i] << endl;
	cout << &intarray[2] << " " << p << endl;


	return 0;
}



int Pointer::TestTwo(void)
{
	struct str_t str;
	memset((void*)&str, 0, sizeof(struct str_t));
	int n = sizeof(long long);
	cout << n << endl;
	str.len = sizeof(struct str_t) - sizeof(int);
	snprintf(str.data, str.len, "hello");//VS 下为_snprintf
	//    int n=sizeof(int);
	//    cout<<n<<endl;
	//    struct data3_t *pData=(struct data3_t*)&str;
	//    printf("data:%s%s\n",str.data,(char*)(&(pData->data[0])));
	//    int x=1;
	//    int y=2;
	//    printf("%d%d%d",x+y,x++,y++);


	struct data2_t *pData = (struct data2_t*)&str;
	printf("data:%s%s\n", str.data, (char*)(pData->data[0]));

	return 0;
}




int Pointer::TestThree()
{
	//const char *p = "helppppppppppn";
	//int m = len(p);
	//cout << "字符串长度：" << m << endl;
	return 0;
}