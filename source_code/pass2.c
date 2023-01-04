#include "sic.h"
#define c fprintf(fp, "^")

int pass2(struct statement *sic, struct info *info){
	int i=0,j=0;
	FILE *fp = fopen("result.obj","w");
	
	if(!strcmp(sic[0].opcode, "START")){		
		fprintf(fp, "H");c;
		fprintf(fp, "%-6s",sic[0].label);c;
		fprintf(fp, "%06x",info[0].starting_address);c;
		fprintf(fp, "%06x\n",info[0].length);
		i++;
	}
	else{
		ERROR("FILE START ERROR ...");
		return -2;
	}
	
	fprintf(fp, "T");c;
	fprintf(fp, "%06x",sic[i].location);c;
	fprintf(fp, "--");c;
	
	int tmp;
	int opcode,operand;
	int fp_len=3,line_len=0;//count_separator
	
	while(strcmp(sic[i].opcode, "END")!=0){
		
		tmp=search_optab(sic[i].opcode);//optab�� opcode�� ������... 
		if(tmp != -1){
			opcode=tmp;
			if(strcmp(sic[i].operand, "null")){//operand�� �����ϸ�.. 
				tmp=search_symtab(sic[i].operand);//symtabŽ�� 
				if(tmp != -1){
					operand=tmp;//symtab�������� operand�� �ּ����� 
				}
				else{
					ERROR("Undefined Symbol");
					return -2;
				}
			}
			else{
				operand=0x0; 
			}
			fprintf(fp, "%02x%04x",opcode,operand);c;
			line_len+=6;
			fp_len+=7;
		}
		else if(strcmp(sic[i].opcode, "BYTE")==0){
			tmp = byte_conversion(sic[i].operand,fp);c;
			if(sic[i].operand[0]=='X'){
				line_len+=tmp/2;
				fp_len+=(tmp+1);
			}
			else if(sic[i].operand[0]=='C'){
				line_len+=tmp*2;
				fp_len+=(tmp*2+1);
			}
		}
		else if(strcmp(sic[i].opcode, "WORD")==0){
			fprintf(fp,"%06x",todec(sic[i].operand));c;
			line_len+=6;
			fp_len+=7;
		}
		i++;
		if(line_len+6 > 60 || strcmp(sic[i].opcode,"END")==0){//���� ������ ���� objcode�� 69�� ������ ���ο�T����
			fseek(fp, -(fp_len), SEEK_END);
			fprintf(fp,"%02x",line_len/2);
			fseek(fp, 0, SEEK_END);
			if(strcmp(sic[i].opcode, "END")!=0){
				fp_len=3,line_len=0;//fp_len : --^ 3pointer start 
				fprintf(fp, "\nT");c;
				fprintf(fp, "%06x",sic[i].location);c;
				fprintf(fp, "--");c;
			}
		}
	}
	fprintf(fp,"\nE");c;
	fprintf(fp,"%06x\n",info[0].starting_address);
	fclose(fp);
}

