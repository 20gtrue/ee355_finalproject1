#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
// TODO: You may need to add other libraries here!
using namespace std;

class Date {
    // TODO: private or protected? Look at your children!	
	//protected string type; // Private bc children need to access type
private:
    string date_nums;
public:
	//virtual void print() = 0;
    //virtual string get_contact(string style="full") = 0;
	//virtual void set_contact() = 0;
    Date(string date_nums);
    void print_date(string idk);
};

#endif

