.SILENT:

help:	##Pour voir les options disponibles, et leurs actions
	chmod +x bin/make_file-help
	./bin/make_file-help

run: ##Run le jeu
	chmod +x ./dist/chess.exe
	cd dist && ./chess.exe

<<<<<<< HEAD
files=src/index.c tools/menu/*.c tools/*.c tools/board/*.c
=======
files=src/index.c tools/menu/*.c tools/board/*.c tools/*.c
>>>>>>> 9f09701a2b157a281f30013a8b732ece7a45d4a5

compil: $(files) ##(files:optionnel) Compile les fichiers spécifiers en un fichier éxecutables chess.exe
	gcc -o dist/chess.exe $(files)