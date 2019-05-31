#include <iostream>
#include <string>
#include <vector>
#include "basics.h"
#include <cmath>
using namespace std;

/*
 * increment arg passed by copy
 * */
void inc_pass_copy(int j) {
	++j;
	return;
}

/*
 * increment arg passed by reference
 * */
void inc_pass_ref(int& j) {

	++j;

	return;
}

/*
 * Fill a vector with n elements from 1 to n.
 * 1st item == 1, 2nd item == 2, etc.
 * 0 filled for you.
 * Use `push_back()` to fill the vector.
 * */
void fill_vector(vector<int>& v, int n) {

	for (size_t i = 1; i < n+1; ++i)
	{
		v.push_back(i);
	}

}

/*
 * Print all elements in a vector. Use a ranged for!
 * */
void print_vector(const vector<int>& v) {

	for (int ant : v)
	{
		cout << ant << "\t";
	}
}

/*
 * Print a pair of coordinates.
 * Output should look like "x = 9, y = 2".
 * */
void print_coords(coord pos) {

	cout << "x = " << pos.x;
	cout << "y = " << pos.y;
	return;

}

/*
 * Square an integer.
 * */
int square(int n) {
	return (n*n);
}

/*
 * Square a double.
 * */
double square(double d) {
	return (d*d);
}

/*
 * Get the absolute value of a number.
 * */
int my_abs(int n) {

	//not using cmath
	//if (n < 0)
	//{
	//	return (n*-1);
	//}
	//else
	//{
	//	return n;
	//}


    return abs(n);
}

/*
 * Sum from 0 to n using a `while` loop.
 * */
int sum(int n) {
	int target = 0;
	int sum = 0;
	try {
		if (n < 0)
		{
			throw;
		}
	}
	catch (...)
	{
		cerr << "out of range";
		exit(2);
	}

	while (target != n)
	{
		sum += target;
		++target;
	}
	return sum;

}

/*
 * Sum from 0 to n using a `for` loop.
 * */
int sum2(int n) {
	int sum = 0;
	for (size_t i = 0; i < n; ++i)
	{
		sum += i;
	}
	return sum;
}

/*
 * say() is built for you!
 * */
void say(std::string s) {
    cout << s << endl;
}


/*
 * Use a ranged for to pull a string apart into its bits.
 * */
void pull_apart_string(std::string s) {

	for (char c : s)
	{
		cout << c << "\t";
	}
}

