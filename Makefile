.PHONY: all
all:
	@echo "Compiling C file;"
	@gcc -c main.c -o main.o

	@echo "Compiling Assembler file;"
	@nasm -f elf64 -l printf.lst -o printf.o -g printf.asm

	@echo "Linking files;"
	@gcc -no-pie main.o printf.o -o main