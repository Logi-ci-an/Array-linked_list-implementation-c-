#include<iostream>
#include<string>
#include"ArrayBag.h"
#include"List.h"
using namespace std;

int main() {
	ArrayBag<int>A1;

	A1.Add(5);
	A1.Add(4);
	A1.Add(6);
	A1.Add(5);
	A1.Add(4);
	A1.Add(6);

	vector<int>v1=A1.ToVector();
	for (auto i : v1) {
		cout << i << " ";
	}
	cout << endl;

	A1.Remove(4);

	v1 = A1.ToVector();
	for (auto i : v1) {
		cout << i << " ";
	}
	cout << endl;
	cout << A1.GetFrequencyOf(5) << endl;
	cout << A1.GetCurrentSize() << endl;

	A1.Clear();


	cout << endl<<endl;
	v1 = A1.ToVector();
	for (auto i : v1) {
		cout << i << " ";
	}



	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	List<int>lista;

	lista.Add(5);
	lista.Add(7);
	lista.Add(8);
	lista.Add(7);
	lista.Add(3);

	cout<<lista.Contains(8)<<endl;
	cout << lista.GetFrequencyOf(7) << endl;

	cout << endl << endl;
	v1 = lista.ToVector();
	for (auto i : v1) {
		cout << i << " ";
	}
	cout << endl;

	lista.Remove(5);
	cout << endl << endl;
	v1 = lista.ToVector();
	for (auto i : v1) {
		cout << i << " ";
	}
}