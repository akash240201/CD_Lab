#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename, line;
    int linenum, count = 0;
    cout << "Enter the filename: ";
    cin >> filename;
    cout << "Enter the line number to delete: ";
    cin >> linenum;

    ifstream inputFile(filename);
    ofstream outputFile("temp.txt");

    while (getline(inputFile, line))
    {
        count++;
        if (count == linenum)
            continue; // this will not push the line with linenum to the temp file
        outputFile << line << endl;
    }

    inputFile.close();
    outputFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    cout << "Line " << linenum << " has been removed from " << filename << endl;

    return 0;
}
