#include "person.h" 
#include "contact.h"
#include "date.h"
#include "misc.h"
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

    // Part 2.3 Addition; printing friends:
    for (auto& itr : myfriends) {
    	cout << codeName(itr->f_name,itr->l_name) << " " << "(" << itr->f_name << " " << itr->l_name << ")" << endl;
    }
    
}

//add friend to myfriends vector
void Person::makeFriend(Person* newFriend) {
	myfriends.push_back(newFriend);
}

//pretty prints friends in sorted order by sorting myfriends list of person
void Person::pprint_friends() {
	string code1 = "";
	string code2 = "";
	Person temp("temp", "temp", "01/22/2023", "temp","111-111-1111");
	int sorted = 0; //flag saying it's not sorted


	while(sorted == 0) {
	//run through list of myfriends once
	sorted = 1;
	code1 = codeName(myfriends[0]->f_name,myfriends[0]->l_name);
	
	for(int i=1;i<myfriends.size();i++) {
		code2 = codeName(myfriends[i]->f_name,myfriends[i]->l_name);
		
		if(code1[0] > code2[0]) {
			//need to swap
			temp = *myfriends[i-1];
			*myfriends[i-1] = *myfriends[i];
			*myfriends[i] = temp;
			
			//cout << "swapped " << code1 << " with " << code2 << endl;
			sorted = 0;
		}
		else if(code1[0] == code2[0]) { 
			//check second letter of code
			if(code1[1] > code2[1]) {
				//need to swap
				temp = *myfriends[i-1];
				*myfriends[i-1] = *myfriends[i];
				*myfriends[i] = temp;
				
				//cout << "swapped " << code1 << " with " << code2 << endl;
				sorted = 0;	
			}
			//otherwise just leave them as is
			
		}
		
		//afterwards update code1
		code1 = code2;
	}}
	
	//now everything has been sorted in myfriends, so we can just print friends in order they're in
	
	cout << f_name << ", " << l_name << endl;
	cout << "--------------------------------" << endl;
	for (auto& itr : myfriends) {
    		cout << itr->f_name << ", " << itr->l_name << endl;
    	}
	
}






