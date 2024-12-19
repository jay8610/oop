#include <iostream>
using namespace std;

class Details {
    int age;
    int income;
    int vehicle;
    string city;

public:
    // Constructor
    Details() {
        // Age validation
        while (true) {
            try {
                cout << "Exception Handling!" << endl;
                cout << "Enter age: ";
                cin >> age;
                if (age > 18 && age < 55) {
                    cout << "Access Granted\n" << endl;
                    break;
                } else {
                    throw age;
                }
            } catch (int age) {
                cout << "You are not eligible." << endl;
                cout << "Your Age must be between 18 and 55! Your Age is: " << age << endl;
                cout << "Please re-enter your age.\n" << endl;
            }
        }

        // Income validation
        while (true) {
            try {
                cout << "Enter income: ";
                cin >> income;
                if (income > 50000 && income < 100000) {
                    cout << "Access Granted\n" << endl;
                    break;
                } else {
                    throw income;
                }
            } catch (int income) {
                cout << "You are not eligible." << endl;
                cout << "Your Income must be between 50000 and 100000! Your Income is: " << income << endl;
                cout << "Please re-enter your income.\n" << endl;
            }
        }

        // City validation
        while (true) {
            try {
                cout << "Enter your City: ";
                cin >> city;
                if (city == "Pune" || city == "Mumbai" || city == "Bangalore" || city == "Chennai") {
                    cout << "Access Granted\n" << endl;
                    break;
                } else {
                    throw city;
                }
            } catch (const string& city) {
                cout << "You are not eligible." << endl;
                cout << "You must live in cities like Pune, Mumbai, Bangalore, or Chennai! Your City is: " << city << endl;
                cout << "Please re-enter your City.\n" << endl;
            }
        }

        // Vehicle type validation
        while (true) {
            try {
                cout << "Enter Your Vehicle Type (Eg: Enter 4 for 4-wheeler): ";
                cin >> vehicle;
                if (vehicle == 4) {
                    cout << "Access Granted\n" << endl;
                    break;
                } else {
                    throw vehicle;
                }
            } catch (int vehicle) {
                cout << "You are not eligible." << endl;
                cout << "You must have a 4-wheeler! Your Vehicle Type is: " << vehicle << " Wheeler(s)" << endl;
                cout << "Please re-enter your Vehicle Type.\n" << endl;
            }
        }
    }
};

int main() {
    Details a;
    cout << "Thank you for showing your interest!" << endl;
    return 0;
}