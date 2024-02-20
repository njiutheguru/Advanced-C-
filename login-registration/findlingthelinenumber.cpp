#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findLineNumber(const string& filename, const string& searchText) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open file." << endl;
        return -1;
    }

    string line;
    int lineNumber = 0;

    // Read each line of the file and check for the search text
    while (getline(inputFile, line)) {
        lineNumber++;
        if (line.find(searchText) != string::npos) {
            inputFile.close();
            return lineNumber;
        }
    }

    inputFile.close();

    // If the search text is not found in the file, return -1
    return -1;
}

int main() {
    string filename, searchText;

    cout << "Enter the filename: ";
    cin >> filename;

    cout << "Enter the line to search: ";
    cin.ignore(); // Ignore newline character from the previous input
    getline(cin, searchText);

    int lineNumber = findLineNumber(filename, searchText);

    if (lineNumber != -1) {
        cout << "The line with the text \"" << searchText << "\" is found at line number: " << lineNumber << endl;
    } else {
        cout << "The text \"" << searchText << "\" is not found in the file." << endl;
    }

    return 0;
}
