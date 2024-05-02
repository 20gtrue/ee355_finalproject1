#define _BSD_SOURCE 1
#define _SVID_SOURCE 1
#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <set>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}


Network::Network(string fileName){
    // Implement it in one single line!
    // You may need to implement the load method before this!
    Network::loadDB(fileName);
}

Network::~Network(){ 
    delete head;
    delete tail;
    count = 0;
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    
    //Only search through LL if it has at least one entry
    if (head == NULL) {
        cout << "No entries in DB" << endl;
        return NULL;
    }
    else {
        Person *ptr = head;
        while (ptr != NULL){
            if (ptr == searchEntry) return ptr;
            else {
                ptr = ptr -> next;
            }
        }
        
        return NULL;
    }
    
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // Note: checks fname and lname directly during search

    //Only search if there is at least one entry in the LL
    if (head == NULL) {
        cout << "No entries in DB" << endl;
        return NULL;
    }
    else{
        Person *ptr = head;
        while (ptr != NULL){
            if (((ptr-> f_name).compare(fname) == 0) & ((ptr->l_name).compare(lname) == 0)) return ptr;
            else {
                ptr = ptr -> next;
            }
        }
    }
    
    return NULL;
    
}




void Network::loadDB(string filename){
    // erase all of the elements of the current LL
    Person * ptr = NULL;
    if (head != NULL){
        ptr = head;
        Person* fwd = ptr->next;
        while (ptr!= NULL){
            delete ptr;
            ptr = fwd;
            fwd = fwd ->next;
        }
        count = 0;
    }
    
    // START NEW Linked List
    Person *next_temp;
    Person *prev_temp;

    int line_num = 1; //keeps track of where in the input file the next person to be added is
    ptr = new Person(filename, line_num); // added first person
    count++;
    head = ptr; // set head to 1st person
    ptr->prev = NULL;

    ifstream ifile(filename); //must open the input file to iterate through its lines
    string trash; //dummy variable to store getline data

    //skip through first person in the file since it was already added to LL
     for (int i = 0; i <= 5; i++){ 
            getline(ifile, trash);
            line_num++;
            trash.clear();
    }

    //add the rest of the people while iterating through file lines
    while (!ifile.eof()){
        if (ptr != head) ptr->prev = prev_temp; // set prev pointer 

        next_temp = new Person(filename, line_num); // make new Person
        for (int i = 0; i <= 5; i++){ //skip through file lines
            getline(ifile, trash);
            line_num++;
            trash.clear();
        }
        ptr->next = next_temp; 
        prev_temp = ptr;
        ptr = next_temp;
        count++;
    }
    
    //ptr -> prev = NULL;
    ptr->prev = prev_temp;
    tail = ptr; //set tail
    ptr -> next = NULL;
    
    
}

void Network::saveDB(string filename){
    // prints current database to an output file 
    //source: https://cplusplus.com/reference/ios/ios/rdbuf/

    //only print if there is at least one entry in the DB
    if (head == NULL) cout << "No DB to save!";
    else{
        Person *ptr = head;

        //use streamuf to redirect cout to a file, not the command line
        std::streambuf *newer, *former;
        std::ofstream ofile;
        ofile.open(filename);

        former = cout.rdbuf(); //save the streambuf of the command line so that cout can return to it
        newer = ofile.rdbuf(); //save the strambuf of the output file
        cout.rdbuf(newer); //switch cout to streambuf of output file

        //print person
        for (int i = 0; i < count; i++){
            ptr->print_person();
            ptr = ptr->next;
            //count++;
        }
        cout.rdbuf(former); // switch cout back to command line
    }


    
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    if (head != NULL){
        Person* ptr = head;
        while(ptr != NULL){
            ptr->print_person();
            cout << "------------------------------" << endl;
            ptr = ptr->next;
        }
    }
}



void Network::push_front(Person* newEntry){
    //adds entry to front of LL
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
    cout << "successful push front" << endl;
}


void Network::push_back(Person* newEntry){
    // Adds a new Person (newEntry) to the back of LL
    if (head == NULL){
        push_front(newEntry);
    }
    else{
        Person * ptr = tail;
        tail -> next = newEntry;
        tail = newEntry;
        newEntry -> prev = ptr;
        newEntry -> next = NULL;
    }

}


bool Network::remove(string fname, string lname){
    // Removes entry from LL (uses search(fname, lname) to check if the entry exists first)

    //only search if there is at least one person in the LL
    if (head == NULL) return false;
    else{
        //search if entry exixts
        Person * ptr = search(fname, lname);
        Person * ptr_prev = NULL;
        Person * ptr_next = NULL;
        cout << "about to remove" << endl;;

        if (ptr == NULL) return false; // if entry does not exist
        else{
            if (ptr == head){ //if entry is at head
                head = ptr -> next;
                head -> prev = NULL;
                delete ptr; 
            }
            else if (ptr == tail){ //if entry is at tail
                cout << "remove at tail..." << endl;
                tail = ptr -> prev;
                tail -> next = NULL;
                delete ptr;

            }
            else{ //if entry is in the middle
                ptr_prev = ptr -> prev;
                ptr_next = ptr -> next;
                ptr_prev -> next = ptr -> next;
                ptr_next -> prev = ptr_prev;
                delete ptr;
            }
            count--;
            return true;
        }
    }
 
}


void Network::showMenu(){
    //option 1: uses saveDB to save DB to file
    //option 2: uses loadDB to load in a new DB
    //option 3: uses pushfront to add a new entry
    //option 4: uses remove to remove an entry
    //option 5: uses search to print people with the same last name
    //option 6: allows people to make friends with other people
    
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
        cout << "6. Connect \n";
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
        string fname, lname, fileName, bdate, dummy;
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
            // print format: one filename one line.
            // This step just shows all the available .txt file to load.

            DIR *dirp;
            struct dirent *direntry;
            dirp = opendir(".");
            set<std::string> text_files;
            while ((direntry = readdir(dirp)) != NULL){
                if ((string((direntry->d_name))).find(".txt") != -1) {
                    cout << direntry ->d_name << endl;
                    text_files.insert(string(direntry->d_name));
                }
            }
            
            cout << "Enter the name of the load file: "; 
            // If file with name FILENAME does not exist: 
            cin >> fileName;
            //getline(cin, dummy);
            if (text_files.find(fileName) == text_files.end()) {
                cout << "File "<< fileName <<" does not exist!" << endl;
            // If file is loaded successfully, also print the count of people in it: 
            
            }
            else {
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " people \n";
            }
        }
        else if (opt == 3){

            // Add a new Person ONLY if it does not exists!
            cout << "Adding a new person \n";
            string first_name, last_name;
            cout << "First name: ";
            getline(cin, first_name);
            cout << "Last name: ";
            getline(cin, last_name);
            getline(cin, dummy);
            
            Person * new_person_ptr = search(first_name, last_name);
            if (new_person_ptr == NULL) {
                new_person_ptr = new Person;
                push_front(new_person_ptr);
            }
            else cout << "Person not added because they already exist";
            first_name.clear(); 
            last_name.clear();
            // delete new_person_ptr;

        }
        else if (opt == 4){
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            string first_name, last_name;
            cout << "First name: ";
            getline(cin, first_name);
            cout << "Last name: ";
            getline(cin, last_name);
            Person * remove_person_ptr = search(first_name, last_name);
            if (remove_person_ptr == NULL) cout << "Person not found! \n";
            else {
                remove(remove_person_ptr -> f_name, remove_person_ptr -> l_name);
                cout << "Remove Successful! \n";
            }
            first_name.clear(); 
            last_name.clear();    
        }
        else if (opt==5){
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            string last_name;
            cout << "Print people with last name \n";
            cout << "Last name: ";
            getline(cin, last_name);
            Person *ptr = head;
            bool person_found = 0;
            //for (int i = 0 ; i < count; i++){
            while(ptr != NULL) {
                if (((ptr -> l_name).compare(last_name)) == 0){
                    person_found = 1;
                    cout << ptr-> f_name << " " << ptr-> l_name;
                }
                ptr = ptr->next;
            }
            if (!person_found) cout << "Person not found! \n";
        }
        else if (opt==6) { // connect
            cout <<"Make Friends: " <<endl;
            // Get Person 1 Info
            cout <<"Person 1: " <<endl;
            string first_name_1, last_name_1, first_name_2, last_name_2;
            cout << "First name: ";
            getline(cin, first_name_1);
            cout << "Last name: ";
            getline(cin, last_name_1);
            cout <<endl; 

            Person * person_1 = search(first_name_1, last_name_1);
            if (person_1 == NULL) {
                cout << "Person not found! \n"; 
            }
            else{
                // Get Person 2 Info
                cout <<"Person 2: " <<endl;
                cout << "First name: ";
                getline(cin, first_name_2);
                cout << "Last name: ";
                getline(cin, last_name_2);
                cout <<endl <<endl;

                Person * person_2 = search(first_name_2, last_name_2);
                if (person_2 == NULL){ 
                    cout << "Person 2 not found! \n";
                }
                else { // Both inputs are valid
                    person_1->makeFriend(person_2);
                    person_2->makeFriend(person_1);

                    person_1->print_person();
                    cout <<endl;
                    person_2->print_person();
                }
            }
        }
        else {
            cin.clear();
            cout << "Nothing matched!\n";
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}

