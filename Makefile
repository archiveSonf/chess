.SILENT:

help:	##Pour voir les options disponibles, et leurs actions
	chmod +x bin/make_file-help
	./bin/make_file-help

run: ##Run le jeu

compil: $(files) ##Compile les fichiers spécifiers en un fichier éxecutables chess.exe
	gcc -o dist/chess.exe $(files) -lncurses