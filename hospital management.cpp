#include <iostream>
#include <limits>

using namespace std;

struct Address {
    string street;
    string city;
    string state;
};

struct Patient {
    string name;
    int age;
    Address address;
    string condition;
};

const int MAX_PATIENTS = 10;
Patient patients[MAX_PATIENTS];
int patientCount = 0;

void addPatient() {
    if (patientCount < MAX_PATIENTS) {
        Patient& newPatient = patients[patientCount];
        cout << "Enter patient name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newPatient.name);

        cout << "Enter patient age: ";
        while (!(cin >> newPatient.age) || newPatient.age <= 0) {
            cout << "Invalid input. Please enter a valid age: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter patient address (street city state): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newPatient.address.street);
        getline(cin, newPatient.address.city);
        getline(cin, newPatient.address.state);

        cout << "Enter patient condition: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, newPatient.condition);

        patientCount++;

        cout << "Patient added successfully!" << endl;
    } else {
        cout << "Maximum patient limit reached." << endl;
    }
}

void displayPatients() {
    if (patientCount > 0) {
        cout << "Patient List:" << endl;
        for (int i = 0; i < patientCount; ++i) {
            const Patient& patient = patients[i];
            cout << "ID: " << i + 1 << "\tName: " << patient.name << "\tAge: " << patient.age
                 << "\tAddress: " << patient.address.street << ", " << patient.address.city << ", " << patient.address.state
                 << "\tCondition: " << patient.condition << endl;
        }
    } else {
        cout << "No patients in the system." << endl;
    }
}

void searchPatient() {
    if (patientCount > 0) {
        cout << "Enter patient ID to search: ";
        int searchId;
        while (!(cin >> searchId) || searchId < 1 || searchId > patientCount) {
            cout << "Invalid input. Enter a valid patient ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        const Patient& patient = patients[searchId - 1];
        cout << "Patient Found:\n"
             << "Name: " << patient.name << "\tAge: " << patient.age
             << "\tAddress: " << patient.address.street << ", " << patient.address.city << ", " << patient.address.state
             << "\tCondition: " << patient.condition << endl;
    } else {
        cout << "No patients in the system." << endl;
    }
}

void updatePatient() {
    if (patientCount > 0) {
        cout << "Enter patient ID to update: ";
        int updateId;
        while (!(cin >> updateId) || updateId < 1 || updateId > patientCount) {
            cout << "Invalid input. Enter a valid patient ID: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Patient& patient = patients[updateId - 1];
        cout << "Enter new condition for patient: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, patient.condition);

        cout << "Patient information updated successfully!" << endl;
    } else {
        cout << "No patients in the system." << endl;
    }
}

int main() {
    int choice;

    do {
        cout << "\nHospital Management System\n"
             << "1. Add Patient\n"
             << "2. Display Patients\n"
             << "3. Search Patient\n"
             << "4. Update Patient\n"
             << "5. Exit\n"
             << "Enter your choice: ";

        while (!(cin >> choice) || (choice < 1 || choice > 5)) {
            cout << "Invalid input. Enter a number between 1 and 5: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice) {
            case 1:
                addPatient();
                break;
            case 2:
                displayPatients();
                break;
            case 3:
                searchPatient();
                break;
            case 4:
                updatePatient();
                break;
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
