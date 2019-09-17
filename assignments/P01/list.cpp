//Kevin McNeil Jr.
#include <iostream>
#include <fstream>

using namespace std;

bool string_match(string big, string small)
{
    int index = big.find(small);
    return index >= 0;
}

string lower_string(string orig)
{
    string result = "";
    for (int i = 0; i < orig.size(); i++)
    {
        result += tolower(orig[i]);
    }
    return result;
}

struct Employee{
    string emp_id; 
    string first_name;
    string last_name;
    string gender;
    string email;
    double hourly_pay;
    Employee *next;

    Employee(){
        emp_id = "";
        first_name = "";
        last_name = "";
        gender = "";
        email = "";
        hourly_pay = 0.0;
    }

    Employee(string id,string first,string last,string sex,string mail, double pay){
        emp_id = id;
        first_name = first;
        last_name = last;
        gender = sex;
        email = mail;
        hourly_pay = pay;
    }
};

class LinkedList{
private:
    Employee* head;
    Employee* last;

public:
    LinkedList(){
        head = NULL;
        last = NULL;
    }


    void frontSert(string id,string first,string last,string sex,string mail, double pay){
        Employee* Temp = new Employee(id,first,last,sex,mail,pay);

        if(head == NULL){
            head = Temp;
        }else{
            Temp->next = head;
            head = Temp;
        }
        
    }

    //set to remove front of list, collects 2 spots to hold onto so we dont lose our place in the list
    //prints out to confirm what we removed.
    void pop()
    {
        Employee *tempDel = head;
        Employee *temp = head -> next;
        cout << "Removed: " << tempDel->emp_id << ", " <<tempDel->first_name << ", " <<tempDel->last_name << endl;
        delete tempDel;
        head = temp;
        
    }

    //adds a new Employee to front of list with given data
    void push(string id,string first,string last,string sex,string mail, double pay)
    {
        Employee *temp = new Employee(id,first,last,sex,mail,pay);
        head = temp;
        cout << "Added: " << temp->emp_id << ", " <<temp->first_name << ", " << temp->last_name << endl;
        
    }

    //finds email substring and returns true if found and cout results for user
    bool find(string emp)
    {
        Employee *temp = head;
        while (temp != NULL)
        {
            if (string_match(lower_string(temp->email), lower_string(emp)))
            {
                cout << "Match found: " << temp->email << endl; 
                return true;
            }
            else
            {
                temp = temp->next;
            }
        }
        cout << "No match found!" << endl;
        return false;
    }

    //deletes select user even if substring is used and cout result
    void del(string emp)
    {
        Employee *temp = head;
        while (temp != NULL)
        {
            if (string_match(lower_string(temp->email), lower_string(emp)))
            {
                cout << temp ->email  << " has been deleted!" << endl;
                delete temp;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }
    }

    void print(){
        Employee* Temp = head;

        //created for loop to only print the 1st 30 of list, rest of list is read in main
        for(int i = 0; i < 30; i++){
            cout<<Temp->emp_id<<", "<<Temp->first_name<<", "<<Temp->last_name<<", "<<Temp->email<<", "<<Temp->gender<<", "<<Temp->hourly_pay << endl;
            Temp = Temp->next;
        }
    }
};

int main(){

    LinkedList EmpList;

    string empid;
    string first;
    string last;
    string email;
    string gender;
    double pay;

    string line;
    string *tokens;
    ifstream fin("employees.dat");

    //reads entire file and creates list EmpList
    while(!fin.eof()){

        fin>>empid>>first>>last>>email>>gender>>pay;
        EmpList.frontSert(empid,first,last,email,gender,pay);
    }


    //test methods to confirm they worked
    EmpList.print();
    EmpList.find("salon");
    EmpList.find("asdfssafasd");
    EmpList.del("salon");
    EmpList.push("20", "Kevin", "McNeil", "Male", "aadf@aadf.com", 10000000.00);
    EmpList.pop();
    

    return 0;
}