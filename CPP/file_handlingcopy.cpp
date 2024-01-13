#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    if (!outputFile) {
        cerr << "Error opening output file!" << endl;
        return 2;
    }

    // Read the content of the input file into a string
    string content;
    getline(inputFile, content, '\0'); // Read until null character (EOF)

    // Write the string to the output file
    outputFile << content;

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "File copied successfully." << endl;

    return 0;
}
