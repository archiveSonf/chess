.SILENT:

help:	##Pour voir les options disponibles, et leurs actions
	chmod +x bin/make_file-help
	./bin/make_file-help

run: ##Run le jeu
	chmod +x ./dist/chess.exe
	cd dist && ./chess.exe

files=src/index.c tools/env/*c tools/menu/*.c tools/board/*.c tools/data/*.c

compil: $(files) ##(files:optionnel) Compile les fichiers spécifiers en un fichier éxecutables chess.exe
	gcc -o dist/chess.exe $(files) -lm -ljansson

install: ##Installe les dépendances
	sudo apt update
	sudo apt upgrade
	sudo apt-get install libjansson-dev