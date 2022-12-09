
#include <list>
#include <iostream>


using namespace std;
int numofstudents = 0;

struct student
{
    string lastname;
    string firstname;
    int age;
    int studentno;
};
student studentlist[30];




void addrecord(){

     cout << "ADD RECORD" << endl;
     cout << "Student Number : ";
     cin >> studentlist[numofstudents].studentno;
     cout << "Last Name : ";
     cin >> studentlist[numofstudents].lastname;
     cout << "First Name : ";
     cin >> studentlist[numofstudents].firstname;
     cout << "Age : ";
     cin >> studentlist[numofstudents].age;
     numofstudents++;
     cout << "1 Record Added" << endl;
     
}

void editrecord(){
     int stuno;
     cout << "EDIT RECORD" << endl;
     cout << "Student Number : ";
     cin >> stuno;
     int index = -1;
     for (int i = 0; i < numofstudents; i++)
     {
         if (stuno == studentlist[i].studentno)
         {
             index = i;
         }
     }

     if (index == -1) 
     {
         cout << "Record does not exist" << endl;
     }

     else 
     {
     cout << "Last Name : ";
     cin >> studentlist[index].lastname;
     cout << "First Name : ";
     cin >> studentlist[index].firstname;
     cout << "Age : ";
     cin >> studentlist[index].age;
     cout << "1 Record Updated" << endl;
     
     }

}



void deleterecord(){
     int stuno;
     cout << "DELETE RECORD " << endl;
     cout << "Student Number : ";
     cin >> stuno;
     int index = -1;
     for (int i = 0; i < numofstudents; i++)
     {
         if (stuno == studentlist[i].studentno)
         {
             index = i;
         }
     }

     if (index == -1) 
     {
         cout << "Record does not exist" << endl;
         
     }

     else 
     {
     
     for (int i = index; i < numofstudents - 1; i++)
     {
         if (stuno == studentlist[i].studentno)
         {
             studentlist[i].studentno = studentlist[i + 1].studentno;
             studentlist[i].lastname = studentlist[i + 1].lastname;
             studentlist[i].firstname = studentlist[i + 1].firstname;
             studentlist[i].age = studentlist[i + 1].age;
         }
     }
     numofstudents--;
     cout << "1 Record Deleted" << endl;
     
     }

}


void menu(){
    int choice;
    cout << "----------\nMenu\n----------\n";
    cout << "1. Add Record\n2. Edit Record\n3. Delete Record \n4. List Records \n" ;
    cout << "Enter Option : ";
    cin >> choice;
    switch (choice){
    case 1:
    addrecord();
    menu();
    break;

    case 2:
    editrecord();
    menu();
    break;

    case 3:
    deleterecord();
    menu();
    break;

    case 4:
    for(int i = 0; i < numofstudents; i++)
    {
        cout << "-------------------------------------------------\n";
        cout <<  "Student Number : " << studentlist[i].studentno << endl;
        cout <<  "Last Name : " << studentlist[i].lastname << endl;
        cout <<  "First Name : " << studentlist[i].firstname << endl;
        cout <<  "Age : " << studentlist[i].age << endl;
        cout << "-------------------------------------------------\n";
    }
    menu();
    break;

    default:
    cout << "Invalid input. Terminating...";

    }
}


int main() {
    
    while (numofstudents < 3)
    {
     cout << "ADD RECORD" << endl;
     cout << "Student Number : ";
     cin >> studentlist[numofstudents].studentno;
     cout << "Last Name : ";
     cin >> studentlist[numofstudents].lastname;
     cout << "First Name : ";
     cin >> studentlist[numofstudents].firstname;
     cout << "Age : ";
     cin >> studentlist[numofstudents].age;
     numofstudents++;
    }

    menu();
    return 0;
}