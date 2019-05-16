#include <QCoreApplication>
#include<iostream>
#include <vector>
using namespace std;



///***************插入排序(写法一)***************///
void InsertSort(int a[], int n)
{
    for (int j = 1; j < n; j++)  //思考这里j为啥从1开始  因为有一个元素是先排好序的
    {

        int key = a[j]; //待排序第一个元素
        int i = j - 1;  //代表已经排过序的元素最后一个索引数
        while (i >= 0 && key < a[i])
        {
            //从后向前逐个比较已经排序过数组，如果比它小，则把后者用前者代替，
            //其实说白了就是数组逐个后移动一位,为找到合适的位置时候便于Key的插入
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = key;//找到合适的位置了，赋值,在i索引的后面设置key值。
    }
}

///***************插入排序(写法二)***************///
void InsertSort2(vector<int> &num){
    for(int i = 1;i < num.size();++i){
        for(int j = i;j > 0;--j){
            if(num[j] < num[j - 1]){
                int temp = num[j];
                num[j] = num[j-1];
                num[j-1] = temp;
            }
        }
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int d[] = { 30,20,10,25,15,28 };
    cout << "输入数组  { 30,20,10,25,15,28 } " << endl;
    vector<int> v;
    v.push_back(12);
    v.push_back(15);
    v.push_back(9);
    v.push_back(20);
    v.push_back(6);
    v.push_back(31);
    v.push_back(24);

    InsertSort(d,6);
//    InsertSort2(v);
    cout << "排序后结果：";
    //***利用下标遍历数组***//
//    for (int i = 0; i < 7; i++)
//    {
//        cout << v[i]<<" ";
//    }
    //***利用***//
    vector<int>::const_iterator iterator = v.begin();
      for(;iterator != v.end();iterator++)
      {
         cout<<*iterator<<" ";

      }




    return a.exec();
}