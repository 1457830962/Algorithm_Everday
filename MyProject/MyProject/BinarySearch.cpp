#include <iostream>
#include "BinarySearch.h"
#define SIZE 8

CBinarySearch::CBinarySearch():bSearchAgain(false)
{
}

CBinarySearch::~CBinarySearch(void)
{
}

/*****************************************************************
* method:BinarySearch
* Para: iarr 数据源
******************************************************************/
void CBinarySearch::BinarySearch(const int *iarr, int low, int high, int key)
{
	int mid, index = -1, Tier = 1, Times = 0;
	while (low <= high)
	{
		Tier++;
		Times++;
		mid = (low + high) / 2;
		if (iarr[mid] == key)
		{
			index = mid;
			break;
		}
		if (iarr[mid] < key)
			low = mid + 1;
		else
			high = mid - 1;
	}

	if (index >= 0)
	{
		printf("Array lookup location:a[%d]\n", index);
		printf("关键字比较次数Timesr:%d\n", Times);
		printf("树高Tier:%d\n", Tier);
		Link_BinarySearch();
	}
	else
	{ 
		printf("this num not found!\n");
		bSearchAgain = true;
		Link_BinarySearch();
	}
}


void CBinarySearch::Link_BinarySearch()
{
	if (bSearchAgain)
	{
		printf("please enter a search number again: ");
	}
	else
	{
		printf("please enter a search number: ");
	}

	int key = 0;
	scanf_s("%d", &key);
	int arr[SIZE] = { 4, 21, 36, 48, 50, 57, 78, 85 };
	int low = 0, high = SIZE - 1;
	BinarySearch(arr, low, high, key);
}