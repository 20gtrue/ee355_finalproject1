#include <iostream>
#include <string>
#include "contact.h"
// TODO: Add needed libraries! 

using namespace std; 

Email::Email(string type, string email_addr){
    // TODO: Complete constructor
    this -> type = type; 
    this -> email_addr = email_addr; 
}

Email::~Email() {
    // Destructor is empty since there are no resources to clean up
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
    cout << "Enter the type of email address: ";
    cin >> this -> type;
    cout << "Enter email address: ";
    cin >> this -> email_addr;
}


string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + ") " + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    
    	this -> type = type; 
    
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
}

Phone::~Phone() {
     // Destructor is empty since there are no resources to clean up
}

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


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + ") " + phone_num.substr(0,3) + "-" + phone_num.substr(3,3) + "-" + phone_num.substr(6,4);
    else 
        return phone_num;
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}



