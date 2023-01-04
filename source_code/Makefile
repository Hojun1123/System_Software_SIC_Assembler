program_exe : Main.o func.o optab.o symtab.o pass1.o pass2.o
	gcc -o program_exe Main.o func.o optab.o symtab.o pass1.o pass2.o

Main.o : Main.c
	gcc -c -o Main.o Main.c

func.o : func.c
	gcc -c -o func.o func.c

optab.o : optab.c
	gcc -c -o optab.o optab.c

symtab.o : symtab.c
	gcc -c -o symtab.o symtab.c

pass1.o : pass1.c
	gcc -c -o pass1.o pass1.c

pass2.o : pass2.c
	gcc -c -o pass2.o pass2.c
