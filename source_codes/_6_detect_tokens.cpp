#include <bits/stdc++.h>
using namespace std;

void findTokens(string program)
{
    int n = program.length();
    int left = 0;
    vector<string> tokens;
    for (int i = 0; i < n; i++)
    {
        char c = program[i];
        if (c == ' ')
        {
            string token = program.substr(left, i - left);
            tokens.push_back(token);
            left = i + 1;
        }
    }
    // printing the tokens
    cout << "The tokens are: " << endl;
    for (string str : tokens)
    {
        cout << str << ", ";
    }
    cout << endl;
}

int main()
{
    string program;
    // cout<<"Enter the program to find the tokens: ";
    // cin>>program;
    string prog = "printf ( ' hello world ' ) ; ";
    findTokens(prog);
    return 0;
}
