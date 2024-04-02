
#include "contact.h"
// TODO: Add needed libraries! 

Email::Email(string type, string email_addr){
    // TODO: Complete constructor
    this.type = type; 
    this.email_addr = email_addr; 
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
    cout << "Enter the type of email address: ";
    cin >> this.type;
    cout << "Enter email address: ";
    cin >> this.email_addr;
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
    
    	this.type = type; 
    
    // Get rid of any non-numbers in num 
   	string no_dash_num = "";
    	for (int i=0; i<num.length(); i++){
	    if (isdigit(num[i]) == true){
		no_dash_num = no_dash_num + num[i]; 
	    }
  	}
  	
  	this.num = no_dash_num; 
  	if(no_dash_num.length() != 10) {
  		cout << "Invalid Phone Number." <<endl; 
  	}
}


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
	cin >> this.type; 
	bool num_not_valid = true; 
	
	while(num_not_valid) {
		cout << "Enter the phone number: ";
		string num; 
		cin >> num; 
	
		// Get rid of any non-numbers in num 
	   	string no_dash_num = "";
	    	for (int i=0; i<num.length(); i++){
		    if (isdigit(num[i]) == true){
			no_dash_num = no_dash_num + num[i]; 
		    }
	  	}
	  	
	  	this.num = no_dash_num; 
	  	if(no_dash_num.length() != 10) {
	  		cout << "Invalid Phone Number." <<endl; 
	  	}
	  	else {
	  		num_not_valid = false; 
	  		this.num = no_dash_num; 
	  	}
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 

}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

