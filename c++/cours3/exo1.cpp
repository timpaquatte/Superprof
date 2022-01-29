#include <iostream>
#include <thread>
#include <vector>

using namespace std;

void printOrder(const int i)
{
    printf("Thread %d\n", i);
    return;
}

int main(int argc, char* argv[])
{
    vector<thread> v;

    if(argc < 2) {
        cout << "Usage: ./exo2 n" << endl;
        exit(-1);
    }

    for(int i = 0; i < atoi(argv[1]); i++)
        v.push_back(thread(printOrder, i+1));    

    for (std::thread &t : v)
        t.join();

    return 0;
}