#include <iostream>

const int DEF_CAPACITY = 10;

class MyVec {

    public:
		// friend ostream& std::operator<< (ostream&, const MyVec);
       
		MyVec();
		void see_inside() const;
        // copy control:
        MyVec(const MyVec& v2);
        ~MyVec();
        MyVec& operator=(const MyVec& v2);

        void push_back(int val);
        int size() const { 
		//std::cout << "call to size" << std::endl;
		return sz; }
        int operator[](int i) const;
        int& operator[](int i);
    private:
        int* data;
        int sz;
        int capacity;
};


void print_vector(const MyVec& v);

bool operator==(MyVec& v1, MyVec& v2);