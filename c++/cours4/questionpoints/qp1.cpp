#include <iostream>

using namespace std;

// Pourquoi le code n'affiche t-il pas 11111 ? 

void rec(int n, int* return_value)
{
    if (n==0)
    {
        *return_value = 0;
        std::cout << *return_value << std::endl;
        return;
    }

    if (n ==1)
    {
        *return_value = 1;
        std::cout << *return_value << std::endl;
        return;
    }

    else
    {
        int a;
        rec(n-1,&a);
        std::cout << a << std::endl;
        return;
    }
}


int main(int argc, char *argv[])
{
    int i = 0;
    rec(atoi(argv[1]), &i);
    std::cout << i << std::endl;
    return 0;
}