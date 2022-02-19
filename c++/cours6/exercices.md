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

## Exo 3 - Multithread - Utilisation de variable globale

* Ecrire un programme C++ qui prend un entier `n` en argument ainsi qu'un entier `nbThreads`, déclare un `std::vector<int>` global et le remplit de `n` nombres aléatoires entre 0 et `nbThreads - 1`.

Ensuite, lancer `nbThreads` threads qui doivent compter les occurences de chaque nombre et les afficher. Chaque thread doit compter un nombre différent.

```bash
./exo3 10 5
v = [1, 2, 4, 3, 4, 0, 1, 3, 2, 4]
Count of 1 in v: 2
Count of 2 in v: 2
Count of 4 in v: 2
Count of 0 in v: 1
Count of 3 in v: 3
```