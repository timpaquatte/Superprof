#include <iostream>
#include <thread>
#include <vector>
# include <cmath>
using namespace std;

struct Point
{
	float x;
	float y;
	
};

float random(int MIN_RAND,int MAX_RAND)
{
   
    const int range = MAX_RAND - MIN_RAND;
    float random_number = range * ((((int) rand()) / (int) RAND_MAX)) + MIN_RAND ;
    return random_number;

}

void task1(struct Point* centre)
{
    int compt_win(0);
    int compt_try_again(0);
    for(int i(0); i< 10000; i++)
    {
        struct Point lancer;

        lancer.x = random(-1,1);
        
        lancer.y = random(-1,1);

        if( pow(lancer.x - centre->x,2)+ pow(lancer.y - centre->y,2)==4)
        {
             compt_win ++;
        }
        else 
        {
            compt_try_again ++;
        }
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
    struct Point* centre;
    (*centre).x =0;
    (*centre).y =0;


    Create_threads(10,centre);
}