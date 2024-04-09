
#include <iostream>
#include "person_caro.h" //TODO: change name

int main(){

    cout << "P1 ----------------\n";
    Person c1;
    c1.print_person();

    cout << "P2 ----------------\n";
    Person c2("person_template.txt");
    c2.print_person();
    
    cout << "P3 ----------------\n";
    Person c3("person_template_2.txt");
    c3.print_person();
    
    cout << "----------------\n";

    cout << "Is c1 equal to c2: " << (c1==c2) << endl;
    cout << "Is c1 not equal to c2: " << (c1!=c2) << endl;
    cout << "Is c2 equal to c3: " << (c2==c3) << endl;
    cout << "Is c2 not equal to c3: " << (c2!=c3) << endl;
    
    return 0;
}
