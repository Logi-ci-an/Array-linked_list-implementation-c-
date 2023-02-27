#include<iostream>
#include<string>
#include"ArrayBag.h"
#include"List.h"
using namespace std;

int main() {
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	List<int>lista;

	lista.Add(9);
	lista.Add(8);
	lista.Add(4);
	lista.Add(1);
	lista.Add(-3);

	vector<int>V1 = lista.ToVector();
	int size = lista.GetCurrentSize();
	for (int i = 0; i < size; i++) {
			cout << V1[i] << " ";
	}
	cout << endl;


	/*lista.swap(1, 3);
	V1 = lista.ToVector();
	size = lista.GetCurrentSize();
	for (int i = 0; i < size; i++) {
			cout << V1[i] << " ";
	}
	cout << endl;*/

	List<int>lista2;

	lista2.Add(5);
	lista2.Add(4);
	lista2.Add(3);
	lista2.Add(2);
	lista2.Add(1);

	lista.Merge(lista2);
	V1 = lista.ToVector();
	size = V1.size();
	for (int i = 0; i < size; i++) {
		cout << V1[i] << " ";
	}
}