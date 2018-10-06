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
    int DOBMonth;
    int DOBday;
    int DOByear;
    int timeServed;
    int salary;
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
    void addEmployee(string newId,string newFirst,string newLast,int MonthDOB,int DayDOB,int yearDOB,int newTime, int newSalary,string newPosition) {
        auto *temp = new employee;
        temp->id = std::move(newId);
        temp->first = std::move(newFirst);
        temp->last = std::move(newLast);
        temp->DOBMonth = std::move(MonthDOB);
        temp->DOBday = std::move(DayDOB);
        temp->DOByear = std::move(yearDOB);
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
                cout << start->id << " "<< start->first << " "<<start->last << " "<< start->DOBMonth << " "<<start->DOBday<<" " << start->DOByear
                <<" " << start->timeServed << " "<< start->salary << " "<< start->position << " "<< endl;
                start=start->next;
            }
    }
    void insert_at_start(string newId,string newFirst,string newLast,int MonthDOB,int DayDOB,int yearDOB,int newTime, int newSalary,string newPosition){
        auto *temp = new employee;
        temp->id = std::move(newId);
        temp->first = std::move(newFirst);
        temp->last = std::move(newLast);
        temp->DOBday = std::move(DayDOB);
        temp->DOByear = std::move(yearDOB);
        temp->timeServed = std::move(newTime);
        temp->salary = std::move(newSalary);
        temp->position = std::move(newPosition);
        temp->next = head;
        head = temp;
    }
    void insertInPosition(string newId,string newFirst,string newLast,int MonthDOB,int DayDOB,int yearDOB,int newTime,int newSalary,string newPosition, int pos){
        employee *temp= new employee;
        employee *current;
        employee *previous= new employee;
        current = head;
        int counter = 0;
        temp->id =std::move(newId);
        temp->first = std::move(newFirst);
        temp->last = std::move(newLast);
        temp->DOBday = std::move(DayDOB);
        temp->DOByear = std::move(yearDOB);
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
    void readCommand( string &path){ // reads the command lines and sorts accordingly
        string line2;
        ifstream myfile( path );
        if (myfile.good()) {
            while (getline(myfile, line2)){
                if (line2.find("sort") != string::npos) {
                    if (line2.find("id") != string::npos) {
                        idBBsort();
                    }
                    if (line2.find("first") != string::npos) {
                        first_BBsort();
                    }
                    if (line2.find("last") != string::npos) {
                        last_BBsort();
                    }
                    if (line2.find("DOB") != string::npos) {
                        DOB_BBsort();
                    }
                    if (line2.find("salary") != string::npos) {
                        salary_BBsort();
                    }
                    if (line2.find("years") != string::npos) {
                        years_BBsort();
                    }
                    if (line2.find("position") != string::npos) {
                        position_BBsort();
                   }
                }
                if (line2.find("add") != string::npos) {
                    if (line2.find("at beginning")) {
                        while (getline(myfile, line2) && isdigit(line2[0])) {
                            stringstream ss(line2);
                            std::string id;
                            std::string first;
                            std::string last;
                            int DOBMonth;
                            int DOBDay;
                            int DOBYear;
                            int timeServed;
                            int salary;
                            std::string position;
                            ss >> id >> first >> last >> DOBMonth >> DOBDay >> DOBYear >> timeServed >> salary >> position;
                            insertInPosition(id, first, last, DOBMonth,DOBDay, DOBYear, timeServed, salary, position, 0);

                        }
                    } else if (line2.find("at end")) {
                        while (getline(myfile, line2) && isdigit(line2[0])) {
                            stringstream ss(line2);
                            std::string id;
                            std::string first;
                            std::string last;
                            int DOBMonth;
                            int DOBDay;
                            int DOBYear;
                            int timeServed;
                            int salary;
                            std::string position;
                            ss >> id >> first >> last >> DOBMonth >> DOBDay >> DOBYear >> timeServed >> salary
                               >> position;

                            addEmployee(id, first, last, DOBMonth, DOBDay, DOBYear , timeServed, salary, position);
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
                    int DOBMonth;
                    int DOBDay;
                    int DOBYear;
                    int timeServed;
                    int salary;
                    std::string position;
                    ss >> id >> first >> last >> DOBMonth >> DOBDay >> DOBYear >> timeServed >> salary >> position;
                    addEmployee(id, first, last, DOBMonth, DOBDay, DOBYear , timeServed, salary, position);

            }
        }else{
            cout << "Experiment Failed" << endl;

        }

    }
    void idBBsort(){ // bubble sort that uses compare to the switch positions
        employee *i, *j;

        for(i=head; i !=nullptr; i=i->next){
            for (j=i->next; j!=nullptr ; j=j->next){
                if(i->id > j->id) {
                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOBMonth,j->DOBMonth);
                    swap(i->DOBday,j->DOBday);
                    swap(i->DOByear,j->DOByear);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
            }
        }
    }
    void first_BBsort() { // bubble sort that uses compare to the switch positions
        employee *i, *j;

        for(i=head; i !=nullptr; i=i->next){
            for (j=i->next; j!=nullptr ; j=j->next){
                if( i->first > j->first) {
                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOBMonth,j->DOBMonth);
                    swap(i->DOBday,j->DOBday);
                    swap(i->DOByear,j->DOByear);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
            }
        }
    }
    void last_BBsort() { // bubble sort that uses compare to the switch positions
        employee *i, *j;

        for(i=head; i !=nullptr; i=i->next){
            for (j=i->next; j!=nullptr ; j=j->next){
                if( i->last > j->last) {
                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOBMonth, j->DOBMonth);
                    swap(i->DOBday, j->DOBday);
                    swap(i->DOByear, j->DOByear);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
            }
        }
    }
    void DOB_BBsort() { // bubble sort that uses compare to the switch positions
        employee *i, *j;

        for(i=head; i !=nullptr; i=i->next) {
            for (j = i->next; j != nullptr; j = j->next) {
                if (i->DOByear > j->DOByear) {
                    swap(i->id, j->id);
                    swap(i->first, j->first);
                    swap(i->last, j->last);
                    swap(i->DOBMonth, j->DOBMonth);
                    swap(i->DOBday, j->DOBday);
                    swap(i->DOByear, j->DOByear);
                    swap(i->timeServed, j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                } else if (i->DOByear == j->DOByear) {
                    if (i->DOBMonth > j->DOBMonth) {
                        swap(i->id, j->id);
                        swap(i->first, j->first);
                        swap(i->last, j->last);
                        swap(i->DOBMonth, j->DOBMonth);
                        swap(i->DOBday, j->DOBday);
                        swap(i->DOByear, j->DOByear);
                        swap(i->timeServed, j->timeServed);
                        swap(i->salary, j->salary);
                        swap(i->position, j->position);
                    }

                } else if (i->DOBday == j->DOBday) {
                    if (i->DOBday > j->DOBday) {
                        swap(i->id, j->id);
                        swap(i->first, j->first);
                        swap(i->last, j->last);
                        swap(i->DOBMonth, j->DOBMonth);
                        swap(i->DOBday, j->DOBday);
                        swap(i->DOByear, j->DOByear);
                        swap(i->timeServed, j->timeServed);
                        swap(i->salary, j->salary);
                        swap(i->position, j->position);
                    }
                }
            }
        }
    }
    void years_BBsort() { // bubble sort that uses compare to the switch positions
        employee *i, *j;
        for(i=head; i !=nullptr; i=i->next){
            for (j=i->next; j!=nullptr ; j=j->next){
                if( i->timeServed > j->timeServed) {
                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOBMonth,j->DOBMonth);
                    swap(i->DOBday,j->DOBday);
                    swap(i->DOByear,j->DOByear);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
            }
        }
    }
    void salary_BBsort(){ // bubble sort that uses compare to the switch positions
        employee *i, *j;
        for(i=head; i !=nullptr; i=i->next){
            for (j=i->next; j!=nullptr ; j=j->next){
                if( i->salary >  j->salary) {


                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->DOBMonth,j->DOBMonth);
                    swap(i->DOBday,j->DOBday);
                    swap(i->DOByear,j->DOByear);
                    swap(i->timeServed,j->timeServed);
                    swap(i->salary, j->salary);
                    swap(i->position, j->position);
                }
            }
        }
    }
    void position_BBsort(){ // bubble sort that uses compare to the switch positions
        employee *i, *j;
        for(i=head; i !=nullptr; i=i->next){
            for (j=i->next; j!=nullptr ; j=j->next){
                if( i->position > j->position) {
                    swap(i->id,j->id);
                    swap(i->first,j->first);
                    swap(i->last,j->last);
                    swap(i->DOBMonth,j->DOBMonth);
                    swap(i->DOBday,j->DOBday);
                    swap(i->DOByear,j->DOByear);
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
    string path= "C:\\Users\\Migue\\Database2.0\\command11.txt";
    ArgumentManager am(argc, argv);
    std::string infilename = am.get("input");
    std::string commandfilename = am.get("command");
    std::string outfilename = am.get("output");
//    std::cout << "File name for input: " << infilename << std::endl
//              << "File name for command: " << infilename << std::endl
//              << "File name for output: " << outfilename << std::endl;



    mylist.build(infilename);
//    commandfilename
    mylist.readCommand(path);
    cout << " \n NO sort \n"<<endl;
    mylist.display();
    cout << "  \n file  sort \n"<<endl;
    mylist.readCommand(path);
    mylist.display();


    return 0;
};
