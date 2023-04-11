#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename, wordToDelete, tempFileName, line;
    cout << "Enter the name of the file to delete word from: ";
    cin >> filename;
    cout << "Enter the word to delete: ";
    cin >> wordToDelete;
    tempFileName = "temp.txt";

    // Open input file
    ifstream inputFile(filename.c_str());
    if (!inputFile)
    {
        cerr << "Error: Unable to open input file: " << filename << endl;
        return 1;
    }

    // Open output file
    ofstream outputFile(tempFileName.c_str());
    if (!outputFile)
    {
        cerr << "Error: Unable to open output file: " << tempFileName << endl;
        return 1;
    }

    // Read input file line by line and write to output file
    while (getline(inputFile, line))
    {
        size_t pos = line.find(wordToDelete);
        while (pos != string::npos)
        {
            // Erase the word from the line
            line.erase(pos, wordToDelete.length());
            // Look for the next occurrence of the word
            pos = line.find(wordToDelete, pos);
        }
        outputFile << line << endl;
    }

    // Close input and output files
    inputFile.close();
    outputFile.close();

    // Replace original file with temporary file
    remove(filename.c_str());
    rename(tempFileName.c_str(), filename.c_str());

    cout << "Word \"" << wordToDelete << "\" deleted from file \"" << filename << "\"" << endl;
    return 0;
}
