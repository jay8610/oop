#include <iostream>
#include <string>
#include <cstdlib> // For exit()
using namespace std;

class Student {
    int roll;
    string name;
    string address;
    string class_name;
    string dob;
    string licno;
    string blood_gr;
    string mobile_no;

public:
    // Default Constructor
    Student() : roll(0), name(""), address(""), class_name(""), dob(""), licno(""), blood_gr(""), mobile_no("") {}

    // Parameterized Constructor
    Student(int roll, const string& name, const string& address, const string& class_name, const string& dob,
            const string& licno, const string& blood_gr, const string& mobile_no)
        : roll(roll), name(name), address(address), class_name(class_name), dob(dob), licno(licno), blood_gr(blood_gr), mobile_no(mobile_no) {}

    // Function to accept student details
    void accept() {
        cout << "\nEnter roll number: ";
        cin >> roll;
        cin.ignore(); // Clear the newline from the input buffer
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter address: ";
        getline(cin, address);
        cout << "Enter class name: ";
        getline(cin, class_name);
        cout << "Enter DOB (dd/mm/yyyy): ";
        getline(cin, dob);
        cout << "Enter license number: ";
        getline(cin, licno);
        cout << "Enter blood group: ";
        getline(cin, blood_gr);
        cout << "Enter mobile number: ";
        getline(cin, mobile_no);
    }

    // Function to display student details
    void display() const {
        cout << "\nRoll: " << roll;
        cout << "\nName: " << name;
        cout << "\nAddress: " << address;
        cout << "\nClass: " << class_name;
        cout << "\nDOB: " << dob;
        cout << "\nLicense No: " << licno;
        cout << "\nBlood Group: " << blood_gr;
        cout << "\nMobile No: " << mobile_no << endl;
    }
};

int main() {
    int ch, n = 0;
    Student students[20]; // Array to store student records

    while (true) {
        cout << "\nMenu\n1. Accept Student Details\n2. Display All Students\n3. Exit\nEnter Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter number of students (max 20): ";
            cin >> n;
            if (n <= 0 || n > 20) {
                cout << "Invalid number of students. Please try again.\n";
                break;
            }
            for (int i = 0; i < n; i++) {
                cout << "\nEntering details for Student " << (i + 1) << ":\n";
                students[i].accept();
            }
            break;

        case 2:
            if (n == 0) {
                cout << "No student details available. Please add details first.\n";
                break;
            }
            for (int i = 0; i < n; i++) {
                cout << "\nDisplaying details of Student " << (i + 1) << ":\n";
                students[i].display();
            }
            break;

        case 3:
            cout << "Exiting the program. Goodbye!\n";
            exit(0);

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}