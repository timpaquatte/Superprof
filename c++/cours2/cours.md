# Cours 2 - 18 janvier

## Utilisation de git

Commandes de bases:
```bash
# Cloner un repo
git clone https://github.com/timpaquatte/Superprof.git

# Ajouter les fichiers que l'on veut commit
git add README.md

# Commit les changements (ajouter tous les fichiers à la branche courante)
git commit -m "Message de commit"

# Récupérer les changements sur le repo distant
git pull

# Envoyer les changements sur le repo distant
git push
```

## Les makefiles

### Bases

Le Makefile est une recette qui explique au système les commandes qu'il doit lancer lorsque la commande `make` est utilisée. Il doit s'appeler Makefile ou makefile.

Forme théorique:
```makefile
targets: prerequisites
	command
	command
	command
```

Exemple basique:
```makefile
all: exo1 exo2 exo3

exo1: exo1.cpp
	g++ exo1.cpp -o exo1 -lpthread

exo2: exo2.cpp
	g++ exo2.cpp -o exo2 -lpthread

exo3: exo3.cpp
	g++ exo3.cpp -o exo3 -lpthread

clean:
	rm exo1 exo2 exo3
```

### En utilisant le langage des Makefile

#### Variables

On peut déjà factoriser certaines parties qui se répète, mais les règles sont encore très redondantes:

```makefile
files := exo1 exo2 exo3

all: ${files}

exo1: exo1.cpp
	g++ exo1.cpp -o exo1 -lpthread

exo2: exo2.cpp
	g++ exo2.cpp -o exo2 -lpthread

exo3: exo3.cpp
	g++ exo3.cpp -o exo3 -lpthread

clean:
	rm ${files}
```

#### Variables automatiques

```makefile
hey: one two
	# Outputs "hey", since this is the first target
	echo $@

	# Outputs all prerequisites newer than the target
	echo $?

	# Outputs all prerequisites
	echo $^
```

Notre makefile devient:
```makefile
CXX := g++
LDFLAGS := -lpthread
targets != exo1 exo2 exo3

%: %.cpp
	$(CXX) $? -o $@ ${LDFLAGS}

clean:
	rm -f $(targets)
```

## C++

### Threads

Les threads permettent l'exécution de certaines taches en parallèle dans un programme. Ils se différencient des processus par le fait qu'ils partagent la même mémoire (mais pas la même `stack`).

Lancer et attendre un thread: `std::thread` et `std::thread.join()`

```c++
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

void sayHi(int start, int nb)
{
	std::cout << "Hello World!" << endl;
}
int main(){
	std::thread t1(sayHi);
	t1.join();
	return 0 ;
}
```

Bloquer l'accès à une ressource:
```c++
#include <thread>
#include <mutex>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
mutex m;

void addToV(int start, int nb)
{
	m.lock();
	v.push_back(1);
	m.unlock();
}
int main(){
	std::thread t1(addToV);
	std::thread t2(addToV);
	t1.join();
	t2.join();
	return 0 ;
}
```

