#include <cassert>
#include <iostream>
#include "../my_code/vector.h"

using namespace std;

int copy_vector(MyVec v) {
    MyVec local_v = v;
	cout << "local \t" ;
	local_v.see_inside();
    return local_v.size();
}

int main() {
	MyVec v;
    for (size_t i = 0; i < 200; i++) {
		//cout << "Iteration \t" << i << endl;
        v.push_back(i);
		//cout << "non-local \t" ;
		//v.see_inside();
        //copy_vector(v);
    }
	
	
     assert(v[199] == 199);
    for (int i = 0; i < 200; i++) {
        v[i] *= 2;
    }
    assert(v[199] == 398);
    MyVec v3;
    for (int i = 9; i < 100; i += 9) {
        v3.push_back(i);
    }
    assert(v3[1] == 18);

    MyVec v2 = v;
    print_vector(v2);
    assert(v2 == v);

    v2 = v3;
    print_vector(v2);
    assert(v2 == v3);
	
	for (int i : v3) {
        assert((i % 9) == 0);
    }

    MyVec v4 = MyVec(10, 20);
    for (int i : v4) {
	assert(i == 20);}
	
	
	
	cout << "THIS IS THE END" << endl;
	
	
	
}