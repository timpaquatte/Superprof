#include <iostream>
#include <thread>
#include <vector>
# include <cmath>
#include<mutex>
using namespace std;

struct Point
{
	float x;
	float y;
	
};

mutex mutex_1;
int compt_win(0);
int compt_try_again(0);

float random(int MIN_RAND,int MAX_RAND)
{
   
    const int range = MAX_RAND - MIN_RAND;
    float random_number = range * ((((float) rand()) / (float) RAND_MAX)) + MIN_RAND ;
    return random_number;

}

void task1(struct Point* centre)
{
    
    for(int i(0); i< 10000; i++)
    {
        struct Point lancer;

        lancer.x = random(-1,1);
        
        lancer.y = random(-1,1);
        std::cout<<lancer.x<<std::endl;
        std::cout<<lancer.y<<std::endl;
        std::cout<<pow(lancer.x - centre->x,2)+ pow(lancer.y - centre->y,2)<<std::endl<<std::endl;

        if( pow(lancer.x - centre->x,2)+ pow(lancer.y - centre->y,2)<=1)
       
        {    
            mutex_1.lock();
            compt_win ++;
            mutex_1.unlock();
        }
        
          
            mutex_1.lock();
            compt_try_again ++;
            mutex_1.unlock();
        
    }
}

void Create_threads(int n, struct Point* centre)

{  
    vector<thread> threads;

    for(int i(0); i<n ;i ++)
    {
           threads.push_back(thread(task1,centre));
        
    }
    
     for(int i(0); i<n ;i ++)
    {
        threads[i].join();
         
    }
}
int main(int argc, char *argv[])
{
    struct Point centre;
    centre.x =0;
    centre.y =0;


    Create_threads(10,&centre);
    std::cout<<compt_win<<std::endl;
    std::cout<<compt_try_again<<std::endl;
    
    std::cout<<((float)compt_win/(float)compt_try_again)*4<<std::endl;
}