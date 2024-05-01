#include "person.h" 
#include "contact.h"
#include "date.h"
#include <fstream>

// Constructor
Person::Person(){
    set_person();
}

// Deconstructor
Person::~Person(){
    delete birthdate; 
    delete email; 
    delete phone; 
}

// Make new person by sending in all data with function call 
Person::Person(string f_name, string l_name, string b_date, string email_raw, string phone_raw){
    this -> f_name = f_name; 
    this -> l_name = l_name; 
    birthdate = new Date(b_date);
    email = new Email("unknown",email_raw); //TODO: will this work??? no type
    phone = new Phone("unknown",phone_raw);
   
}

// Make new person by sending in a file of data + calling set_person()
Person::Person(string filename, int line_num){
    set_person(filename, line_num);
}

// set_person creates a new person by taking in data inputted by the user
void Person::set_person(){
    string temp;
    string type;

    cout << "First Name: ";
    std::getline(std::cin,f_name);
    
    cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
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

// Makes a new person by reading in person data from a file; called by Person()
void Person::set_person(string filename, int line_num){
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

    string type_e_temp;
    // getline(input,type_e_temp);
    input >> type_e_temp; 

    string e_temp;
    // getline(input,e_temp);
    input >> e_temp; 

    string type_p_temp;
    //getline(input,type_p_temp);
    input >> type_p_temp; 

    string p_temp;
    //getline(input, p_temp);
    input >> p_temp; 
    
    phone = new Phone(type_p_temp,p_temp);
    email = new Email(type_e_temp,e_temp); 
 }

// Compare two people for equality: same first name, last name and birthday
bool Person::operator==(const Person& rhs){
	if((this->f_name == rhs.f_name) && (this->l_name == rhs.l_name) && (this->birthdate->get_date() == rhs.birthdate->get_date()))
		return true; 
	else 
		return false;
}

// Compare two people for inequality: different first name, last name or birthday
bool Person::operator!=(const Person& rhs){ 

    // TODO: Complete this method!
    	if((this->f_name == rhs.f_name) && (this->l_name == rhs.l_name) && (this->birthdate->get_date() == rhs.birthdate->get_date()))
		return false; 
	else  
		return true;
}

// print a person 
void Person::print_person(){
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    	phone->print();
    	email->print();
}
