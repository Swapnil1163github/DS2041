#include <iostream>
#include <fstream>

using namespace std;

struct Student {
    int rollNumber;
    string name;
    float marks;

    // Serialization method to write the struct to a file
    friend ostream& operator<<(ostream& os, const Student& student) {
        os << student.rollNumber << ' ' << student.name << ' ' << student.marks;
        return os;
    }

    // Deserialization method to read the struct from a file
    friend istream& operator>>(istream& is, Student& student) {
        is >> student.rollNumber >> student.name >> student.marks;
        return is;
    }
};

void record(fstream& file, const Student& student) {
    file << student << endl;
}

void display(fstream& file) {
    Student student;

    cout << "Roll Number    Name                 Marks" << endl;
    cout << "---------------------------------------------" << endl;

    file.seekg(0, ios::beg); // Move the file pointer to the beginning

    while (file >> student) {
        cout << student.rollNumber << "              " << student.name << "          " << student.marks << endl;
    }
}

void update(fstream& file, int recordNumber, const Student& updatedStudent) {
    file.seekp((recordNumber - 1) * sizeof(Student), ios::beg);
    file << updatedStudent << endl;
}

int main() {
    const string fileName = "student_database.txt"; // Change the file name here

    fstream databaseFile(fileName, ios::in | ios::out);

    if (!databaseFile.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    int choice;
    Student student;

    do {
        cout << "\n1. Add Student Record\n";
        cout << "2. Display All Records\n";
        cout << "3. Update Record at Arbitrary Location\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Roll Number: ";
                cin >> student.rollNumber;

                cout << "Enter Name: ";
                cin.ignore(); // Clear newline character from the buffer
                getline(cin, student.name);

                cout << "Enter Marks: ";
                cin >> student.marks;

                record(databaseFile, student);
                break;

            case 2:
                cout << "\nDisplaying all records:\n";
                display(databaseFile);
                break;

            case 3:
                int recordNumber;
                cout << "Enter Record Number to Update: ";
                cin >> recordNumber;

                cout << "Enter Roll Number: ";
                cin >> student.rollNumber;

                cout << "Enter Name: ";
                cin.ignore(); // Clear newline character from the buffer
                getline(cin, student.name);

                cout << "Enter Marks: ";
                cin >> student.marks;

                update(databaseFile, recordNumber, student);
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    databaseFile.close();

    return 0;
}
