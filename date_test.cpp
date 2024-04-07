#include <iostream>
#include "date.h"

int main() {
    string temp;

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    Date *birthdate = new Date(temp); 

    birthdate->print_date("Month D, YYYY");

}
