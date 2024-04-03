.SILENT:

help:	##Pour voir les options disponibles, et leurs actions
	chmod +x bin/make_file-help
	./bin/make_file-help

run: ##Run le jeu
	chmod +x ./dist/chess.exe
	cd dist && ./chess.exe

<<<<<<< HEAD
files=src/index.c tools/menu/*.c tools/*.c tools/board/*.c

compil: $(files) ##(files:optionnel) Compile les fichiers spécifiers en un fichier éxecutables chess.exe
	gcc -o dist/chess.exe $(files) -lncurses -std=c99
=======
files=src/index.c tools/menu/*.c tools/board/*.c tools/*.c

compil: $(files) ##(files:optionnel) Compile les fichiers spécifiers en un fichier éxecutables chess.exe
	gcc -o dist/chess.exe $(files) -lm
>>>>>>> cbbf7c22d886ecdebe472da52fde8b5762b9a827
