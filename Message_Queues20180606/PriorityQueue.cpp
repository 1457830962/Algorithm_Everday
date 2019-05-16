#include<iostream>
#include<string>
#include"PriorityItem.cpp"


//class creates and deals with priority queues
template<typename type>
class priorityQueue {
private:
    int size, count;
    priorityItem<type>* ptr;
public:
    //default constructor
    priorityQueue() {
        size = 5;   //初始化队列大小
        count = 0;   //对列入队计数
        ptr = new priorityItem<type>[size];   //new出size个大小的数据项
    }
    //parameterized constructor
    priorityQueue(int size) {
        this->size = size;
        count = 0;
        ptr = new priorityItem<type>[size];
    }
    /*priorityCheck function is used by the add function to get the index
     where the new priorityItem type object is stored*/
    int priorityCheck(int priority){
        if (count == 1)
            return 0;
        else if (priority < ptr[0].getPriority()) {//首先判断与首个元素的优先级
            for (int i = (count - 1); i > 0; i--) //调整每个数据的优先级位置
                ptr[i] = ptr[i - 1];
            return 0;
        }
        else {
            for (int i = 0; i < (count - 1); i++) {//优先级不小于首个元素情况下： 依次判断与其他元素优先级
                if (priority < ptr[i].getPriority()) {
                    for (int j = (count - 1); j > i; j--)
                        ptr[j] = ptr[j - 1];
                    return i;
                }
            }
            return (count - 1);//返回用于存储新加入数据的数组下标
        }
    }
    /*sizeCheck function is used by add and remove functions to check and
     balance the size of the priorityQueue as per given criteria which is
     (i)the queue should double in size when number of added elements equals
     the size of the queue; (ii)the queue should be made to equal the number
     of elements in the queue if the size is more than three times the number
     of elements in the queue*/
    void sizeCheck() {//检测输入数据是否超多两个    检测数据量是否超过对列大小
        if (count == size - 1) {//？？？这里为啥是从count为4时就将队列大小翻倍
            priorityItem<type>* temp = new priorityItem<type>[size];
            for (int i = 0; i < size; i++)
                temp[i] = ptr[i];
            delete[] ptr;
            size *= 2;
            ptr = new priorityItem<type>[size];
            for (int i = 0; i < (count - 1); i++)
                ptr[i] = temp[i];
            delete[] temp;
        }
        else if (3 * (count + 1) == size && count != 0) {//判断条件根本不可能满足  不可能进入循环？？？
            priorityItem<type>* temp = new priorityItem<type>[count];
            for (int i = 0; i < (count - 1); i++)
                temp[i] = ptr[i];
            delete[] ptr;
            size = size / 3;
            ptr = new priorityItem<type>[size];
            for (int i = 0; i < size; i++)
                ptr[i] = temp[i];
            delete[] temp;
        }
    }

    //adds a new priorityItem type object to the priorityQueue based on the priority of the added object
    void add(type data, int priority) {
        count++;
        sizeCheck();//队列大小检查
        int temp = priorityCheck(priority); //加入新数据项的优先级 重新排列整个数组中优先级的顺序
        ptr[temp].setData(data); //设置ptr[temp]数据项
        ptr[temp].setPriority(priority);
        std::cout << "\t\tadded " << ptr[temp].getData() << " at " << temp << std::endl;
    }
    //removes the first element from the queue as it is a FIFO(first in first out) data structure
    void remove() {
        if (count > 0) {
            priorityItem<type> temp = ptr[0]; //临时存储数组中第一个元素
            for (int i = 0; i < (count - 1); i++)
                ptr[i] = ptr[i + 1]; //将数组中所有元素向前移动
            count--;//存储数据计数减一
            sizeCheck();//检测数据个数
            std::cout << "\t\tremoved " << temp.getData() << std::endl;//对移除数据进行输出
        }
        else
            std::cout << "\t\tno more elements" << std::endl;
    }
    //print the elements of the queue grouped into their respective priorities
    void print() {
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                if(i == 0)
                    std::cout << "\t\tPriority " << ptr[0].getPriority() << ":" << std::endl;
                std::cout << "\t\t" << ptr[i].getData() << std::endl;
                if (ptr[i].getPriority() < ptr[i + 1].getPriority() && (count - 1) != i)//这样的判定条件进行输出的好处？？
                    std::cout << "\t\tPriority " << ptr[i + 1].getPriority() << ":" << std::endl;
            }
        }
        else
            std::cout << "\t\tno data to print" << std::endl;
    }
    //class destructor
    ~priorityQueue() {
        delete[] ptr;
    }
};
