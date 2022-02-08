#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

static int var =0;
mutex m;


int fibonacci(int n)
{
    if (n <= 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}


void task_1(int n)
{
    m.lock();
    var = var + fibonacci(n-1);
    m.unlock();
}

void task_2(int n)
{
    m.lock();
    var = var + fibonacci(n-2);
    m.unlock();
}


int fibo(int n)
{
    std::thread t_n_1 (task_1,n);
    std::thread t_n_2(task_2, n);
    t_n_1.join();
    t_n_2.join();

    return var;
}


int main(int argc, char *argv[])
{
    std::cout<< fibo(atoi(argv[1]))<<std::endl;
    return 0;
}