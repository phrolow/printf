.PHONY: all
all:
	@gcc -c main.c -o main.o

	@nasm -f elf64 -l printf.lst -o printf.o -g printf.asm

	@gcc -no-pie main.o printf.o -o main

ctoasm:
	@nasm -f elf64 -o stdprintf.o stdprintf.asm

	@gcc -no-pie -o stdprintf stdprintf.o