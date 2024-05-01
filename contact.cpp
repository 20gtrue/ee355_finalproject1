#include <iostream>
#include <string>
#include "contact.h"

using namespace std; 

// Email Constructor
Email::Email(string type, string email_addr){
    this -> type = type; 
    this -> email_addr = email_addr; 
}

// Email Deconstructor
Email::~Email() {
    // Destructor is empty since there are no resources to clean up
}

// set an email
void Email::set_contact(){
    // TODO: Do not change the prompts!
    cout << "Enter the type of email address: ";
    cin >> this -> type;
    cout << "Enter email address: ";
    cin >> this -> email_addr;
}

// get an email
string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + ") " + email_addr;
    else 
        return email_addr;
}

// print an email
void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

// phone constructor
Phone::Phone(string type, string num){
    	this -> type = type; 
    
    // Get rid of any non-numbers in num 
   	string no_dash_num = "";
    	for (int i=0; i<num.length(); i++){
	    if (isdigit(num[i]) == true){
		no_dash_num = no_dash_num + num[i]; 
	    }
  	}
	cout << "num"<< endl;
  	cout << num;
  	this -> phone_num = no_dash_num; 
  	if(no_dash_num.length() != 10) {
  		cout << "Invalid Phone Number." <<endl; 
  	}
}

// phone deconstructor
Phone::~Phone() {
     // Destructor is empty since there are no resources to clean up
}

// set a phone number
void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
	cin >> (this -> type); 
	bool num_not_valid = true; 
	string num; 
	
	while(num_not_valid) {
		cout << "Enter the phone number: ";
		cin >> num; 
	
		// Get rid of any non-numbers in num 
	   	string no_dash_num = "";
	    	for (int i=0; i<num.length(); i++){
		    if (isdigit(num[i]) == true){
			no_dash_num = no_dash_num + num[i]; 
		    }
	  	}
	  	
	  	this -> phone_num = no_dash_num; 
	  	if(no_dash_num.length() != 10) {
	  		cout << "Invalid Phone Number." <<endl; 
	  	}
	  	else {
	  		num_not_valid = false; 
	  		this -> phone_num = no_dash_num; 
	  	}
	}
}

// get phone number
string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + ") " + phone_num.substr(0,3) + "-" + phone_num.substr(3,3) + "-" + phone_num.substr(6,4);
    else 
        return phone_num;
}

// print phone number
void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}



