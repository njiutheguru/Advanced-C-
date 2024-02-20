#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void replaceWordsInFile() {
    ifstream inputFile("records.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Cannot open input file." << endl;
        return;
    }

    string line;
    string content;

    // Read the entire content of the file
    while (getline(inputFile, line)) {
        content += line + '\n';
    }

    inputFile.close();

    string oldWord, newWord;
    cout << "Enter the word to replace: ";
    cin >> oldWord;
    cout << "Enter the new word: ";
    cin >> newWord;

    // Replace all occurrences of the old word with the new word in the content
    size_t pos = 0;
    while ((pos = content.find(oldWord, pos)) != string::npos) {
        content.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }

    ofstream outputFile("records.txt");
    if (!outputFile.is_open()) {
        cerr << "Error: Cannot open output file." << endl;
        return;
    }

    // Write the modified content back to the file
    outputFile << content;
    outputFile.close();

    cout << "Replacement complete." << endl;
}

int main() {
    string "records.txt";

    cout << "Enter the "records.txt": ";
    cin >> "records.txt";

    replaceWordsInFile("records.txt");

    return 0;
}
