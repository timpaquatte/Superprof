
#include <math.h>
#include <iostream>

bool isPremier(int nombre)

{   
    if ( nombre == 1)
    {
        return false;
    }

    int diviseur = 2; 
    
    while (((nombre%diviseur != 0) or (diviseur==nombre)) && (diviseur != std::sqrt(nombre)))
    {  
        if ( diviseur < sqrt(nombre))
        {
            diviseur = diviseur + 1;
        }
        else 
        {
            return true;
        }
    }
    return false;
}

int generate_first_premier_after_n(int nombre)
{
    if(isPremier(nombre + 1))
    {
        return nombre + 1;
    }
    return generate_first_premier_after_n(nombre + 1);
}

int pgcd(int a, int b)
{   
    float result = 0;
    int puissance = 0;
    int prem = 2;

    while((a!= 1)&&(b != 1))
    {
       int result_int = 0;

        while ((a % prem == 0)&&(b % prem == 0))
        {
            puissance = puissance + 1;
            a = a / prem;
            b = b /prem;
            result_int = pow(prem, puissance) + result_int;
        }

        result = result + result_int;
        prem = generate_first_premier_after_n(prem);
        // peut pas mettre un continue
        a = a/prem;
        b = b/prem;
        
    }

    return result;
}
int main(int argc, char **argv)
{   
   int reponse = pgcd(30,18);
   std::cout<<reponse;
   return 0;
}