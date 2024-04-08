#include "person.h"
//#include "contact.h"
#include "date.h"
#include <fstream>

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    // delete birthdate;
    // // TODO: complete the method!
    // delete l_name;
    // delete f_name;
    // delete email;
    // delete phone; // do these need to be deconstructors in contact?
}


Person::Person(string f_name, string l_name, string b_date, string email, string phone){
    // TODO: Complete this method!
    // phone nd email strings are in full version
    
    this -> f_name = f_name; 
    this -> l_name = l_name; 
    birthdate = new Date(b_date);
    /*
    Contact mail; 
    Contact mail.set_contact(email);
    Contact phone;
    Contact phone.set_contact(phone);
    */
}

/*
Person::Person(string filename){
    set_person(filename);
}
*/

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

	/*
    cout << "Type of email address: ";
    string type_e_temp;
    std::getline(std::cin,email->(type_e_temp));
    
    cout << "Email address: ";
    string e_temp;
    std::getline(std::cin,e_temp);
    
    Contact email = Contact(type_e_temp, e_temp);
    
    cout << "Type of phone number: ";
    string type_p_temp;
    std::getline(std::cin,type_p_temp);
    
    cout << "Phone number: ";
    string type_p_temp;
    std::getline(std::cin, p_temp);
    
    Contact phone = Contact(type_p_temp, p_temp);
    */
}


// void Person::set_person(string filename){
//     // reads a Person from a file
//     // Look at person_template files as examples.     
//     // Phone number in files can have '-' or not.
//     // TODO: Complete this method!
//     ifstream input(filename); 
    
//     getline(input, f_name);
//     getline(input, l_name);
    
//     // string date;
//     // getline(input, date);
//     // birthdate = new Date(date); 
    
//     string type_p;
//     string p;
//     getline(input, type_p, ' ');
//     getline(input, p, ' ');
//     email -> set_contact(type_p, p);
    
    
//     string type_e;
//     string e;
//     getline(input, type_e, ' ');
//     getline(input, e, ' '); 
    
//     email -> set_contact(type_e, e);
// }


bool Person::operator==(const Person& rhs){
	/*
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
	if((this->f_name == rhs.f_name) && (this->l_name == rhs.l_name)) // && (this->birthday == rhs.birthday) )
		return true; 
	else */
		return false;
}

bool Person::operator!=(const Person& rhs){ 
/*
    // TODO: Complete this method!
    	if((this->f_name == rhs.f_name) && (this->l_name == rhs.l_name)) // && (this->birthday == rhs.birthday) )
		return false; 
	else  */
		return true;
}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    //phone->print();
    //email->print();
}
