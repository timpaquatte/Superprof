#include <iostream>
#include <thread>
#include <vector>
#include <cmath>
#include <mutex>
using namespace std;

// POUR COMPARER CE CODE ET VERSION D'AVANT FAIRE : git pull puis git diff head^
// LA COMMANDE git log --oneline permet d'afficher toutes les modifications
// utiliser CTRL C+ CTRL U 
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
    //chacun des nombres divisés doit être un float non un int.
    // Chacun d'entre eux doit être converti
    return random_number;
}

void task1(struct Point* centre)
{
    int compt_square_local = 0;
    int compt_circle_local = 0;
    //au sein de chaque thread des compteurs récupèrent le nombre de lancers. Si on les met en global 
    //le mutex utilisé pour empêcher tous les threads d'incrémenter en même temps ne permettra l'accès à 
    //la variable que pour un seul thread à la fois ce qui annulera l'intêrêt des threads, le déroulement 
    //de l'execution sera le même que pour une seule grande boucle 
    //Les tirs dans le carré ou dans le cercle mais devront être récupérés après sinon
    //on ne peut pas faire [(nombre de lancé dans cercle)/(nombre de lancers dans carré) ]x4
    for(int i(0); i< 10000; i++)
    {
        struct Point lancer;

        lancer.x = random(-1,1);
        lancer.y = random(-1,1);

        if( pow(lancer.x - centre->x,2)+ pow(lancer.y - centre->y,2)<=1)
            compt_circle_local++;
            //les tirs appartenant au cercle de rayon 1 sont comptés
        compt_square_local++;   
        //tous les  tirs appartiennent de toute façon au carré de côté 2. 
        //Soit uniquement dans le carré, soit dans le carré + cercle. 
        //En effet, le x et leur y sont compris entre -1 et 1
    }

    mutex_1.lock();
    // le mutex est utilisé pour initialisé les compteurs variables globales
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
        //ok sur le fait de passer un pointeur en argument
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
    //attention sur la version réalisée avant il y avait l'erreur core dumped
    //elle n'est pas liée à un manque de libération de la mémoire.
    // Mais aucun objet veritable centre n'était créé, 
    //juste un pointeur qui ne pointait sur rien. C'est ce pb qui causait core dumped. 


    Create_threads(10,&centre);
    // On passe donc l'adresse de l'objet en paramètres pas "centre" en tant que pointeur
    std::cout<<compt_win<<std::endl;
    std::cout<<compt_square<<std::endl;
    
    std::cout<<((float)compt_win/(float)compt_square)*4<<std::endl;

}