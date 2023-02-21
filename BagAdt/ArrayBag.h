#pragma once
#include "BagInterface.h"
#include<iostream>
using namespace std;
template<class T>
class ArrayBag :public BagInterface<T>
{
private:
	T items[DefaultCount];
	int MAxcount;
	virtual int getIndexOf(const T &item,int SearchIndex =0)const {
		/*int result = -1;
		if (SearchIndex < this->CurrentCount) {
			if (item == this->items[SearchIndex])
				return SearchIndex;
			else
				return getIndexOf(item, SearchIndex + 1);
		}
		return result;*/
		if (SearchIndex >= this->CurrentCount)
			return -1;
		else if (this->items[SearchIndex] == item)
			return SearchIndex;
		return getIndexOf(item, SearchIndex + 1);
	}


public:
	ArrayBag() {
		MAxcount = DefaultCount;
	}
	ArrayBag(const ArrayBag& A) {
		for (int i = 0; i < A.CurrentCount; i++) {
			this->Add(A[i]);
		}
		MAxcount = DefaultCount;
	}
	virtual int GetCurrentSize()const {
		return this->CurrentCount;
	}
	virtual bool IsEmpty()const {
		return this->CurrentCount;
	}
	virtual	bool Add(const T item) {
		if (this->CurrentCount == this->MAxcount)
			return false;
		items[this->CurrentCount++] = item;
		return true;
	}
	virtual bool Remove(const T item) {
		if (!this->Contains(item))
			return false;
		int index = getIndexOf(item);
		for (index; index < this->CurrentCount; index++) {
			items[index] = items[index + 1];
		}
		this->CurrentCount--;
		return true;
	}
	virtual void Clear() {
		this->CurrentCount = 0;
	}
	virtual int GetFrequencyOf(const T &item,int Start=0)const {
		if (Start == this->CurrentCount)
			return 0;
		if (item == this->items[Start])
			return 1 + GetFrequencyOf(item, Start + 1);
		return GetFrequencyOf(item, Start + 1);
	}
	virtual bool Contains(const T &item)const {
		if (getIndexOf(item) >= 0)
			return true;
		return false;
	}
	virtual vector<T> ToVector()const {
		vector<T>result;
		for (int i = 0; i < this->CurrentCount; i++) {
			result.push_back(this->items[i]);
		}
		return result;
	}
};
