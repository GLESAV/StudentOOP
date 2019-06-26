#ifndef TVECTOR
#define TVECTOR

#include <iostream>
using namespace std;


template <typename FILL>
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
            friend bool operator!=(Iterator& rhs, Iterator& lhs){
	
                return (rhs.iptr!=lhs.iptr);
            }
			

        public:
		Iterator (FILL* ip): iptr(ip) {
			std::cout << "Iterator construted" << std::endl;
		};

            Iterator& operator++()
			{
				iptr++;
				return *this;
			}

            FILL operator*()
			{
				return *iptr;
			}

        private:
            FILL* iptr;
    };
		//template<typename FILL>
		// friend ostream& std::operator<< (ostream&, const MyVec);
		
		
      // template <typename FILL>
		MyVec():data(new FILL[10]),sz(0),capacity(10) 
		{
cout << "Default Constructor Called"<< endl;
}
		
		void see_inside() const{
	cout << "\nSIZE CAP DATA\t" << sz << "\t" << capacity << endl;
		for (size_t i=0;i<sz;++i)
		{
			cout << data[i] << "\t";
		}
		
		}
        
		
		// copy control:
        // template <typename FILL>
		MyVec(const MyVec& v2)
		{			
			data = new FILL[v2.capacity];
			
	
			sz = v2.sz;
			capacity=v2.capacity;
			
			for (size_t i=0;i<v2.sz;i++)
				{
					data[i]=v2.data[i];
				}
			cout << "Copy called/fin" << endl;
		}
		
		
		// template <typename FILL>
        ~MyVec(){
	delete [] data;
}


		// template <typename FILL>
        MyVec<FILL>& operator=(const MyVec<FILL>& v2) {
			if (&v2!=this)
				
			{
				sz=v2.size();
				capacity=v2.size()*2;
				delete [] data;
				data = new FILL[sz];
				for (size_t i=0;i<sz;++i)
					{
							data[i] =v2.data[i];
					}
				return *this;
			}
			else	{return *this;}
}

		// template <typename FILL>
        void push_back(FILL val)
		{
			if(sz==capacity) //NO space,copy old values
			{
				cout << "Make bigger" << endl;
				FILL* data_hold=new FILL[capacity*2];
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
		
        int size() const { 
		//std::cout << "call to size" << std::endl;
		return sz; }
		
		// template <typename FILL>
        FILL operator[](int i) const{
    return data[i];
}
		// template <typename FILL>
        FILL& operator[](int i){
    
    return data[i];
}
		
		//Iterators
		// template <typename FILL>
		MyVec(int sz, FILL val=0):data(new FILL[sz]),sz(sz),capacity(sz*2) {
	for (int i=0;i<sz;i++)
	{
		data[i]=val;
	}
	cout << "Constructor w sz of vals para Called"<< endl;
	}
		
		 Iterator begin() const
		 {
			cout << "Iterator begin called" << endl;
			MyVec::Iterator begin_it = (data);
			return begin_it;
		}
		 Iterator end() const
		 {
			cout << "Iterator end called" << endl;
			return MyVec::Iterator(data+sz);
		 }

		
		
    private:
        FILL* data;
        int sz;
        int capacity;
};

template <typename FILL>
void print_vector(const MyVec<FILL>& v){
	cout << "SIZE CAP DATA" << endl;
	cout << v.size() << "\t" <<endl;
			for (size_t i=0;i<v.size();++i)
				{
					cout << v[i] << "\t";
				}
	

}


 template <typename FILL>
bool operator==(MyVec<FILL>& v1, MyVec<FILL>& v2)
{
	if (v1.size()!=v2.size())
	{
		return false;
	}
	else
	{
		for (size_t i=0; i< v1.size();++i)
		{
			if (v1[i]!=v2[i])
			{
				return false;
			}
		}
	}
	return true;
}

#endif