#include <iostream>
#include <string>
#include "weather.h"
#include "date.h"


using namespace std;


Image::Image(int w, int h, std::string flnm)
    : width(w), height(h)
{
    filename = flnm;
    image_buf = new char[image_sz()];
}


void Image::copy_fields(const Image& img2) {
	width=img2.width;
	height=img2.height;
	filename=img2.filename;
	
	image_buf= new char( width*height  );
	
	for (int i=0;i <(width*height);++i)
	{
		image_buf[i]=img2.image_buf[i];
	}
}


Image::~Image() {
	if (image_buf)
	{
	delete[] image_buf;
	}
}
Image::Image(const Image& img2) {

	this->copy_fields(img2);
	
	
}

 Image& Image::operator=(const Image& img2) {
	 
	 if (&img2!=this)
	 {
		delete []image_buf;
		this->copy_fields(img2);

		return *this;		
	 }
	 else
	 {
		return *this;
	 }
}

int Image::image_sz() {
    return width * height;
}



string Image::display(std::string s) {
    return "Displaying image " + s;
}













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
	os << wr.date << "Temperature: " << wr.temperature << " Humidity: " << wr.humidity << " Windspeed: " << wr.windspeed << " ";
	return os;
}


//Constructors
Weather::Weather(std::string nm, GPS loc): station_nm(nm), my_loc(loc){}
// Date::Date(int d, int m, int y): day(d), month(m),year(y){}
WReading::WReading(Date dt, double temp, double hum, double ws) :
	date(dt), temperature(temp), humidity(hum), windspeed(ws){}

double WReading::get_tempF() const
{
	return temperature;
}


/*
	double WReading::get_tempF() const
	{
		return temp;
	}
	double WReading::get_tempC(double raw=temp) const
	{
		return (raw-32)*(5/9)
	}
	double WReading::get_heat_index(double raw=temp) const
	{
		double c_1 = -42.379;
		double c_2 = 2.04901523*raw;
		double c_3 = 10.14333127*humidity;
		double c_4 = -0.22475541*raw*humidity;
		double c_5 = -6.83783*(10^-3)*(raw^2);
		double c_6 = -5.481717*(10^-2)*(humidity^2);
		double c_7 = 1.22874*(10^-3)*(raw*2)*(humidity);
		double c_8 = 8.5282*(10^-4)*raw*(humidity^2);
		double c_9 = -1.99*(10^-6)*(humidity^2)(raw^2);
		
		return c_1+c_2+c_3+c_4+c_5+c_6+c_7+c_8+c_9;
		
		
		
		
	}
	double WReading::get_wind_chill(int fahrenheit_flag) const;
	double WReading::get_wind_chill() const;
*/


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

