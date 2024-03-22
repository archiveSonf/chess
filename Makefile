.SILENT:

help:	##Pour voir les options disponibles, et leurs actions
	chmod +x bin/make_file-help
	./bin/make_file-help

run: ##Run le jeu
	chmod +x bin/run
	./bin/run

compil: $(files) ##(files=value, sys=Linux|Win32) Compile les fichiers spécifiers en un fichier éxecutables chess(wn).exe
	if [ "$(sys)" = "Linux" ]; then \
		gcc -o dist/chess $(files) -lncurses; \
	elif [ "$(sys)" = "Win32" ]; then\
		gcc -o dist/chesswn $(files); \
	else \
		printf "\033[1;33mVous n'avez pas specifie vers quel systeme d'expoitation vous voulez compiler !\033[0m\n"; \
	fi