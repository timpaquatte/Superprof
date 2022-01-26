#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <mutex>
using namespace std;

struct Point
{
	float x;
	float y;
};

mutex mutex_1;
int compt_win(0);
int compt_square(0);

float random(int MIN_RAND,int MAX_RAND)
{
    const int range = MAX_RAND - MIN_RAND;
    float random_number = range * ((((float) rand()) / (float) RAND_MAX)) + MIN_RAND ;
    return random_number;
}

void task1(struct Point* centre)
{
    int compt_square_local = 0;
    int compt_circle_local = 0;
    for(int i(0); i< 10000; i++)
    {
        struct Point lancer;

        lancer.x = random(-1,1);
        lancer.y = random(-1,1);

        if( pow(lancer.x - centre->x,2)+ pow(lancer.y - centre->y,2)<=1)
            compt_circle_local++;
        compt_square_local++;        
    }

    mutex_1.lock();
    compt_square += compt_square_local;
    compt_win += compt_circle_local;
    mutex_1.unlock();

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
    std::cout<<compt_square<<std::endl;
    
    std::cout<<((float)compt_win/(float)compt_square)*4<<std::endl;
}