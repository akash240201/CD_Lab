#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Student
{
    string name;
    int rollNo;
    float gpa;
};

int main()
{
    ofstream outputFile("students.txt");
    if (!outputFile)
    {
        cerr << "Error: could not open file" << endl;
        return 1;
    }

    char continueInput = 'y';
    while (continueInput == 'y')
    {
        Student s;

        cout << "Enter student name: ";
        getline(cin, s.name);

        cout << "Enter student roll number: ";
        cin >> s.rollNo;

        cout << "Enter student GPA: ";
        cin >> s.gpa;

        outputFile << s.name << " " << s.rollNo << " " << s.gpa << endl;

        cout << "Do you want to enter details of another student? (y/n): ";
        cin >> continueInput;
        cin.ignore();
    }

    outputFile.close();

    return 0;
}
