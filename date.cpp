#include <iostream>
#include <string>
#include <map>
#include "date.h"
// TODO: Add needed libraries! 


Date::Date(string date_nums) {

	if(date_nums[1] == '/') {
		date_nums.insert(0, "0"); //put zero before date if only one digit
	}
	// now assume XX/?X/XXXX
	if(date_nums[4] == '/') {
		date_nums.insert(3, "0"); //put zero for month first digit
	}

	this -> date_nums = date_nums;
}

//TODO: figure out what the string input is supposed to mean?
void Date::print_date(string idk) {

	//convoluated way of avoiding using C++11, using maps instead
	map<string, string> month_glossary;
	month_glossary["01"] = "January";
	month_glossary["02"] = "February";
	month_glossary["03"] = "March";
	month_glossary["04"] = "April";
	month_glossary["05"] = "May";
	month_glossary["06"] = "June";
	month_glossary["07"] = "July";
	month_glossary["08"] = "August";
	month_glossary["09"] = "September";
	month_glossary["10"] = "October";
	month_glossary["11"] = "November";
	month_glossary["12"] = "December";
	
	string day = date_nums.substr(3,2);
	string year = date_nums.substr(6,4);
	string month = date_nums.substr(0,2);
	month = month_glossary[month];
	
	cout << month << " " << day << ", " << year << endl;

}

string Date::get_date(){
    return date_nums; 
} 

