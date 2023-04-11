#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int main()
{
    // Open the input file
    ifstream inputFile("input_8.cpp");
    if (!inputFile.is_open())
    {
        cerr << "Error: Unable to open input file" << endl;
        return 1;
    }

    // Define the regular expressions for comments
    regex singleLineCommentRegex("//.*");
    regex multiLineCommentRegex("/\\*.*?\\*/");

    // Open the output file
    ofstream outputFile("comments.txt");
    if (!outputFile.is_open())
    {
        cerr << "Error: Unable to open output file" << endl;
        return 1;
    }

    // Read the input file line by line and extract comments
    string line;
    while (getline(inputFile, line))
    {
        // Extract single-line comments
        smatch singleLineMatch;
        if (regex_search(line, singleLineMatch, singleLineCommentRegex))
        {
            outputFile << singleLineMatch.str() << endl;
        }

        // Extract multi-line comments
        smatch multiLineMatch;
        if (regex_search(line, multiLineMatch, multiLineCommentRegex))
        {
            outputFile << multiLineMatch.str() << endl;
        }
    }

    // Close the files
    inputFile.close();
    outputFile.close();

    return 0;
}
