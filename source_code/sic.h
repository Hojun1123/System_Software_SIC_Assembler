#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 100
#define START_ADDRESS 0x1000
#define ERROR(error) printf("ERROR - %s(%d)\n",error, i)


struct statement {
	char no[7];
    char label[7];//MAX_length = 6
	char opcode[7]; 
    char operand[7];	//대문자 
    int location;
};
struct statement s[MAXLINE];

struct info{
	char name[7];
	int starting_address;
	int length;	//읽어온 텍스트파일 길이
};
struct info info[1];

//pass1.c
int pass1(struct statement *sic, struct info *info);
//pass2.c
int pass2(struct statement *sic, struct info *info);

//symtab.c
int check_symtab(char *label);
void add_symtab(char *label, int location);
int search_symtab(char *label);
void print_symtab();

//optab.c
int check_optab(char *opcode);
int search_optab(char *opcode);
void print_opcode_table();

//fun.c
int read(struct statement *sic);
void print_file(struct statement *sic, int n);
int tohex(char *str);	//return 16
int todec(char *str);	//return 10
int byte_conversion(char *operand, FILE *fp);
