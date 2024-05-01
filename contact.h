#ifndef CONTACT_H
#define CONTACT_H
#include <iostream>
#include <string>
using namespace std;

// Make class contact; virtual functions allow for child classes to call different versions of the parent functions
class Contact  {	
	protected: string type; // Private bc children need to access type
	public:
	    	Contact() : type("") {}  // Default constructor   
		virtual void print() = 0;
	  	virtual string get_contact(string style="full") = 0;
		virtual void set_contact() = 0;
};

// Make class Email, child of Contact
class Email: public Contact{
    	protected: string email_addr;
	public:
	    Email() : email_addr("") {}  // Default constructor   
	    Email(string type, string email_addr);
	    virtual ~Email();
	    void print();
	    string get_contact(string style="full");
	    void set_contact();
};

// make class Phone, child of Contact
class Phone: public Contact{
	protected: string phone_num; 
	public:
	    Phone(string type, string phone_number);
	    Phone() : phone_num("") {}  // Default constructor
	    virtual ~Phone(); 
	    void print();
	    string get_contact(string style="full");
	    void set_contact();
};

#endif
