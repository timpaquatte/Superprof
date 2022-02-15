#include <iostream>
#include <thread>
#include <mutex>
#include <map>
using namespace std;

static int var =0;
mutex m;
map<int, int> mapValues;


void fibonacci(int n, int* returnValue,int nbThreads)
{
    if (n <= 0) {
        *returnValue = 0;
        return;
    }

    if (n == 1) {
        *returnValue = 1;
        return;
    }

    if(mapValues.find(n) != mapValues.end()) 
    {
        *returnValue = mapValues[n];
        return;
    }
    else 
    {   
        if(nbThreads > 1)
        {
            int a, b;
            std::cout << "2 threads sont lancés" << std::endl;
            std::thread t1(fibonacci, n-1, &a,nbThreads/2);
            std::thread t2(fibonacci, n-2, &b,nbThreads/2);
         
            t1.join();
            t2.join();
            *returnValue = a + b;
            mapValues[n] = a + b;

        }

        else

        {   
            int a, b;
            fibonacci(n-1,&a,nbThreads);
            fibonacci(n-1,&b, nbThreads);
            *returnValue = a + b;

        }
        

    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    int cpt = 4;
    fibonacci(atoi(argv[1]), &i, cpt);

    std::cout << i << std::endl;
    return 0;
}