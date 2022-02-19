 #include <iostream>
 #include <thread>
 #include <vector>
 #include <sstream>
    // pb core dumped
 std::vector<std::thread> v;

void task()
{


std::cout<<"thread lance"<<std::endl;



}
int main(int argc, char* argv[])
{
v.push_back(std::thread(task));
for (std::thread &t : v)
        t.join();

 return 0;
}