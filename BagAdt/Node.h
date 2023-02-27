#pragma once
template<class T>
class Node
{
private:
	T Data;
	Node<T>* Next;
public:
	Node() {
		Next = nullptr;
	}
	void SetData(T D) {
		Data = D;
	}
	void SetNext(Node<T>*N) {
		Next = N;
	}
	T GetData() {
		return this->Data;
	}
	Node<T>* GetNext() {
		return this->Next;
	}

};

