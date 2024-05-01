#include "person.h" //TODO: change names
#include "contact.h"
#include "date.h"
#include "misc.h"
#include <fstream>

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate; 
    delete email; 
    delete phone; 
}


Person::Person(string f_name, string l_name, string b_date, string email_raw, string phone_raw){
    // TODO: Complete this method!
    // phone nd email strings are in full version
    
    this -> f_name = f_name; 
    this -> l_name = l_name; 
    birthdate = new Date(b_date);
    email = new Email("unknown",email_raw); //TODO: will this work??? no type
    phone = new Phone("unknown",phone_raw);
   
}


Person::Person(string filename, int line_num){
    set_person(filename, line_num);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);
    
    cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
     // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

	
    cout << "Type of email address: ";
    string type_e_temp;
    std::getline(std::cin,type_e_temp);
    
    cout << "Email address: ";
    string e_temp;
    std::getline(std::cin,e_temp);
    
  
    cout << "Type of phone number: ";
    string type_p_temp;
    std::getline(std::cin,type_p_temp);
    
    cout << "Phone number: ";
    string p_temp;
    std::getline(std::cin, p_temp);
    
    email = new Email(type_e_temp,e_temp); 
    phone = new Phone(type_p_temp,p_temp);
    
   
    
}


void Person::set_person(string filename, int line_num){
     // reads a Person from a file
     // Look at person_template files as examples.     
     // Phone number in files can have '-' or not.
     // TODO: Complete this method!
    string temp;
    string type;

    fstream input(filename); 
    
    // Shift iterator to desired line number in file
    for (int cur_line = 1; cur_line < line_num; cur_line++) {
        if (!getline(input, temp)) {
            cerr << "Error: Line " << cur_line << endl;
            return;
        }
    }

    getline(input,f_name);
    getline(input,l_name);

    getline(input,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    string type_p_temp;
    //getline(input,type_p_temp);
    input >> type_p_temp; 

    string p_temp;
    //getline(input, p_temp);
    input >> p_temp; 

    string type_e_temp;
    // getline(input,type_e_temp);
    input >> type_e_temp; 

    string e_temp;
    // getline(input,e_temp);
    input >> e_temp; 
    
    phone = new Phone(type_p_temp,p_temp);
    email = new Email(type_e_temp,e_temp); 
 }


bool Person::operator==(const Person& rhs){
	
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
	if((this->f_name == rhs.f_name) && (this->l_name == rhs.l_name) && (this->birthdate->get_date() == rhs.birthdate->get_date()))
		return true; 
	else 
		return false;
}

bool Person::operator!=(const Person& rhs){ 

    // TODO: Complete this method!
    	if((this->f_name == rhs.f_name) && (this->l_name == rhs.l_name) && (this->birthdate->get_date() == rhs.birthdate->get_date()))
		return false; 
	else  
		return true;
}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    phone->print();
    email->print();
    //part2 implementation:
    for (auto& itr : myfriends) {
    	cout << codeName(itr->f_name,itr->l_name) << " " << "(" << itr->f_name << " " << itr->l_name << ")" << endl;
    }
}

//add friend to myfriends vector
void Person::makeFriend(Person* newFriend) {
	myfriends.push_back(newFriend);
}

void Person::pprint_friends() {
	//string code1 = myfriends[0];
	string code2 = "";
	//run through list of myfriends once
	for(auto& itr : myfriends) {
		code2 = codeName(itr->f_name,itr->l_name);
		
		
		
		//afterwards
		//code1 = 
			
		//if(codeName(itr->f_name,itr->l_name)[0] < codeName((itr+1)->f_name,(itr+1)->l_name)[0]) {
		//cout << "true" << endl;
		
		//}
	}
}






