#include <iostream>
#include <string>
#include <map>
#include "date.h" 

//constructor takes in date in X/X/XXXX or XX/X/XXXX or XX/XX/XXXX format and converts it to XX/XX/XXXX format
//this assumes that it's given in month/day/year format, which is the date_nums string input
Date::Date(string date_nums) {
	//checks where the '/' characters are and uses that to determine if the month and day are single digit or double digit.
	//if they are single digit, it adds a leading zero to the string (so 4 becomes 04 ex.)
	if(date_nums[1] == '/') {
		date_nums.insert(0, "0"); //put zero before date if only one digit
	}
	// now assume XX/?X/XXXX
	if(date_nums[4] == '/') {
		date_nums.insert(3, "0"); //put zero for month first digit
	}

	this -> date_nums = date_nums;
}

//prints the date in a pretty format
//this function takes in a string based on the starter code we were given, but we do not use that string in the function.
void Date::print_date(string idk) {

	//Using a map to create a glossary with each month number as the key, that corresponds to the written-out month
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

	//the following converts the raw string date_nums to each individual part
	string day = date_nums.substr(3,2);
	string year = date_nums.substr(6,4);
	string month = date_nums.substr(0,2);
	month = month_glossary[month];
	
	cout << month << " " << day << ", " << year << endl;

}

string Date::get_date(){
    return date_nums; 
} 

