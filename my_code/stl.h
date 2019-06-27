#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>



using namespace std;

template <typename FILL>
void print_vec(string name, const vector<FILL>& vector_of_fill)
{
	cout << name << endl;
	for (const FILL& fill: vector_of_fill)
	{
		cout << fill << "\t";
	}
	cout << endl;
}

template <typename FILL>
void print_list(string name, const list<FILL>& list_of_fill)
{
	cout << name << endl;
	for (const FILL& fill: list_of_fill)
	{
		cout << fill << "\t";
	}
	cout << endl;
}


template <typename CLASS>
void print(string name, const CLASS& a_class)
{
	cout << name << endl;
	for (const auto& fill: a_class)
	{
		cout << fill << "\t";
	}
	cout<< endl;
	
	
	//this doesn't work....
	// for (const auto& iter=a_class.begin(); iter!=a_class.end();++iter)
	// {
		// cout << *iter << "\t";
	// }
	// cout << endl;
}
