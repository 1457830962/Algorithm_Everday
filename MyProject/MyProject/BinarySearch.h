#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

class CBinarySearch
{
public:
	CBinarySearch();
	virtual ~CBinarySearch(void);
public:
	void BinarySearch(const int *iarr, int low, int high, int key);
	void Link_BinarySearch();
private:
	bool bSearchAgain;

};
#endif