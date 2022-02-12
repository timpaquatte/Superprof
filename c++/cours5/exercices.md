# Exercices pour cette séance

## Exercice 1 - Suite de la séance suivante sur Fibonacci

Reprendre le code précédent calculant la suite de Fibonacci. Le code précédent présente un gros problème: 2 threads sont créés à chaque appel récursif. Il y a donc un nombre exponentiel de threads créés, ce qui finit par ralentir le programme et même le faire crasher.

Afin de corriger cela, faire en sorte que le code n'utilise qu'un nombre défini de threads, par exemple 8. **Ce nombre doit être une puissance de 2**.

Pour cela, la fonction `fibonacci` devra prendre un paramètre de plus appelé `int nbThreads` qui contiendra le nombre de threads disponible. A chaque appel récursif:
* si `nbThreads` est strictement supérieur à 1 alors les deux appels récursifs sont lançés dans des threads distincts.
* sinon les deux appels récursifs sont effectués sans créer de nouveau thread.

