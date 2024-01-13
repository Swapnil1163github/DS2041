#include <iostream>

using namespace std;

class DrivingLicense {
private:
    int age;

public:
    DrivingLicense(int personAge) : age(personAge) {
        if (age < 18) {
            throw "You are not eligible for driving. Minimum age requirement is 18.";
        }
    }

    void displayLicenseInfo() {
        cout << "Congratulations! You are eligible for driving with a valid license." << endl;
        // Additional license information can be displayed here
    }
};

int main() {
    try {
        int personAge;
        cout << "Enter your age: ";
        cin >> personAge;

        DrivingLicense license(personAge);
        license.displayLicenseInfo();
    }
    catch (const char* message) {
        cerr << "Error: " << message << endl;
    }

    return 0;
}
