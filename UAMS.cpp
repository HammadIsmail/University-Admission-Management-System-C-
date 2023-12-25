#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>
#include<cmath>
using namespace std;
const int MAX_STUDENTS = 100;
string getField(string record, int field);
float converterToFloat(const string a) ;
float converter(string a);
void menu();
void info();
void header();
void updateInfo();
void deleteInfo();
void addStudent(int ID[] ,string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],  int& count);
void deleteStudent(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count);
void updateStudent(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count);
void viewRecords(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count);
float calculateAggregate(float matric, float inter, float ecat);
bool login();
void signUp();
void loginInfo();
void recordInfo();
void signUpInfo();
void admin(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count);
void Student(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count);
int StudentMenu();
void admission(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count);
int main() {
    system("cls");
           // Intializing the the here
    string names[MAX_STUDENTS];
    string fatherNames[MAX_STUDENTS];
    float matricMarks[MAX_STUDENTS];
    float interMarks[MAX_STUDENTS];
    float ecatMarks[MAX_STUDENTS];
    float aggregates[MAX_STUDENTS];
    int ID[MAX_STUDENTS] ;
   string department[MAX_STUDENTS];
    int count = 0;
    // for color
    system("color 0A");
    // to display UMAS header
    header();
    cout << "Press Enter to Continue.........";
    getch();
    while (true)
    {
    system("CLS");
    info();
    cout<<"Enter (1) for Admin : "<<endl;
    cout<<"Enter (2) for Student : "<<endl;
    cout<<"Enter (3) for Exit : "<<endl;
    cout<<"Choose the Option : ";
    int person;
    cin>>person;
    if (person == 1)
    {
         // Login / Signup part begins here
    while (true)
    {
        system("cls");
        info();
          cout<<"Enter (1) for SignUp : "<<endl;
    cout<<"Enter (2) for Login : "<<endl;
    cout<<"Choose the Option : ";
    int select;
    cin >> select;
     bool loggedIn = false;
    switch (select) {
    case 1:
    // for signup
        system("cls");
        signUpInfo();
        signUp();
        break;
    case 2:
    // for login
            system("cls");
        while (!loggedIn) {
             loginInfo();
            loggedIn = login();

            if (!loggedIn) {
                cout << "Login failed. Please try again." << endl;
                getch();
                system("CLS");
            }
        }
        
       // running function of admin 

    system("cls");
    info();
    admin( ID, names,  fatherNames,  matricMarks,  interMarks,  ecatMarks,  aggregates, department,   count);
    
    default:
        cout << "Invalid Input";
    }
    }
}
else if (person == 2)
{   while (true)
{
    
     int opt=1;
        opt = StudentMenu();
        if (opt ==1 )
        {
       Student( ID, names,  fatherNames,  matricMarks,  interMarks,  ecatMarks,  aggregates, department,   count);
        }
        else if (opt = 2)
        {
    admission( ID, names,  fatherNames, matricMarks,  interMarks,  ecatMarks,  aggregates, department, count);
        }
        else if (opt == 3)
        {
            exit(0);
        }

}

}
else if (person == 3)
{
    exit(0);
}
    return 0;
}
}
/////// Area of Fuctions start from here////////////////////// 

// Logic for Sign up and login
bool login() {
    string username, password, user, pass;

    cout << "~~~> Username: ";
    cin >> username;
    cout << "~~~> Password: ";
    cin >> password;

    fstream fs;
    fs.open("Login.txt", ios::in);
    if (!fs.is_open()) {
        cout << "Error opening Login.txt file." << endl;
        return false;
    }

    getline(fs, user);
    getline(fs, pass);
    fs.close();

    if (username == user && password == pass) {
        return true;
    } else {
        return false;
    }
}

void signUp() {
    fstream fs;
    string username, password;
    cout << "~~~> Username: ";
    cin >> username;
    cout << "~~~> Password: ";
    cin >> password;

    fs.open("Login.txt", ios::out);
    if (!fs.is_open()) {
        cout << "Error opening Login.txt file." << endl;
        return;
    }

    fs << username << endl;
    fs << password << endl;
    fs.close();

    cout << "Login information written to Login.txt successfully." << endl;
    Sleep(1000);
    cout << "Press any Key to Continue........" << endl;
    getch();
}
//////Logic to add student///////

void addStudent(int ID[], string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[], int& count) {
    string discipline;
    int preference[4];
    if (count < MAX_STUDENTS) {
        cout << "Enter ID  = ";
        cin >> ID[count];
        cin.ignore();
        cout << "Enter Your Name = ";
        getline(cin, names[count]);
        cout << "Enter Your Father Name = ";
        getline(cin, fatherNames[count]);
        cout << "Enter Your Matric Marks = ";
        cin >> matricMarks[count];
        cout << "Enter Your Intermediate Marks = ";
        cin >> interMarks[count];
        cout << "Enter Your ECAT Marks = ";
        cin >> ecatMarks[count];
        aggregates[count] = calculateAggregate(matricMarks[count], interMarks[count], ecatMarks[count]);
        cout << "Your Aggregate is = " << aggregates[count] << endl;
                cout << endl;
        cout << "|---- Enter Any 4 preferences ------| " << endl;
        cout<<"~~>(1) Computer Science " << endl;
        cout<<"~~>(2)  Electrical Engineering "<<endl;
        cout<<"~~>(3) Textile Engineering"<<endl;
        cout<<"~~>(4) Chemical Engineering "<<endl;
        cout << endl;
        cin.ignore();
        for (int i = 0; i < 4; i++) {
            cout << "Preference " << i + 1 << " : ";
             cin >> preference[i]; 
        }

        if (aggregates[count] > 80) {
            discipline ="Computer Science";
        } else if (aggregates[count] > 70) {
            discipline = "Electrical Engineering";
        } else if (aggregates[count] > 60) {
            discipline = "Textile Engineering";
        } else if (aggregates[count] > 50) {
            discipline = "Chemical Engineering";
        } else {
            discipline = "-";
        }
        cout << "Record Entered...... " << endl;

        // logic to add data to file
        fstream fs;
        fs.open("StudentData.txt", ios::app);
        if (!fs.is_open()) {
            cout << "Error opening StudentData.txt file." << endl;
            return;
        }

        fs << ID[count] << "," << names[count] << "," << fatherNames[count] << "," << matricMarks[count] << ","
           << interMarks[count] << "," << ecatMarks[count] << "," << aggregates[count] << "," << discipline << endl;

        fs.close();

        count+=1; // Increment count after writing to the file
        getch();
        system("CLS");
    } else {
        cout << "Maximum number of students reached." << endl;
        cin.ignore();
        getch();
        system("CLS");
    }
}

/// Function to view the record ////////////
void viewRecords(int ID[], string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[], string department[], int& count) {
    string record;
    fstream data;
    data.open("StudentData.txt", ios::in);
    int idx = 0;

    while (getline(data, record) && idx < MAX_STUDENTS) {
        ID[idx] = converter(getField(record, 1));
        names[idx] = getField(record, 2);
        fatherNames[idx] = getField(record, 3);
        matricMarks[idx] = converter(getField(record, 4));
        interMarks[idx] = converter(getField(record, 5));
        ecatMarks[idx] = converter(getField(record, 6));
        aggregates[idx] = stof(getField(record, 7));
        department[idx] = getField(record, 8);

        idx = idx + 1;
    }
    count=idx;
        if(idx>0)
        {
        cout << "Following Students Exist in the System" << endl;
        cout << "Index\tID\tName\tFather\tMatric\tIntermediate\tECAT\tAggregate\tDiscipline" << endl;
        for (int i = 0; i < idx; i++) {
            cout << i << "\t" << ID[i] << "\t" << names[i] << "\t" << fatherNames[i] << "\t" << matricMarks[i] << "\t"
                 << interMarks[i] << "\t\t" << ecatMarks[i] << "\t" << aggregates[i] << "\t\t" << department[i];

            cout << endl;
        }
        }
        else
        {
            cout<<"No data to display.....";
        }

    getch();
    system("CLS");
}
// function to calculate aggregate////////
float calculateAggregate(float matric, float inter, float ecat) {
    return (matric * 25) / 1100 + (inter * 45) / 1100 + (ecat * 30) / 400;
}
/// function to check fields;////////////
string getField(string record, int field)
{
    int commaCount = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + record[x];
        }
    }
    return item;
}

/////////////////////////////////////////// Functions for Headers //////////////////////////////////

void header() {
    fstream fs;
    string line;

    fs.open("header.txt", ios::in);
    if (!fs.is_open()) {
        cout << "Error opening header.txt file." << endl;
        return;
    }

    while (!fs.eof()) {
        getline(fs, line);
        cout << line << endl;
    }

    fs.close();
}

void menu()
{
    fstream fs;
    string line;

    fs.open("menu.txt", ios::in);
    if (!fs.is_open()) {
        cout << "Error opening header.txt file." << endl;
        return;
    }

    while (!fs.eof()) {
        getline(fs, line);
        cout << line << endl;
    }

    fs.close();

}

void info()
{
	fstream fs;
    string line;

    fs.open("Info.txt", ios::in);
    if (!fs.is_open()) {
        cout << "Error opening header.txt file." << endl;
        return;
    }

    while (!fs.eof()) {
        getline(fs, line);
        cout << line << endl;
    }

    fs.close();

}
void loginInfo()
{
 fstream fs;
    string line;

    fs.open("loginInfo.txt", ios::in);
    if (!fs.is_open()) {
        cout << "Error opening header.txt file." << endl;
        return;
    }

    while (!fs.eof()) {
        getline(fs, line);
        cout << line << endl;
    }

    fs.close();

}
void recordInfo()
{

 fstream fs;
    string line;

    fs.open("recordInfo.txt", ios::in);
    if (!fs.is_open()) {
        cout << "Error opening recordInfo.txt file." << endl;
        return;
    }

    while (!fs.eof()) {
        getline(fs, line);
        cout << line << endl;
    }

    fs.close();
}

void updateInfo()
{
        fstream fs;
   string line;

    fs.open("updateInfo.txt", ios::in);
    if (!fs.is_open()) {
        cout << "Error opening header.txt file." << endl;
        return;
    }

    while (!fs.eof()) {
        getline(fs, line);
        cout << line << endl;
    }

    fs.close();

}

void deleteInfo()
{
    fstream fs;
 string line;

    fs.open("deleteInfo.txt", ios::in);
    if (!fs.is_open()) {
        cout << "Error opening header.txt file." << endl;
        return;
    }

    while (!fs.eof()) {
        getline(fs, line);
        cout << line << endl;
    }

    fs.close();

}

void signUpInfo()
{
 fstream fs;
    string line;


    fs.open("SignUpInfo.txt", ios::in);
    if (!fs.is_open()) {
        cout << "Error opening header.txt file." << endl;
        return;
    }

    while (!fs.eof()) {
        getline(fs, line);
        cout << line << endl;
    }

    fs.close();
}
/// for converting string to integer and float ////////////
float converter(string a)
{
float result= 0;
int x=0;
while(a[x]!='\0'){
	x=x+1;	
}
for (int n=0;n<x;n++) {
result=result*10+(a[n]-'0');
}
return result;
}

float converterToFloat(const string a) {
    float result = 0.0f;
    int x = 0;

    // Find the length of the string
    while (a[x] != '\0') {
        x = x + 1;
    }

    // Variables to keep track of decimal point and digits after decimal
    int decimalIndex = -1;
    int numDigitsAfterDecimal = 0;

    // Iterate through each character in the string
    for (int n = 0; n < x; n++) {
        if (a[n] == '.') {
            // Found a decimal point
            decimalIndex = n;
        } else {
            // If a digit is found
            result = result * 10 + (a[n] - '0');

            // If a decimal point was found, update the count of digits after the decimal
            if (decimalIndex != -1) {
                numDigitsAfterDecimal++;
            }
        }
    }

    // Adjust the result based on the position of the decimal point
    if (decimalIndex != -1) {
        result = result / pow(10, numDigitsAfterDecimal);
    }

    return result;
}

// Function for admin
void admin(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count)
{
  
      // no of students user wants to enter 
    cout << "Enter the number of students you want to enter: ";
    int numStudents;
    cin >> numStudents;
    
     while (count < numStudents) {
        system("CLS");
        menu();

        int choice;
        cout << "Enter Your Choice = ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("CLS");
            cin.ignore();
            info();
            addStudent(ID,names, fatherNames, matricMarks, interMarks, ecatMarks, aggregates, count);
            system("CLS");
            break;
        case 2:
                    system("CLS");
                    recordInfo();
                viewRecords(ID, names,  fatherNames,  matricMarks,  interMarks,  ecatMarks,  aggregates, department,   count);
                       system("CLS");
            break;
        case 3:
            updateStudent(ID, names,  fatherNames,  matricMarks,  interMarks,  ecatMarks,  aggregates, department,   count);
            system("CLS");
            break;
        case 4:
                   deleteStudent(ID, names,  fatherNames,  matricMarks,  interMarks,  ecatMarks,  aggregates, department,   count);
                   system("cls");
            break;
        case 0:
                exit(0);
        default:
            cout << "Invalid Choice!!!" << endl;

        }
    }        
    }
    /// function for student
void Student(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count)
{
 string record;
    fstream data;
    int rollNo;
    cout<<"Enter the Rollno : ";
    cin>>rollNo;
    data.open("StudentData.txt", ios::in);
   int idx = 0;

    while (getline(data, record) && idx < MAX_STUDENTS) {
        ID[idx] = converter(getField(record, 1));
        names[idx] = getField(record, 2);
        fatherNames[idx] = getField(record, 3);
        matricMarks[idx] = converter(getField(record, 4));
        interMarks[idx] = converter(getField(record, 5));
        ecatMarks[idx] = converter(getField(record, 6));
        aggregates[idx] = converterToFloat(getField(record, 7));
        department[idx] = getField(record, 8);
        if (ID[idx]== rollNo)
        {
            break;
        }
        
        idx = idx + 1;
    }
    system("cls");
    recordInfo();
     cout << "ID\tName\tFather\tMatric\tIntermediate\tECAT\tAggregate\tDiscipline" << endl;
    cout << ID[idx] << "\t" << names[idx] << "\t" << fatherNames[idx] << "\t" << matricMarks[idx] << "\t"
                 << interMarks[idx] << "\t\t" << ecatMarks[idx] << "\t" << aggregates[idx] << "\t\t" << department[idx];
    getch();

}

void deleteStudent(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count)
{
    system("cls");
deleteInfo();
viewRecords(ID, names,  fatherNames,  matricMarks,  interMarks,  ecatMarks,  aggregates, department,count);
if (count>0)
{
 int c = 0;
 fstream student;
 fstream temp;
    string line;
    int opt;
    cout << "ENTER THE STUDENT'S NUMBER WHOSE DATA YOU WANT DELETED (Starting from 0) = ";
    cin >> opt;

    student.open("StudentData.txt", ios::in);
    temp.open("Temp.txt", ios::out);
    while (getline(student, line))
    {
        if (c != opt)
        {
            temp << line << endl;
        }
        c++;
    }
    student.close();
    temp.close();
    remove("StudentData.txt");
    rename("Temp.txt", "StudentData.txt");
    cout << "DATA DELETED ! ";
    getch();
    system("cls");
}
else
{
    cout<<"No data to delete ....";
    getch();
}

}

void updateStudent(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count)
{
      system("cls");
updateInfo();
viewRecords(ID, names,  fatherNames,  matricMarks,  interMarks,  ecatMarks,  aggregates, department,count);
if(count>0){
 int c = 0;
 fstream student;
 fstream temp;
    string line;
    int opt;
    cout << "ENTER THE STUDENT'S NUMBER WHOSE DATA YOU WANT DELETED (Starting from 0) = ";
    cin >> opt;

    student.open("StudentData.txt", ios::in);
    temp.open("Temp.txt", ios::out);
    while (getline(student, line))
    {
        
        if (c == opt)
        {
            cin.ignore();
              cout << "Enter ID  = ";
        cin >> ID[opt];
        cin.ignore();
        cout << "Enter Your Name = ";
        getline(cin, names[opt]);
        cout << "Enter Your Father Name = ";
        getline(cin, fatherNames[opt]);
        cout << "Enter Your Matric Marks = ";
        cin >> matricMarks[opt];
        cout << "Enter Your Intermediate Marks = ";
        cin >> interMarks[opt];
        cout << "Enter Your ECAT Marks = ";
        cin >> ecatMarks[opt];
        aggregates[opt] = calculateAggregate(matricMarks[opt], interMarks[opt], ecatMarks[opt]);
        cout << "Your Aggregate is = " << aggregates[opt] << endl;
        cin.ignore();
        cout << "Enter Your Department = ";
        getline(cin,department[opt]);

        temp << ID[opt] << "," << names[opt] << "," << fatherNames[opt] << "," << matricMarks[opt] << ","
           << interMarks[opt] << "," << ecatMarks[opt] << "," << aggregates[opt] << "," << department[opt] << endl;
        }
       else
        {
            temp << line << endl;
        }
        c++;
    }
    student.close();
    temp.close();
    remove("StudentData.txt");
    rename("Temp.txt", "StudentData.txt");
    cout << "DATA Updated ! ";
    getch();
    system("cls");
}
else
{
    cout<<"No Data to Update ....";
    getch();
}

}

int StudentMenu()
{
    int i=0;
    system("cls");
    cout<<"~~>1 View Your Information : "<<endl;
    cout<<"~~>2 View Your Department : "<<endl;
    cout<<"~~>3 Exit : "<<endl;
    cout<<"~~> Select Option : ";
    cin>>i;
    return i;
}

void admission(int ID[],string names[], string fatherNames[], float matricMarks[], float interMarks[], float ecatMarks[], float aggregates[],string department[],  int& count)
{
    system("cls");
    recordInfo();
 string record;
    fstream data;
    int rollNo;
    cout<<"Enter the Rollno : ";
    cin>>rollNo;
    data.open("StudentData.txt", ios::in);
   int idx = 0;

    while (getline(data, record) && idx < MAX_STUDENTS) {
        ID[idx] = converter(getField(record, 1));

        department[idx] = getField(record, 8);
        if (ID[idx]== rollNo)
        {
            break;
        }
        
        idx = idx + 1;
    }
    system("cls");
    recordInfo();
    if (department[idx]=="-")
    {
        cout<<"Better Luck Next Time !!!";
            getch();
    }
    else
    {
        cout<<"Congratulations!!! You got Admission in "<<department[idx];
            getch();
    }
       
}
