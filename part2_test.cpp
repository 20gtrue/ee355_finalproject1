#include <iostream>
#include "date.h"
#include "person.h"
#include "date.h"
#include "misc.h"

int main() {
    //cout << "P1 ----------------\n";
    //Person c1;
    //c1.print_person();
    
    //cout << "P2 ----------------\n";
    //Person c2;
    
    Person c3("Caro", "Dwo", "01/22/2023", "em","571-645-4154");
    Person c4("Grace", "Tr", "01/22/2023", "em","571-645-4154");
    Person c5("Tali", "Em", "01/22/2023", "em","571-645-4154");
    Person c6("Sha", "Na", "01/22/2023", "em","571-645-4154");
    Person c7("Sage", "Wat", "01/22/2023", "em","571-645-4154");
    Person c8("Apple", "Pie Too", "01/22/2023", "em","571-645-4154");
    
    c3.makeFriend(&c4);
    c3.makeFriend(&c5);
    c3.makeFriend(&c6);
    c3.makeFriend(&c7);
    c3.makeFriend(&c8);
    
    
    //c3.print_person();
    c3.pprint_friends();
    
    //c3.print_person();
    
    cout << "test" << endl;
    //in the connect menu option, just need these commands to make 2 people friends with each other: 
    //c1.makeFriend(&c2);
    //c2.makeFriend(&c1);
    
    //c2.print_person();
    

}
