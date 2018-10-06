#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include "ArgumentManager.h"

using namespace std;

struct employee{
    std::string id;
    std::string first;
    std::string last;
    std::string DOB;
    std::string timeServed;
    std::string salary;
    std::string position;
    employee *next;
    employee(){next = nullptr;}


};

class list {
private:
    employee *head;
    employee *tail;
public:
    list() {
        head = nullptr;
        tail = nullptr;
    }
    void addEmployee(string newId,string newFirst,string newLast,string newDOB,string newTime, string newSalary,string newPosition) {
        auto *temp = new employee;
        temp->id = std::move(newId);
        temp->first = std::move(newFirst);
        temp->last = std::move(newLast);
        temp->DOB = std::move(newDOB);
        temp->timeServed = std::move(newTime);
        temp->salary = std::move(newSalary);
        temp->position = std::move(newPosition);
        temp->next = nullptr;

        if (head == nullptr) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    void display(){
        string line;
        employee *start = head;
            while(start!= nullptr){
                cout << start->id << " "<< start->first << " "<<start->last << " "<< start->DOB <<" "<< start->timeServed << " "<< start->salary << " "<< start->position << " "<< endl;
                start=start->next;
            }
    }
    void insert_at_start(string newId,string newFirst,string newLast,string newDOB ,string newTime, string newSalary,string newPosition){
        auto *temp = new employee;
        temp->id = std::move(newId);
        temp->first = std::move(newFirst);
        temp->last = std::move(newLast);
        temp->DOB = std::move(newDOB);
        temp->timeServed = std::move(newTime);
        temp->salary = std::move(newSalary);
        temp->position = std::move(newPosition);
        temp->next = head;
        head = temp;
    }
    void insertInPosition(string newId,string newFirst,string newLast,string newDOB,string newTime, string newSalary,string newPosition, int pos){
        employee *temp= new employee;
        employee *current;
        employee *previous= new employee;
        current = head;
        int counter = 0;
        temp->id =std::move(newId);
        temp->first = std::move(newFirst);
        temp->last = std::move(newLast);
        temp->DOB = std::move(newDOB);
        temp->timeServed = std::move(newTime);
        temp->salary = std::move(newSalary);
        temp->position = std::move(newPosition);
        previous->next=temp;
        temp->next=current;
        if (pos == 0)
        {
            temp->next = head;
            head = temp;
        }
        else while(current!= nullptr && counter < pos){
                counter++;
                previous = current;
                current=current->next;
            }
    }

    void deleteAtBeg(){
        employee *temp= head;
        head = head->next;
        delete temp;
    }

    void deleteAtPosition(int pos){
        employee *current;
        current = head;
        auto * previous=new employee;
        int counter = 0;
        while(current!= nullptr && counter < pos){
            counter++;
            previous= current;
            current=current->next;
        }
        previous->next=current->next;
    }

    void delByInput(const string &del){
        auto *current = head;
        employee *previous = nullptr;
        if(head->id == del){
            employee *temp;
            temp = head;
            head = head->next;
            delete temp;
        }else{
            while(current->next != nullptr && current->id != del){
                previous=current;
                current=current->next;
            }
            previous->next=current->next;
            if(previous->next ==nullptr){
                tail =previous;

            }
            delete current;
        }
    }

    void deleteAtEnd(){ // deletes a node a the end of the least by stoping at the second to last and making that the tail
        employee *current;
        auto *previous =new employee;
        current = head;
        while (current->next != nullptr and head!= nullptr){
            previous =current;
            current=current->next;
             }
        tail = previous;
        previous->next= nullptr;
        delete current;
        if (head== nullptr && tail== nullptr){
            cout <<"list is empty" << endl;

        }
    }
    void readCommand(const string &commandfilename){ // reads the command lines and sorts accordingly
        string line;
        ifstream myfile(commandfilename);
        if (myfile.good()){
            cout <<" something inside the if mysort line" << endl;

            while (getline( myfile, line ).good()){
                  cout <<" something inside the good line" << endl;
                if (line.find("sort") != string::npos){
                    cout <<" something inside line find sort" << endl;

                    if(line.find("id")){
                        BBsort("id");
                    }
                    if(line.find("first")){
                        BBsort("first");
                    }
                    if(line.find("last")){
                        BBsort("last");
                    }
                    if(line.find("DOB")){
                        BBsort("DOB");
                    }
                    if(line.find("salary")){
                        BBsort("salary");
                    }
                    if(line.find("years")){
                        BBsort("timeServed");
                    }
                    if(line.find("position")){
                        BBsort("position");
                    }
                }
                if(line.find("add") != string::npos) {
                    if (line.find("at beginning")) {
                        while (getline(myfile, line) && isdigit(line[0])) {
                            stringstream ss(line);
                            std::string id;
                            std::string first;
                            std::string last;
                            std::string DOBMonth;
                            std::string DOBDay;
                            std::string DOBYear;
                            std::string timeServed;
                            std::string salary;
                            std::string position;
                            ss >> id >> first >> last >> DOBMonth >> DOBDay >> DOBYear >> timeServed >> salary
                               >> position;
                            std::string DOB = DOBMonth + " " + DOBDay + " " + DOBYear;
                            insertInPosition(id, first, last, DOB, timeServed, salary, position, 0);

                        }
                    } else if (line.find("at end")) {
                        while (getline(myfile, line) && isdigit(line[0])) {
                            stringstream ss(line);
                            std::string id;
                            std::string first;
                            std::string last;
                            std::string DOBMonth;
                            std::string DOBDay;
                            std::string DOBYear;
                            std::string timeServed;
                            std::string salary;
                            std::string position;
                            ss >> id >> first >> last >> DOBMonth >> DOBDay >> DOBYear >> timeServed >> salary >> position;
                            std::string DOB = DOBMonth + " " + DOBDay + " " + DOBYear;
                            addEmployee(id, first, last, DOB, timeServed, salary, position);
                        }
                    }
                }

            }

        }else{
            cout <<"This is the else for the mysortfile" << endl;
        }

    }
    void build(const string &infilename) { // reads and stores from a txt file
        string line;
        ifstream myfile( infilename );
        if (myfile.good())
        {
           while (getline( myfile, line ).good())
            {

                    stringstream ss(line);
                    std::string id;
                    std::string first;
                    std::string last;
                    std::string DOBMonth;
                    std::string DOBDay;
                    std::string DOBYear;
                    std::string timeServed;
                    std::string salary;
                    std::string position;
                    ss >> id >> first >> last >> DOBMonth >> DOBDay >> DOBYear >> timeServed >> salary >> position;
                    std::string DOB = DOBMonth + " " + DOBDay + " " + DOBYear;
                    addEmployee(id, first, last, DOB, timeServed, salary, position);

            }
        }else{
            cout << "Experiment Failed" << endl;

        }

    }
    void BBsort(const string &instructions){ // bubble sort that uses compare to the switch positions
        employee *i, *j;
        for(i=head; i !=nullptr; i=i->next){
            for (j=i->next; j!=nullptr ; j=j->next){
                if( instructions == "position" && i->position.compare(j->position) > 0){
                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOB,j->DOB);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
                if( instructions == "id" &&  i->id >j->id){
                    cout << "sorted id" << endl;
                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOB,j->DOB);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
                if( instructions == "years" && i->timeServed.compare(j->timeServed) > 0){
                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOB,j->DOB);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
                if( instructions == "first" && i->first.compare(j->first) > 0){

                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOB,j->DOB);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
                if( instructions == "last" && i->last.compare(j->last) > 0){
                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOB,j->DOB);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
                if( instructions == "salary" && i->salary.compare(j->salary) > 0){
                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOB,j->DOB);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
            }
        }
    }

};


int main(int argc, char* argv[])
{
    list mylist;
    ArgumentManager am(argc, argv);
    std::string infilename = am.get("input");
    std::string commandfilename = am.get("command");
    std::string outfilename = am.get("output");
//    std::cout << "File name for input: " << infilename << std::endl
//              << "File name for command: " << infilename << std::endl
//              << "File name for output: " << outfilename << std::endl;



    mylist.build(infilename);
//    commandfilename
    mylist.readCommand(commandfilename);
    mylist.display();

    return 0;
};
