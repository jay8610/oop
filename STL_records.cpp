#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Record {
    string name;
    string dob;
    string telephoneNumber;
};

// Comparator for sorting records by name
bool compareRecords(const Record& a, const Record& b) {
    return a.name < b.name;
}

int main() {
    vector<Record> Records;
    int n;

    // Input number of records
    cout << "Enter the number of personal records: ";
    cin >> n;
    cin.ignore(); // Clear newline character after reading integer input

    if (n <= 0) {
        cout << "No records to process." << endl;
        return 0;
    }

    // Input records
    for (int i = 0; i < n; i++) {
        Record record;
        cout << "Enter name: ";
        getline(cin, record.name); // Allow names with spaces
        cout << "Enter DOB (dd-mm-yyyy): ";
        cin >> record.dob;
        cout << "Enter telephone number: ";
        cin >> record.telephoneNumber;
        cin.ignore(); // Clear newline character after reading
        Records.push_back(record);
    }

    // Sort records by name
    sort(Records.begin(), Records.end(), compareRecords);

    // Display sorted records
    cout << "\nSorted personal records:" << endl;
    for (const Record& record : Records) {
        cout << "Name: " << record.name
             << ", DOB: " << record.dob
             << ", Telephone Number: " << record.telephoneNumber << endl;
    }

    // Search for a record by name
    string searchName;
    cout << "\nEnter name to search: ";
    getline(cin, searchName);

    // Replace lambda with traditional loop for search
    auto it = Records.end();
    for (auto itr = Records.begin(); itr != Records.end(); ++itr) {
        if (itr->name == searchName) {
            it = itr;
            break;
        }
    }

    if (it != Records.end()) {
        cout << "Record found: Name: " << it->name
             << ", DOB: " << it->dob
             << ", Telephone Number: " << it->telephoneNumber << endl;
    } else {
        cout << "Record not found." << endl;
    }

    return 0;
}