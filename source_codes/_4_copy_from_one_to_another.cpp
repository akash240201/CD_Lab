#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string inputFileName, outputFileName;
    ifstream inputFile;
    ofstream outputFile;

    cout << "Enter input file name: ";
    getline(cin, inputFileName);

    cout << "Enter output file name: ";
    getline(cin, outputFileName);

    inputFile.open(inputFileName.c_str());
    outputFile.open(outputFileName.c_str());

    if (!inputFile)
    {
        cerr << "Error: Unable to open input file: " << inputFileName << endl;
        return 1;
    }

    if (!outputFile)
    {
        cerr << "Error: Unable to open output file: " << outputFileName << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
    {
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "File copied successfully!" << endl;

    return 0;
}
