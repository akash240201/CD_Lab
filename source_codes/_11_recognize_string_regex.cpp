#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main()
{
    string str;
    cout << "Enter the string: ";
    cin >> str;
    regex pattern("^(a*|a*b+|abb)$");

    if (regex_match(str, pattern))
    {
        cout << "String matches the pattern!" << endl;
    }
    else
    {
        cout << "String does not match the pattern." << endl;
    }

    return 0;
}

input:
abbbb
aaaaaaaa
akash
abb
