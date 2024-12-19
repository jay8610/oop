#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    int roll;
    char name[30];
    int marks;

    // Default constructor
    Student() {}

    // Function to get data from the user
    void getdata() {
        cout << "\nEnter Student Details -->" << endl;
        cout << "Enter roll no: ";
        cin >> roll;
        cin.ignore(); // To clear the newline character from the input buffer
        cout << "Enter Student's name: ";
        cin.getline(name, 30);
        cout << "Enter marks: ";
        cin >> marks;
    }

    // Function to display data
    void displaydata() const {
        cout << "\nRoll No: " << roll << endl;
        cout << "Student's Name: " << name << endl;
        cout << "Student's Marks: " << marks << endl;
    }
};

int main() {
    Student s[70];
    fstream file;
    int n;

    // Get the number of students
    cout << "Enter Number of Students: ";
    cin >> n;

    // Open file for writing
    file.open("students.txt", ios::out | ios::binary);
    if (!file) {
        cerr << "Error: Could not open file for writing." << endl;
        return 1;
    }

    // Write student data to the file
    for (int i = 0; i < n; i++) {
        s[i].getdata();
        file.write((char *)&s[i], sizeof(s[i]));
    }
    file.close();

    // Open file for reading
    file.open("students.txt", ios::in | ios::binary);
    if (!file) {
        cerr << "Error: Could not open file for reading." << endl;
        return 1;
    }

    // Read and display student data from the file
    cout << "\nReading Student information from the file..." << endl;
    for (int i = 0; i < n; i++) {
        file.read((char *)&s[i], sizeof(s[i]));
        s[i].displaydata();
    }
    file.close();

    return 0;
}