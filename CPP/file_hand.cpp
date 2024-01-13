#include <iostream>
#include <fstream>

using namespace std;

int main() {
    // Writing to a file
    ofstream outputFile("example.txt");

    if (outputFile.is_open()) {
        outputFile << "Hello, this is a sample line." << endl;
        outputFile << "Writing to a file in C++ is easy!" << endl;
        outputFile.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;  // Exit with an error code
    }

    // Reading from a file
    ifstream inputFile("example.txt");

    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cerr << "Unable to open file for reading." << endl;
        return 1;  // Exit with an error code
    }

    return 0;
}