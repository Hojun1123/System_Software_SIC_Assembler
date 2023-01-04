#include "sic.h"

#define SYMTAB_SIZE 100

struct symbol_table{
	int location;
	char symbol[7];
};
struct symbol_table st[SYMTAB_SIZE];
int symtab_len=0;

int check_symtab(char *label){
	int i;
	for(i=0; i<symtab_len; i++){
		if(!strcmp(label, st[i].symbol)){
			return 1;
		}
	}
	return 0;
}

void add_symtab(char *label, int location){
	st[symtab_len].location = location;
	strcpy(st[symtab_len].symbol, label);
	symtab_len++;
}

int search_symtab(char *label){
	int i;
	for(i=0; i<symtab_len; i++){
		if(!strcmp(label, st[i].symbol)){;
			return st[i].location;
		}
	}
	return -1;
}

void print_symtab(){
	int i;
	printf("\n______________________________________\n");
	for(i=0; i<symtab_len; i++){
		printf("%s\t%#x\n", st[i].symbol, st[i].location);
	}
}
