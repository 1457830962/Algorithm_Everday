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
        size = 5;   //��ʼ�����д�С
        count = 0;   //������Ӽ���
        ptr = new priorityItem<type>[size];   //new��size����С��������
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
        else if (priority < ptr[0].getPriority()) {//�����ж����׸�Ԫ�ص����ȼ�
            for (int i = (count - 1); i > 0; i--) //����ÿ�����ݵ����ȼ�λ��
                ptr[i] = ptr[i - 1];
            return 0;
        }
        else {
            for (int i = 0; i < (count - 1); i++) {//���ȼ���С���׸�Ԫ������£� �����ж�������Ԫ�����ȼ�
                if (priority < ptr[i].getPriority()) {
                    for (int j = (count - 1); j > i; j--)
                        ptr[j] = ptr[j - 1];
                    return i;
                }
            }
            return (count - 1);//�������ڴ洢�¼������ݵ������±�
        }
    }
    /*sizeCheck function is used by add and remove functions to check and
     balance the size of the priorityQueue as per given criteria which is
     (i)the queue should double in size when number of added elements equals
     the size of the queue; (ii)the queue should be made to equal the number
     of elements in the queue if the size is more than three times the number
     of elements in the queue*/
    void sizeCheck() {//������������Ƿ񳬶�����    ����������Ƿ񳬹����д�С
        if (count == size - 1) {//����������Ϊɶ�Ǵ�countΪ4ʱ�ͽ����д�С����
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
        else if (3 * (count + 1) == size && count != 0) {//�ж�������������������  �����ܽ���ѭ��������
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
        sizeCheck();//���д�С���
        int temp = priorityCheck(priority); //����������������ȼ� ���������������������ȼ���˳��
        ptr[temp].setData(data); //����ptr[temp]������
        ptr[temp].setPriority(priority);
        std::cout << "\t\tadded " << ptr[temp].getData() << " at " << temp << std::endl;
    }
    //removes the first element from the queue as it is a FIFO(first in first out) data structure
    void remove() {
        if (count > 0) {
            priorityItem<type> temp = ptr[0]; //��ʱ�洢�����е�һ��Ԫ��
            for (int i = 0; i < (count - 1); i++)
                ptr[i] = ptr[i + 1]; //������������Ԫ����ǰ�ƶ�
            count--;//�洢���ݼ�����һ
            sizeCheck();//������ݸ���
            std::cout << "\t\tremoved " << temp.getData() << std::endl;//���Ƴ����ݽ������
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
                if (ptr[i].getPriority() < ptr[i + 1].getPriority() && (count - 1) != i)//�������ж�������������ĺô�����
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
