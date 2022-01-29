#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int> globalVector;
mutex m;

void writeToV(const int i)
{
    for(int j = 0; j < 3; j++) {
        m.lock();
        globalVector.push_back(i);
        m.unlock();
    }
    return;
}

void readV(const int i)
{
    // m.lock();
    stringstream s;

    s << "Count of " << i << " in v: " << count(globalVector.begin(), globalVector.end(), i) << endl;
    cout << s.str();
    // m.unlock();
    return;
}

ostream& operator<<(ostream& out, const vector<int>& v)
{
    if(v.size() == 0) {
        out << "[]";
        return out;
    }

    out << "[" << v[0];
    for(int i = 1; i < v.size(); i++) {
        out << "," << v[i];
    }
    
    out << "]";

    return out;
}

int main(int argc, char* argv[])
{
    vector<thread> v;

    if(argc < 2) {
        cout << "Usage: ./exo3 n" << endl;
        exit(-1);
    }

    for(int i = 0; i < atoi(argv[1]); i++)
        v.push_back(thread(writeToV, i+1));    

    for (std::thread &t : v)
        t.join();

    cout << "v = " << globalVector << endl;

    vector<thread> v2;
    for(int i = 0; i < atoi(argv[1]); i++)
        v2.push_back(thread(readV, i+1));    

    for (std::thread &t : v2)
        t.join();
    return 0;
}