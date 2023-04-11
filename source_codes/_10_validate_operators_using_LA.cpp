#include <iostream>
#include <string>

using namespace std;

bool is_rel(char ch)
{
    if (ch == '<' || ch == '>' || ch == '!' || ch == '=')
        return true;
    return false;
}

bool is_bit(char ch)
{
    if (ch == '&' || ch == '^' || ch == '~' || ch == '|')
        return true;
    return false;
}

bool is_ari(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
        return true;
    return false;
}

void fun(char ch[])
{
    if (is_rel(ch[0]) && (ch[1] == '=' || ch[1] == '\0'))
    {
        cout << "\nIt is relational operator";
        return;
    }

    if ((is_bit(ch[0]) && ch[1] == '\0') || ((ch[0] == '<' || ch[0] == '>') && ch[0] == ch[1]))
    {
        cout << "\nIt is bitwise operator";
        return;
    }

    if (((ch[0] == '&' || ch[0] == '|') && ch[0] == ch[1]) || (ch[0] == '!' && ch[1] == '\0'))
    {
        cout << "\nIt is logical operator";
        return;
    }

    if (ch[0] == '?' && ch[1] == ':')
    {
        cout << "\nIt is ternary operator";
        return;
    }

    if ((ch[0] == '+' || ch[0] == '-') && ch[0] == ch[1])
        cout << "\nIt is unary operator";
    else if ((is_ari(ch[0]) && ch[1] == '=') || (ch[0] == '=' && ch[1] == '\0'))
        cout << "\nIt is assignment operator";
    else if (is_ari(ch[0]) && ch[1] == '\0')
        cout << "\nIt is arithmetic operator";
}

int main()
{
    char ch[2];

    cout << "Enter the string: ";
    cin >> ch;

    fun(ch);
    return 0;
}


// input: 
// - 
// +
// =
// <
// >
