// File: Time.h
// definitions for the Time class

#pragma once // include the header file only once

class Time
{
public:
    Time(); // default constructor
    Time(int h, int m, int s);  // constructor with parameters 
                                // if one of the parameters is invalid, the corresponding value is set to 0

    void setHour(int h);   // set the hour. if the value is invalid, set it to 0
    void setMinute(int m); // set the minute. if the value is invalid, set it to 0
    void setSecond(int s); // set the second. if the value is invalid, set it to 0

    int &badSetHour(int h); // public function that returns a not-const reference 
                            // to the private member hour
                            // DANGEROUS ! Breaks encapsulation !
                            // allows an access and modification of the private member hour
                            // should be avoided !
                            

    int getHour() const; // get the hour
    int getMinute() const; // get the minute
    int getSecond() const; // get the second

    void print() const; // print the time in the format hh:mm:ss

private:
    int hour;
    int minute;
    int second;
};