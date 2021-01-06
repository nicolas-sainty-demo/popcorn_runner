##
## EPITECH PROJECT, 2020
## Untitled (Workspace)
## File description:
## Makefile
##

all: comp clean

comp:
	cd lib/my && make && cd ../../
	gcc -o popcorn src/*.c -L./lib/my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window -lm

clean:
	rm -f src/*.o
	rm -f src/*~
	rm -f src/#*#
	rm -f src/a.out
	rm -f src/.gc*

fclean: clean
	rm -f test

re: fclean comp

