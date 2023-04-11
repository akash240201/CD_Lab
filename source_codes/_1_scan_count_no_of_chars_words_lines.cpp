#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename;
    ifstream inputFile;
    char c;
    int charCount = 0, wordCount = 0, lineCount = 0;

    // Ask user for file name
    cout << "Enter the name of the file: ";
    getline(cin, filename);

    // Open file
    inputFile.open(filename.c_str());

    // Check if file exists
    if (!inputFile)
    {
        cerr << "Unable to open file " << filename << endl;
        return 1;
    }

    // Read file character by character
    while (inputFile.get(c))
    {
        charCount++;

        // Check for word and line boundaries
        if (isspace(c))
        {
            wordCount++;
        }

        if (c == '\n')
        {
            lineCount++;
        }
    }

    // Add 1 to word and line counts to account for last word/line
    wordCount++;
    lineCount++;

    // Close file
    inputFile.close();

    // Print results
    cout << "Number of characters: " << charCount << endl;
    cout << "Number of words: " << wordCount << endl;
    cout << "Number of lines: " << lineCount << endl;

    return 0;
}
