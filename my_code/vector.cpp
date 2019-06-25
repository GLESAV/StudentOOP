#include <iostream>
#include "vector.h"

using namespace std;

void print_vector(const MyVec& v) {
	cout << "SIZE CAP DATA" << endl;
	cout << v.size()<< "\t"<< endl;
			for (size_t i=0;i<v.size();++i)
				{
					cout << v[i] << "\t";
				}
	

}


// ostream& std::operator<< (ostream& os,const MyVec obj)
// {
	// for (size_t i=0;i<obj.sz;++i)
	// {
		// os << obj.data[i] << "\t";
	// }
	// return os;
// }
void MyVec::see_inside()const {
	cout << "\nSIZE CAP DATA\t" << sz << "\t" << capacity << endl;
		for (size_t i=0;i<sz;++i)
	{
		cout << data[i] << "\t";
	}
	
}
MyVec::MyVec():data(new int[10]),sz(0),capacity(10) {

cout << "Default Constructor Called"<< endl;
}

MyVec::MyVec(int sz, int val):data(new int[sz]),sz(sz),capacity(sz*2) {
	
	
	for (int i=0;i<sz;i++)
	{
		data[i]=val;
	}
	
	
cout << "Constructor w sz of vals para Called"<< endl;
}





MyVec::MyVec(const MyVec& v2) {
	data = new int[v2.capacity];
	sz = v2.sz;
	capacity=v2.capacity;
	
	for (int i=0;i<sz;i++)
	{
		data[i]=v2.data[i];
	}
	cout << "Copy called/fin" << endl;
}

MyVec::~MyVec() {
	delete [] data;
}

MyVec& MyVec::operator=(const MyVec& v2) {
	return *this;
}



bool operator==(MyVec& v1, MyVec& v2) {
    return true;
}

void MyVec::push_back(int val) {
	if(sz==capacity) //NO space,copy old values
	{
		cout << "Make bigger" << endl;
		int* data_hold=new int[capacity*2];
		cout << "LAST \t" ;
		for (int i=0;i<sz;++i)
		{
			data_hold[i]=data[i];
		}
		delete [] data;
		data=data_hold;
		capacity=capacity*2;
	}
	
	data[sz]=val;
	++sz;
}
int MyVec::operator[](int i) const {
    return data[i];
}

int& MyVec::operator[](int i) {
    
    return data[i];
}




MyVec::Iterator MyVec::begin() const {
	cout << "Iterator begin called" << endl;
	MyVec::Iterator begin_it = (data);
    return begin_it;
}

MyVec::Iterator MyVec::end() const {
	cout << "Iterator end called" << endl;
    return MyVec::Iterator(data+sz);
}


bool operator!=(MyVec::Iterator& rhs, MyVec::Iterator& lhs) {
	
                return (rhs.iptr!=lhs.iptr);
            }
			
			

int MyVec::Iterator::operator*() { return *iptr; }


MyVec::Iterator::Iterator(int* ip): iptr(ip) {
			std::cout << "Iterator construted" << std::endl;
		};
MyVec::Iterator& MyVec::Iterator::operator++()
			{
				iptr++;
				return *this;
			}

