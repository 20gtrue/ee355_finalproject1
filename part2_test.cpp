#include <iostream>
#include "date.h"
#include "person.h"
#include "date.h"
#include "misc.h"

int main() {
    cout << "P1 ----------------\n";
    Person c1;
    c1.print_person();
    
    cout << "P2 ----------------\n";
    Person c2;
    
    
    //Person* temp;
    //temp = c2;
    
    //in the connect menu option, just need these commands:
    c1.makeFriend(&c2);
    c2.makeFriend(&c1);
    
    c2.print_person();
    

}
