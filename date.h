#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;

//defines class date and all its functions
class Date {
private:
    string date_nums;
public:
    Date(string date_nums);
    virtual ~Date();
    string get_date(); // Implementing this function so we can access date_nums in person to compare two people 
    void print_date(string idk);
};

#endif

