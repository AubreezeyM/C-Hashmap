hashmap: main.c hashmap.c
	gcc -Wall -o out main.c hashmap.c

debug: main.c hashmap.c
	gcc -Wall -g -o debug main.c hashmap.c