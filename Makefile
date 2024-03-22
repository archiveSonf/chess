.SILENT:

help:	##Pour voir les options disponibles, et leurs actions
	chmod +x bin/make_file-help
	./bin/make_file-help

run: ##Run le jeu

compil: $(files) ##(files=value, sys=Linux|Win32) Compile les fichiers spécifiers en un fichier éxecutables chess(wn).exe
	if [ "$(sys)" = "Linux" ]; then \
		gcc -o dist/chess $(files) -lncurses; \
	else \
		gcc -o dist/chesswn $(files); \
	fi