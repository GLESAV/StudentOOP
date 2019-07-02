
#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

class Sin {
    public:
        double operator()(double r) {
            return sin(r);
        }
};

class Fib {
    public:
        Fib() {}

        long long int operator()(long long int n) {
            if (n==0)
			{return 0;}
		else if (n==1)
			{return 1;}
		else if (n>1)
		{
			for (size_t i=0; i<n-1;++i)
			{
				previous=previous_2;
				previous_2=current;
				current=previous+previous_2;
			}
			return current;
		}
	
			
			
			// if (n <= 1) return 1;
            // else return operator()(n - 1) + operator()(n - 2);
        }

        const int MAX_FIB = 100;
        const int NOT_CALCED = -1;
    private:
	long long int previous=0;
	long long int previous_2=1;
	long long int current=1;
};


double square_func(double d, function<double(double)> f)
 {
    return f(d) * f(d);
}



double cubed_func(double d, function<double(double)> f) {
    return f(d)*f(d)*f(d); 
}


double tan_sq_plusy
(double x, double y, function<double(double)> f)
{
	double hold= f(x);
	return hold+y;
}

void times_string(string x,double times, function<string(string)> f)
{
	//used floor in this function;
	for (size_t i=0; i < floor(times); ++i)
	{
		cout << f(x) << endl;
	}
	
	
}



int main() {
	double x;
	double xsq_plus_y;
	const int TEST_INT=2;
	
	//assignment : memo-ize the fib functor so it can run acceptably fast 60 or 80 as inputs
	
	//about half a dozen practice lambdas
	// three with square and three with whatever
	cout << "\n\n\n\n\n";
    const long long int FIB_NUM = 80;

    // first functors:
    Sin sine = Sin();
    double d = sine(PI / 2);
    cout << "sin pi / 2 == " << d << endl;
    d = sine(0);
    cout << "sin 0 == " << d << endl;
    Fib fib = Fib();
    long long int f = fib(FIB_NUM);
    cout << "fib(" << FIB_NUM << ") == " << f << endl;

    // then lambdas -- use several functions from cmath here:
    d = square_func(0, [](double arg) { return sin(arg); });
    cout << "Square of sin 0 = " << d << endl;
    d = square_func(1, [](double arg) { return sin(arg); });
	
	d = square_func(1, [](double arg) { return cos(arg); });
	cout << "Square of cos 1 = " << d << endl;
    // your call here!

	d = square_func(0, [](double arg) { return tan(arg); });
    cout << "Square of tan 0 = " << d << endl;
    // your call here!
	d = square_func(1, [](double arg) { return tan(arg); });
    cout << "Square of tan 1 = " << d << endl;
    // your call here!
    
	
	
    cout << "Square of sin 1 = " << d << endl;
    	
	x = cubed_func(TEST_INT, [](double para){return log(para);});
	cout << "log" << TEST_INT << " cubed = " << x << endl;
	
	
	xsq_plus_y= tan_sq_plusy(x,TEST_INT,[](double in_value){return tan(in_value);}); 
	
	times_string("hello world" ,32,[](string str){return str;});
	

	cout << "This is the end of test functors" << endl;
}