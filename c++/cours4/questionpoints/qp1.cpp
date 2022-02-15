#include <iostream>

using namespace std;
//////////////////////////////////////////////////////////////////////////////////////////://
// Pourquoi le code n'affiche t-il pas 11111 ? 

int rec(int n)
{
    if (n==0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    if (n ==1)
    {
        std::cout << 1 << std::endl;
        return 1;
    }

    else
    {
        int a;
        a = rec(n-1);
        std::cout << a << std::endl;
        return a;
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    i = rec(atoi(argv[1]));
    std::cout << i << std::endl;
    return 0;
}