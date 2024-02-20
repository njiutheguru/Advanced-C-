#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Function to replace a certain line in the file with another line
void replaceLineInFile(const string& filename, int lineNum, const string& newLine) {
    ifstream inputFile("records.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open input file." << endl;
        return;
    }

    vector<string> lines;
    string line;

    // Read each line of the file and store them in a vector
    while (getline(inputFile, line)) {
        lines.push_back(line);
    }

    inputFile.close();

    // Check if the specified line number is valid
    if (lineNum <= 0 || lineNum > static_cast<int>(lines.size())) {
        cerr << "Error: Invalid line number." << endl;
        return;
    }

    // Replace the line with the new line
    lines[lineNum - 1] = newLine;

    ofstream outputFile("records.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Cannot open output file." << endl;
        return;
    }

    // Write the modified content back to the file
    for (const string& l : lines) {
        outputFile << l << endl;
    }

    outputFile.close();
}

int main() {
    string filename, newLine;
    int lineNum;

    cout << "Enter the filename: ";
    cin >> filename;

    cout << "Enter the line number to replace: ";
    cin >> lineNum;

    cout << "Enter the new line: ";
    cin.ignore(); // Ignore newline character from the previous input
    getline(cin, newLine);

    replaceLineInFile(filename, lineNum, newLine);

    cout << "Replacement complete." << endl;
    return 0;
}
