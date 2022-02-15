#include <iostream>
#include <thread>
#include <mutex>
#include <map>
using namespace std;

static int var =0;
mutex m;
map<int, int> mapValues;


void fibonacci(int n, int* returnValue, int nbThreads)
{
    if (n <= 0) {
        *returnValue = 0;
        return;
    }

    if (n == 1) {
        *returnValue = 1;
        return;
    }

    if(mapValues.find(n) != mapValues.end()) {
        *returnValue = mapValues[n];
        return;
    }
    else {
        int a, b;
        if(nbThreads > 1) {
            std::thread t1(fibonacci, n-1, &a, nbThreads/2);
            std::thread t2(fibonacci, n-2, &b, nbThreads/2);
            t1.join();
            t2.join();
        }
        else {
            fibonacci(n-1, &a, nbThreads);
            fibonacci(n-2, &b, nbThreads);
        }
        *returnValue = a + b;
        mapValues[n] = a + b;
    }
}

int main(int argc, char *argv[])
{
    int i = 0;
    fibonacci(atoi(argv[1]), &i, 8);

    std::cout << i << std::endl;
    return 0;
}