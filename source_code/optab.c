#include "sic.h"

#define OPT_NUM 24

struct opcode_table {
	char mnemonic[7];
	int opcode;//16Áø¼ö
};

struct opcode_table opt[] =
{
	{"ADD",0x18}, {"AND",0x40},{"COMP",0x28},{"DIV",0x24},{"J",0x3c},{"JEQ",0x30},
	{"JGT",0x34}, {"JLT",0x38},{"JSUB",0x48},{"LDA",0x00},{"LDL",0x08},{"MUL",0x20},
	{"OR",0x44}, {"RSUB",0x4c},{"STA",0x0c},{"STL",0x14},{"STX",0x10},{"TD",0xe0},
	{"TIX",0x2c},{"LDX",0x04},{"STCH",0x54},{"WD",0xdc},{"RD",0xd8},{"LDCH",0x50}
};

struct opcode_table directive[] =
{
	{"START"},{"END"},{"BYTE"},{"WORD"},{"RESB"},{"RESW"}
};

int check_optab(char *opcode){
	int i;
	for(i=0; i<OPT_NUM; i++){
		if(!strcmp(opcode, opt[i].mnemonic))
			return 1;
	}
	return 0;
}

int search_optab(char *opcode){
	int i;
	for(i=0; i<OPT_NUM; i++){
		if(!strcmp(opcode, opt[i].mnemonic))
			return opt[i].opcode;
	}
	return -1;
}

void print_opcode_table(){
	int i;
	printf("\n______________________________________\n");
	for(i=0; i<OPT_NUM; i++){
		printf("%d.\t%s\t%#.2x\n",i,opt[i].mnemonic, opt[i].opcode);
	}
}
