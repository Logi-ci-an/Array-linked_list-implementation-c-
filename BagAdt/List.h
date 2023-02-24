#pragma once
#include "BagInterface.h"
#include"Node.h"
template<class T>
class List :public BagInterface<T>
{
private:
	Node<T>* HEAD;
	Node<T>* GetPointer(const T& Item) const{
		Node<T>* header=HEAD;
		while (header->GetNext() != nullptr) {
			if (header->GetNext()->GetData() == Item)
				return header;
			header = header->GetNext();
		}
		return nullptr;
	}
public:
	List() {
		this->CurrentCount = 0;
		HEAD = nullptr;
	}

	List(const List<T>& Copy) {
			this->HEAD = nullptr;
			this->CurrentCount = 0;
			Node < T >  *NEW_Node = Copy.HEAD;
			while (NEW_Node != nullptr) {
				this->Add(NEW_Node->GetData());
				NEW_Node = NEW_Node->GetNext();
			}
		
	}

	virtual bool Add(const T item) {
		Node<T>* NewItem = new Node<T>;
		NewItem->SetData(item);
		NewItem->SetNext(HEAD);
		HEAD=NewItem;
		this->CurrentCount++;
		return true;
	}
	virtual bool Contains(const T& item)const {
		return (GetPointer(item )!= nullptr);
	}

	virtual int GetCurrentSize()const {
		return this->CurrentCount;
	}
	virtual bool IsEmpty()const {
		return this->CurrentCount;
	}


	virtual void Clear() {
		Node<T>* Deleter = HEAD;
		while (HEAD->GetNext() != nullptr) {
			HEAD = HEAD->GetNext();
			delete Deleter;
			Deleter = HEAD;
		}
		delete Deleter;
	
	}
	virtual bool Remove(const T item){
		Node<T>*ptr=this->GetPointer(item);
		if (ptr == nullptr)
			return false;
		Node<T>* deleted = ptr->GetNext();
		ptr->SetNext(deleted->GetNext());
		delete deleted;
		this->CurrentCount--;
		return true;
	}

	virtual int GetFrequencyOf(const T& item, int x=0)const {
		int result = 0;
		Node<T>* Fre = HEAD;
		while (Fre != nullptr) {
			if (Fre->GetData() == item)
				result++;
			Fre = Fre->GetNext();
		}
		return result;
	}
	virtual vector<T> ToVector()const {
		vector<T>result;
		Node<T>* Displayer=HEAD;
		while (Displayer != nullptr) {
			result.push_back(Displayer->GetData());
			Displayer = Displayer->GetNext();
		}
		return result;
	}


	~List() {
		Clear();
	}

};

