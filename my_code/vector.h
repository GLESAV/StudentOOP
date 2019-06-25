#include <iostream>

const int DEF_CAPACITY = 10;
const int CAPACITTY_MULT = 2;


class MyVec {

    public:
	
	        class Iterator {
        /*
         * This class supports ranged for loops.
         * It includes:
         * Iterator(int*)
         * operator++
         * operator*
         * operator!=
         * */
            friend bool operator!=(Iterator& rhs, Iterator& lhs);

        public:
		Iterator (int* ip): iptr(ip) {
			std::cout << "Iterator construted" << std::endl;
		};

            Iterator& operator++()
			{
				iptr++;
				return *this;
			}

            int operator*();

        private:
            int* iptr;
    };
	
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
		
		//Iterators
		MyVec(int sz, int val=0);
		
		Iterator begin() const;
		Iterator end() const;
		
		
    private:
        int* data;
        int sz;
        int capacity;
};


void print_vector(const MyVec& v);

bool operator==(MyVec& v1, MyVec& v2);