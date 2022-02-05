# Exercices pour cette séance

## Exercice 1 : Makefile

Ecrire un Makefile générique qui pourra être utilisé pour compiler les fichiers cpp des exercices suivants.

## Exercice 2 : calcul de la suite de Fibonacci

La suite de Fibonacci est définie de la manière suivante:
```latex
F_0 = 0
F_1 = 1
F_{n+2} = F_{n} + F_{n+1}

Premiers termes:
0 1 1 2 3 5 8 13 ...
```

* Ecrire une fonction récursive `fibonacci` qui prend un paramètre `n` et calcule `F_n` (elle s'appelle elle-même pour calculer les termes n-1 et n-2)
* Améliorer cette fonction en calculant en parallèle (multithread) les termes n-1 et n-2
* Améliorer encore la performance en gardant en mémoire les termes déjà calculés pour ne pas les recalculer. En effet au cours du calcul de nombreux termes sont recalculés plusieurs fois et cela affecte grandement les performances.