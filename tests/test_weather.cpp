#include <cassert>
#include <iostream>
#include <fstream>
#include "../my_code/weather.h"
#include "../my_code/date.h"

using namespace std;


void get_wreadings(string& filenm, Weather& w) 
{
    ifstream rfile(filenm);
    while (!rfile) 
	{
        cout << "Could not read input file " << filenm <<" \n Try a new name (0 to exit): " << endl;
		
		cin >> filenm;
		
		if (filenm=="0")
		{exit(2);}
		rfile.open(filenm);
		

		
    }
	
	int m, d, y;
	double temp, hum, ws;
	while (rfile >> m >> d >> y >> temp >> hum >> ws) 
	{
		WReading wr = WReading(Date(d, m, y), temp, hum, ws);
		w.add_reading(wr);
	}
	
	rfile.close();
	
}

int main() {
    Weather irkutsk = Weather("Irkutsk", GPS(46.3, 67.2));

    string filenm;
    cout << "Input the name of the new readings file:\n";
	cin >> filenm;
	
	get_wreadings(filenm, irkutsk);

    cout << irkutsk << endl;
}