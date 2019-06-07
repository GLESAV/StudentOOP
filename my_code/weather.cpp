#include <iostream>
#include <string>
#include "weather.h"
#include "date.h"


using namespace std;

//Output operators
std::ostream& operator<<(std::ostream& os, const GPS& gps){
	os << "Lat:  " << gps.latitude 
	<< " Long:   " << gps.longitude;
	
	return os;
}
std::ostream& operator<<(std::ostream& os, const Weather& w){
	os << "Station Name: " << w.station_nm << " Rating: "<< w.rating << " " << w.my_loc;
	cout << endl;
	for (WReading inst: w.wreadings)
	{
		cout << inst << "\n";
	}
	cout << endl;
	
	return os;
}
// std::ostream& operator<<(std::ostream& os, const Date& date){
	// os <<date.month << "/" << date.day <<"/" << date.year << " ";
	// return os;
// }
std::ostream& operator<<(std::ostream& os, const WReading& wr)
{
	os << wr.date << "Temperature: " << wr.temperature << " Humidity " << wr.humidity << " Windspeed: " << wr.windspeed << " ";
	return os;
}


//Constructors
Weather::Weather(std::string nm, GPS loc): station_nm(nm), my_loc(loc){}
// Date::Date(int d, int m, int y): day(d), month(m),year(y){}
WReading::WReading(Date dt, double temp, double hum, double ws) :
	date(dt), temperature(temp), humidity(hum), windspeed(ws){}




//Weather methods
int Weather::get_rating() const{
	return rating;
}    
void Weather::set_rating(int new_rating){
	rating= new_rating;
	return;
}
std::string Weather::get_name() const{
	return station_nm;
}
void Weather::add_reading(WReading wr)
{
	wreadings.push_back(wr);
}

