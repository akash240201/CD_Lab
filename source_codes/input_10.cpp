#include <iostream>

int main()
{
    int a = 10;
    int b = 20;

    if (a == b)
    {
        std::cout << "a is equal to b" << std::endl;
    }
    else if (a < b)
    {
        std::cout << "a is less than b" << std::endl;
    }
    else if (a > b)
    {
        std::cout << "a is greater than b" << std::endl;
    }
    else
    {
        std::cout << "a and b are not comparable" << std::endl;
    }

    int c = a + b;
    int d = a - b;
    int e = a * b;
    int f = b / a;
    int g = b % a;

    std::cout << "c = " << c << std::endl;
    std::cout << "d = " << d << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "f = " << f << std::endl;
    std::cout << "g = " << g << std::endl;

    return 0;
}
