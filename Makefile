.SILENT:

help:
	chmod +x bin/make_file-help
	./bin/make_file-help

run: ##Run le jeu

compil: $(files) ##Compile les fichiers spécifiers en fichier éxecutables chess.exe
	gcc -o dist/chess.exe $(files) -lSDL2