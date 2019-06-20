#ifndef WEATHER_H
#define WEATHER_H

#include <string>
#include <vector>
#include "date.h"


class Date;




const int HIGH=3;
const int MED=2;
const int LOW=1;





class Image {
 public:
    Image(int w, int h, std::string flnm);
    Image(const Image& img2);
    ~Image();
	
	
    Image& operator=(const Image& img2);
    int image_sz();
    int get_height() { return height; }
    int get_width() { return width; }
	virtual std::string display() const;
 private:
    int width;
    int height;
    std::string filename;
    char* image_buf;
    void copy_fields(const Image& img2);
};


class Jpeg : public Image{
	public:
	Jpeg(int w, int h, std::string flnm, int q=HIGH):Image(w,h,flnm),quality(q){}
	std::string display() const;
	private:
	int quality;
};

class Png : public Image{
	public:
	Png(int w, int h, std::string flnm, int q=HIGH):Image(w,h,flnm),quality(q){}
	std::string display() const;
	private:
	int quality;
};

class Gif : public Image{
	public:
	Gif(int w, int h, std::string flnm, int q=HIGH):Image(w,h,flnm),quality(q){}
	std::string display() const;
	private:
	int quality;
};









struct GPS {
    double latitude;
    double longitude;
    GPS(double la, double lo) : latitude(la),
        longitude(lo) {}
};

std::ostream& operator<<(std::ostream& os, const GPS& gps);


// class Date {
    // friend std::ostream& operator<<(std::ostream& os, const Date& date);
 // public:
    // Date(int d, int m, int y);
 // private:
     // int day;
     // int month;
     // int year;
// };


class WReading {
    friend std::ostream& operator<<(std::ostream& os, const WReading& wr);
 public:

    WReading(Date dt, double temp, double hum, double ws, Image* imag_coll);
	double get_tempF() const;
	void call_image() const;

/*
	double get_tempF() const;
	double get_tempC(double raw=temp) const;
	double get_heat_index(double raw) const;
	double get_wind_chill(int fahrenheit_flag) const;
	double get_wind_chill() const;
	
	*/

 private:
    Date date;
    double temperature;  // stored temp in C
    double humidity;
    double windspeed;
	Image* imag_coll;
};


const int UNRATED = -1;
const int BAD = 0;
const int OK = 1;
const int GOOD = 2;

class Weather {
    // << should output name, rating, and use the GPS << to output my_loc
    friend std::ostream& operator<<(std::ostream& os, const Weather& w);
 public:
    Weather(std::string nm, GPS loc);
    std::string get_name() const;
    int get_rating() const;
    void set_rating(int new_rating);
    void add_reading(WReading wr);
	void display_images() const;
 private:
    std::vector<WReading> wreadings;
    std::string station_nm;
    GPS my_loc;
    int rating = UNRATED;
};


#endif