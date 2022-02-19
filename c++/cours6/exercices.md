# Exercices pour cette séance

## Exercice 1

Faire un Makefile pour tous les autres exercices !!

## Exercice 2 - PGCD récursif

Ecrire un programme qui calcule le PGCD de deux nombres `a` et `b`. 

Le PGCD est le plus grand diviseur commun de deux nombres (https://fr.wikipedia.org/wiki/Plus_grand_commun_diviseur), et vérifie la formule suivante:
```
pgcd(0, a) = a
pgcd(b, a) = pgcd(a, b)
pgcd(a, b) = pgcd(b, a%b) si b != 0 
```