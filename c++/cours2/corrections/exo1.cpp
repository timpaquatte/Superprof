#include <iostream>
#include <thread>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void printHelloWorld(void)
{
    cout << "Hello World!\n";
    return;
}

void introduceThenPrint(void)
{
    stringstream s;

    s << "Thread 0x" << hex << this_thread::get_id() << ": Hello World!\n";
    cout << s.str();
    return;
}

int main(int argc, char* argv[])
{
    vector<thread> v;

    if(argc < 2) {
        cout << "Usage: ./exo1 n" << endl;
        exit(-1);
    }

    for(int i = 0; i < atoi(argv[1]); i++)
        v.push_back(thread(introduceThenPrint));    

    for (std::thread &t : v)
        t.join();

    return 0;
}