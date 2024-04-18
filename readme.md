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
- **src** : module d'entrée du programme 
- **tools** : module contenant les modules utiles dans le programme
    - **board** : module contenant les méthodes de jeu
    - **menu** : module contenant les méthodes de sélection d'options
    - **env** : module contenant les méthodes de mise en place de l'interface sur le terminal
    - **data** : module contenant les méthodes d'écriture et lecture de données.

## Env
## Menu
## Board
## Data