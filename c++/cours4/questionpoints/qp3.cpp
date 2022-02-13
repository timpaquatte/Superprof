#include <iostream>

// Pourquoi la récursion affiche t-elle 5 4 3 2 1 et pas 1 2 3 4 5 ? 
using namespace std;

int rec(int n)
{
    if(n == 1)
    {  
        std::cout<<n<<std::endl;

        return 1;
    }

    else if(n > 1)
    {
        std::cout<<n<<std::endl;

        return rec(n-1);
    }

}


int main(int argc, char *argv[])
{
    rec(5);
    return 0;
}