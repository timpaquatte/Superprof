# Exercices pour cette séance

## Exo 1 - Basique

* Ecrire un programme C++ qui prend un entier `n` en argument et qui crée `n` threads qui affichent "Hello World!". Le thread principal doit attendre la fin de chaque thread avant de retourner.

Exemple de déroulé:
```bash
$ ./exo1 5
Hello World!
Hello World!
Hello World!
Hello World!
Hello World!
```

* Faire en sorte que chaque thread se présente avec son ID avant de dire bonjour. (Source: https://en.cppreference.com/w/cpp/thread/thread/get_id)

Exemple:
```bash
./exo1 5
Thread 0x35a7210f: Hello World!
Thread 0x35a7234f: Hello World!
Thread 0x35a7245c: Hello World!
Thread 0x35a73004: Hello World!
Thread 0x35a721c4: Hello World!
```

## Exo 2 - Passage de paramètres

Ecrire un programme C++ qui prend un entier `n` en argument et qui lance `n` threads qui doivent afficher l'ordre dans lequel ils sont lançés. Le thread principal doit attendre la fin de chaque thread avant de retourner.

Exemple:
```bash
./exo2 5
Thread 1
Thread 3
Thread 4
Thread 5
Thread 2
```

## Exo 3 - Utilisation de variable globale

* Ecrire un programme C++ qui prend un entier `n` en argument, déclare un `std::vector<int>` global et le remplit de la façon suivante:

`n` threads sont lançés, chacun doit choisir un entier (par exemple l'ordre avec lequel il est lançé) et l'écrire 3 fois dans le `vector` global.

Finalement le programme affiche le `vector` obtenu lorsque tous les threads ont fini.

Exemple:
```bash
./exo3 4
[1, 2, 2, 1, 1, 3, 3, 4, 2, 5, 3, 4, 5, 5, 4]
```

* Après cela, relancer `n` threads qui comptent le nombre d'apparitions de leur nombre assigné (par exemple leur ordre) et l'affiche.

```bash
./exo3 4
v = [1, 2, 2, 1, 1, 3, 3, 4, 2, 5, 3, 4, 5, 5, 4]
Count of 1 in v: 3
Count of 2 in v: 3
Count of 4 in v: 3
Count of 5 in v: 3
Count of 3 in v: 3
```