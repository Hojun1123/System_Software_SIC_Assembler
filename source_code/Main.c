#include "sic.h"
//#define ERROR(error) printf("ERROR - %s(%d)\n",error, i)
int main(){
	int FILE_LINE=0;
	FILE_LINE = read(s);
	pass1(s, info);
	print_file(s, FILE_LINE);
	print_symtab();
	print_opcode_table();
	pass2(s, info);
}
