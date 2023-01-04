#include "sic.h"

int pass1(struct statement *sic, struct info *info){
	//i�� linecnt�� index, j��symtab�� index 
	int i=0;
	int locctr;
	//START�� ������ �����ּ�����, �̸����� 
	if(!strcmp(sic[0].opcode, "START")){		
		if(!strcmp(sic[0].operand, "null"))
			info[0].starting_address = START_ADDRESS;
		else
			info[0].starting_address= tohex(sic[0].operand);
		strcmp(info[0].name, sic[0].label);
		locctr=info[0].starting_address;
		sic[0].location = locctr;
		i++;
	}
	else{
		ERROR("FILE START ERROR ...");
		return -1;
	}
	while(strcmp(sic[i].opcode, "END")!=0){
		sic[i].location=locctr;
		//label���� �����Ѵٸ�...	
		if(strcmp(sic[i].label, "null")!=0){
			if(check_symtab(sic[i].label)){
				ERROR("SYMTAB OVERLAP");
				return -1; 
			}
			else{
				add_symtab(sic[i].label, locctr);
			}
		}
		
		if(check_optab(sic[i].opcode)){
			locctr += 3;
		}
		else if(!strcmp(sic[i].opcode, "WORD")){
			locctr += 3;
		}
		else if(!strcmp(sic[i].opcode, "BYTE")){
			if(sic[i].operand[0]=='X')
				locctr += (strlen(sic[i].operand)-3)/2;// X'01'ó���ԷµǹǷ� -3
			else if(sic[i].operand[0]=='C')
				locctr += (strlen(sic[i].operand))-3;
		}
		else if(!strcmp(sic[i].opcode, "RESB")){
			locctr += todec(sic[i].operand);
		}
		else if(!strcmp(sic[i].opcode, "RESW")){
			locctr += todec(sic[i].operand)*3;
		}
		else{
			ERROR("NOT FOUND OPCODE");
			return -1;
		}
		i++;
	}
	//END�� ���� ������ �ݺ�
	info[0].length=locctr-info[0].starting_address;
}
