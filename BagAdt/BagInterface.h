#pragma once


#define DefaultCount 10

#include<vector>
using namespace std;
template<class T>
class BagInterface//abstract class
{
protected:
	int CurrentCount;
public:
	BagInterface() {
		CurrentCount = 0;
	}
	virtual int GetCurrentSize()const = 0;
	virtual bool IsEmpty()const = 0;
	virtual	bool Add(const T) = 0;
	virtual bool Remove(const T) = 0;
	virtual void Clear() = 0;
	virtual int GetFrequencyOf(const T&,int)const = 0;
	virtual bool Contains(const T&)const = 0;
	virtual vector<T> ToVector()const = 0;
};

