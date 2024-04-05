#include <iostream>
#include <string>
#include "contact.h"
#include "person.h"

using namespace std;


int main() {
    // Test Cases for Contact.cpp  
        // Email e1 = Email("Work", "gtrue@usc.edu");
        // e1.print();
        // Email e2; 
        // e2.set_contact();
        // e2.print();


        // Phone p1 = Phone("Work", "9253894592");
        // p1.print();
        // Phone p2 = Phone("Mobile", "213-284-8422");
        // p2.print();
        // Phone p3; 
        // p3.set_contact();
        // p3.print();
        // Phone p4; 
        // p4.set_contact();
        // p4.print();

    // Test cases for Person.cpp
    Person p1 = Person("grace", "true", "7/2/2002", "gtrue@usc.edu", "9253894592");
    p1.print_person();
    return 0;
}