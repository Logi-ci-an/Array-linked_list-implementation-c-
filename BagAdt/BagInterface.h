#pragma once


#define DefaultCount 10

#include<vector>
using namespace std;
template<class T>
class BagInterface//abstract class
{
protected:
	virtual int getIndexOf(T) = 0;
	int MAxcount;
	int CurrentCount;
public:
	BagInterface() {
		MAxcount = DefaultCount;
		CurrentCount = 0;
	}
	virtual int GetCurrentSize() = 0;
	virtual bool IsEmpty() = 0;
	virtual	bool Add(T) = 0;
	virtual bool Remove(T) = 0;
	virtual void Clear() = 0;
	virtual int GetFrequencyOf(T) = 0;
	virtual bool Contains(T) = 0;
//	virtual vector ToVector()final = 0;
};

