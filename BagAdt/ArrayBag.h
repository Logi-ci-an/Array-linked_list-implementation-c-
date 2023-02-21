#pragma once
#include "BagInterface.h"
template<class T>
class ArrayBag :public BagInterface<T>
{
private:
	T items[DefaultCount];
	virtual int getIndexOf(T item) {
		for (int i = 0; i < this->CurrentCount; i++) {
			if (item == items[i])
				return i;
		}
		return -1;
	}


public:
	virtual int GetCurrentSize() {
		return this->CurrentCount;
	}
	virtual bool IsEmpty() {
		return this->CurrentCount;
	}
	virtual	bool Add(T item) {
		if (this->CurrentCount == this->MAxcount)
			return false;
		items[this->CurrentCount++] == item;
		return true;
	}
	virtual bool Remove(T item) {
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
	virtual int GetFrequencyOf(T item) {
		int result=0;

		for (int i = 0; i < this->CurrentCount; i++) {
			if (item == items[i])
				result++;
		}
		return result;
	}
	virtual bool Contains(T item) {
		if (getIndexOf(item) >= 0)
			return true;
		return false;
	}
	//virtual vector ToVector() {
		
//	}
};

