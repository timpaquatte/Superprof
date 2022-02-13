#include <iostream>
#include <map>

using namespace std;


// Pourquoi n'est-il pas possible de trouver 6 ?

int main(int argc, char *argv[])
{
   std::map<int, int> m;
    m[1] = 4;
    m[2] = 6;
    m[4] = 6;

   if (m.find(7)==m.end())
   {
       std::cout<<"impossible à trouver"<<std::endl;
   }

    if(m.find(6) != m.end())
    {
        std::cout<<"c'est bon trouvé"<<std::endl;
    }
    return 0;
}