#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    ofstream outputFile("output.txt", ios::app);  // Open the file in append mode

    if (!outputFile) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    // Content to be appended
    string contentToAppend = "This content is appended to the file.";

    // Append the content to the file
    outputFile << contentToAppend << endl;

    // Close the file
    outputFile.close();

    cout << "Content appended to the file successfully." << endl;

    return 0;
}
