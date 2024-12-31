/* Develop a program in c++ to create a database of studen't information system containing the following information.
Name, roll no., class, division, date of birth, blood group, contact address, telephone number, driving license number, and other. 
Construct the database with suitable member function. make use of constructor, default contructor, copy constructor,destructor, 
static memeber functions, friend class, this pointer, inline code, and dynamic memeory allocation operators - new and delete as well as exception*/
#include<iostream>
#include<string>
using namespace std;

class StudData;

class Student {
    string name;
    int roll_no;
    string cls;
    char* division;
    string dob;
    char* bloodgroup;
    static int count;

public:
    Student() // Default Constructor
    {
        name = "";
        roll_no = 0;
        cls = "";
        division = new char[100]; // Allocate memory for division
        dob = "dd/mm/yyyy";
        bloodgroup = new char[10]; // Allocate memory for blood group
    }

    ~Student() {
        delete[] division;  // Deallocate memory for division
        delete[] bloodgroup;  // Deallocate memory for blood group
    }

    static int getCount() {
        return count;
    }

    void getData(StudData*);
    void dispData(StudData*);
};

class StudData {
    string caddress;
    long int* telno;
    long int* dlno;

    friend class Student;

public:
    StudData() {
        caddress = "";
        telno = new long;
        dlno = new long;
    }

    ~StudData() {
        delete telno; // Deallocate memory for telephone number
        delete dlno;  // Deallocate memory for driving license number
    }

    void getStudData() {
        cout << "Enter Contact Address : ";
        cin.get();
        getline(cin, caddress);
        cout << "Enter Telephone Number : ";
        cin >> *telno;
        cout << "Enter Driving License Number : ";
        cin >> *dlno;
    }

    void dispStudData() {
        cout << "Contact Address : " << caddress << endl;
        cout << "Telephone Number : " << *telno << endl;
        cout << "Driving License Number : " << *dlno << endl;
    }
};

inline void Student::getData(StudData* st) {
    cout << "Enter Student Name : ";
    getline(cin, name);
    cout << "Enter Roll Number : ";
    cin >> roll_no;
    cin.get(); // Consume the newline character left by cin >> roll_no
    cout << "Enter Class : ";
    getline(cin, cls);
    cout << "Enter Division : ";
    cin >> division;
    cout << "Enter Date of Birth : ";
    cin.get(); // Consume the newline character
    getline(cin, dob);
    cout << "Enter Blood Group : ";
    cin >> bloodgroup;
    st->getStudData();
    count++;
}

inline void Student::dispData(StudData* st1) {
    cout << "Student Name : " << name << endl;
    cout << "Roll Number : " << roll_no << endl;
    cout << "Class : " << cls << endl;
    cout << "Division : " << division << endl;
    cout << "Date of Birth : " << dob << endl;
    cout << "Blood Group : " << bloodgroup << endl;
    st1->dispStudData();
}

int Student::count;

int main() {
    Student* stud1[100];
    StudData* stud2[100];
    int n = 0;
    char ch;
    do {
        stud1[n] = new Student;
        stud2[n] = new StudData;
        stud1[n]->getData(stud2[n]);
        n++;
        cout << "Do you want to add another student (y/n) : ";
        cin >> ch;
        cin.get();  // Consume the newline character
    } while (ch == 'y' || ch == 'Y');
    
    for (int i = 0; i < n; i++) {
        cout << "---------------------------------------------------------------" << endl;
        stud1[i]->dispData(stud2[i]);
    }
    cout << "---------------------------------------------------------------" << endl;
    cout << "Total Students : " << Student::getCount();
    cout << endl << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++) {
        delete stud1[i];
        delete stud2[i];
    }
    return 0;
}

