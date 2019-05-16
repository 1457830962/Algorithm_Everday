#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int minNumberInRotateArray(vector<int> rotateArray){
		int size = rotateArray.size();
		if (size == 0)	{
			return 0;
		}//if

		int left = 0, right = size - 1;
		int mid = 0;
		//rotateArray[left] >= rotateArray[right] ȷ����ת
		while (rotateArray[left] >= rotateArray[right]){
			if (right - left == 1){
				mid = right;
				break;
			}//if
			mid = left + (right - left) / 2;
			//rotateArray[left]  rotateArray[right] rotateArray[mid] �������
			//�޷�ȷ���м�Ԫ��������ǰ�滹�Ǻ���ĵ���������
			//ֻ��˳�����
			if (rotateArray[left] == rotateArray[right] && rotateArray[left] == rotateArray[mid]){
				return MinOrder(rotateArray, left, right);
			}//if
			//�м�Ԫ��λ��ǰ��ĵ���������
			//��ʱ��С����Ԫ��λ���м�Ԫ�غ���
			if (rotateArray[mid] >= rotateArray[left]){
				left = mid;
			}//if
			//�м�Ԫ��λ�ں������������
			//��ʱ��СԪ��λ���м�Ԫ�ص�ǰ��
			else{
				right = left;
			}//else
			return rotateArray[mid];
		}//while
	}

private:
	//˳��Ѱ����Сֵ
	int MinOrder(vector<int> &num, int left, int right){
		int result = num[left];
		for (int i = left + 1; i < right; ++i){
			if (num[i] < result){
				result = num[i];
			}//if
		}//for
		return result;
	}
};

int main(){
	Solution s;
	vector<int> num = { 2, 2, -20,-2, 1, 2 };
	int result = s.minNumberInRotateArray(num);
   //���
	cout << result << endl;
	getchar();
	return 0;
}