# Chess on terminal

Ce projet vise à réaliser un jeu d'échec complet sur le terminal avec le language séquentiel C.

Fonctionnalités:
1. Lancer une partie multijoueur
1. Sauvegarder une partie
1. Charger une partie
1. Analyser des parties
1. Lancer une partie contre ia

>Les fonctionnalités 4 et 5 ne sont pas encore implémenter.

Auteurs: 

- [@YannDste, yannsonfack@gmail.com](https://github.com/YannDste)
- [@roo7690, roosevelt@roo7690.me](https://github.com/roo7690)

## Installation

Pour lancer le jeu, veuillez suivre ces étapes.

```sh
git clone https://github.com/archiveSonf/chess.git ./chess
make install
make compil
make run
```

## Architecture

- **dist** : contient le fichier executables chess.exe
- **assets** : contient les fichiers de données écrit en json.
- **src** : module d'entrée du programme. 
- **tools** : module contenant les modules utiles dans le programme.
    - **[board](#Board)** : module contenant les méthodes de jeu.
    - **[menu](#Menu)** : module contenant les méthodes de sélection d'options.
    - **[env](#Env)** : module contenant les méthodes de mise en place de l'interface.
    - **[data](#Data)** : module contenant les méthodes d'écriture et lecture de données.

## Env
## Menu
## Board
## Data

Les méthodes du module Data utilise la bibliothèque jansson.h pour stocker lire des données au format json.

### [`SaveGame`](https://github.com/archiveSonf/chess/blob/chess/tools/data/save.c)

Cette méthode permet de sauvagarder une partie terminée ou encours, pour la continuer plustard ou l'analyser.

```c
// Sauvegarde la partie
int SaveGame(char *db_file); 

// db_file => chemin relatif vers la fichier de base de données
// renvoie 1 si l'opération est une réussite.
```

### [`LoadGame`](https://github.com/archiveSonf/chess/blob/chess/tools/data/load.c)

`LoadGame` permet de charger une partie depuis une base de données.

```c
int id=14; //id de la partie
char *db_file="chemin/vers/base/de/données";

GAME *game=LoadGame(id,db_file);
if(game!=NULL)
    runGame(game,NULL,NULL);
```

### [`LoadGames`](https://github.com/archiveSonf/chess/blob/chess/tools/data/load.c)

Cette méthode charge des informations sur les parties sauvegardées sous la structure `Partie`.
```c
typedef struct _partie{
  int id;
  char* player1;
  char* player2;
  struct _partie *next;
  struct _partie *previous;
} Partie;
```
```c
int nb_partie;
char *db_file="chemin/vers/base/de/données";

//Retourne la liste des parties
Partie *list_parties=LoadGames(db_file,&nb_partie);
```
