
#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>
#include <direct.h>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    Network::loadDB(fileName);
}

Network::~Network(){ 
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person *ptr = head;
    while (ptr != NULL){
        if (ptr == searchEntry) return ptr;
        else {
            ptr = ptr -> next;
        }
    }
    if (ptr == NULL){
        return NULL;
    }
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly. 
    Person *ptr = head;
    while (ptr != NULL){
        if ((ptr-> f_name == fname) & (ptr->l_name == lname)) return ptr;
        else {
            ptr = ptr -> next;
        }
    }
    if (ptr == NULL){
        return NULL;
    }
}




void Network::loadDB(string filename){
    // TODO: Complete this method
    // erase all of the elements of the current LL
    Person* ptr = Network::head;
    while (ptr!= NULL){
        ptr -> ~Person();
        ptr = ptr -> next;
    }

    //read and add the new ones in the format of print_person
    ptr -> prev = NULL;
    count = 0;
    Network::saveDB(filename);

    ptr -> next = NULL;
    
}

void Network::saveDB(string filename){
    // TODO: Complete this method
    Person *ptr = Network::head;
    for (int i = 0; i< Network::count; i++){
        ptr -> set_person(filename);
        ptr -> prev = ptr;
        ptr = ptr -> next;
        count++;
    }
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}



void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Complete this method
    Person * ptr = tail;
    tail -> next = newEntry;
    tail = newEntry;
    newEntry -> prev = ptr;
    newEntry -> next = NULL;

}


bool Network::remove(string fname, string lname){
    // TODO: Complete this method
    Person * ptr = search(fname, lname);
    Person * ptr_prev = NULL;
    Person * ptr_next = NULL;

    if (ptr == NULL) return false;
    else{
        if (ptr == head){
            head = ptr -> next;
            head -> prev = NULL;
            delete ptr; 
        }
        else if (ptr == tail){
            tail = ptr -> prev;
            tail -> next = NULL;
            delete ptr;

        }
        else{
            ptr_prev = ptr -> prev;
            ptr_next = ptr -> next;
            ptr_prev -> next = ptr -> next;
            ptr_next -> prev = ptr_prev;
            delete ptr;
        }
        count--;
    }
 
}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with last name  \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            cin >> fileName;
            saveDB(fileName);
            // Save the network database into the file with the given name,
            // with each person saved in the format the save as printing out the person info,
            // and people are delimited similar to "networkDB.txt" format
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";

            struct dirent **namelist;
            int n;
            n = scandir(".", &namelist, NULL, NULL);
            for (int i = 0; i<n; i++){
                if ((namelist[n]->dname).find(".txt") != -1 )
                cout << namelist[n] ->dname << endl;
            }
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            // print format: one filename one line.
            // This step just shows all the available .txt file to load.
            cout << "Enter the name of the load file: "; 
            // If file with name FILENAME does not exist: 
            cin >> fileName;
            bool flag = 0;
            for (int i = 0; i<n; i++){
                if (fileName.compare(namelist[n]->dname)) flag = 1;
            }
            if (!flag) cout << "File FILENAME does not exist!" << endl;
            // If file is loaded successfully, also print the count of people in it: 
            else {cout << "Network loaded from " << fileName << " with " << count << " people \n";}
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Person ONLY if it does not exists!
            cout << "Adding a new person \n";
            string first_name, last_name;
            cout << "First name: ";
            cin >> first_name;
            cout << "Last name: ";
            cin >> last_name;
            
            Person * new_person_ptr = search(f_name, l_name);
            if (new_person_ptr = NULL) {
                new_person_ptr -> f_name = first_name;
                new_person_ptr -> l_name = last_name;
                push_front(new_person_ptr);
            }
            else cout << "Person not added because they already exist";
            delete first_name, last_name;
            delete new_person_ptr;

        }
        else if (opt == 4){
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            string first_name, last_name;
            cout << "First name: ";
            cin >> first_name;
            cout << "Last name: ";
            cin >> last_name;
            Person * remove_person_ptr = search(first_name, last_name);
            if (remove_person_ptr == NULL) cout << "Person not found! \n";
            else {
                remove(remove_person_ptr -> fname, remove_person_ptr -> lname);
                cout << "Remove Successful! \n";
            }
            delete first_name, last_name;
            delete remove_person_ptr;
        }
        else if (opt==5){
            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            string last_name;
            cout << "Print people with last name \n";
            cin >> last_name;
            cout << "Last name: ";
            Person *ptr = head;
            bool person_found = 0;
            for (i = 0 ; i < count; i++){
                if (!((ptr -> l_name).compare(last_name))){
                    person_found = 1;
                    cout << ptr-> f_name << " " << ptr-> l_name;
                    ptr = ptr->next;
                }
            }
            if (!person_found) cout << "Person not found! \n";
        }
        
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}

