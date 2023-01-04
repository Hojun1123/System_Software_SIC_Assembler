#include "sic.h"
int read(struct statement *sic){
	FILE *in;
    //long len;
    int i=0;
    in = fopen("./sic.txt", "r");
    if (in == NULL) {
        ERROR("CAN'T NOT FOUND FILE");
        return -1;
    }
    while (!feof(in)) {  
        fscanf(in,"%s %s %s %s\n", sic[i].no, sic[i].label, sic[i].opcode, sic[i].operand);
        i++;
    }
    fclose(in);
    return i;
}

void print_file(struct statement *sic, int n){
	int i;
	printf("\n______________________________________\n\n");
    for(i=0; i<n; i++){
    	printf("%2d.\t%s\t%s\t%s\t%s\t%#x\n", 
		i,sic[i].no, sic[i].label, sic[i].opcode, sic[i].operand, sic[i].location);
	}
}

int todec(char *str){
	//int로 변환 linux에서의  atoi함수 대체 
	int i = 0;
	int num = 0;
	while(str[i] != '\0'){		//Linux환경에서는 i+1 
		num = num*10;
		/*
		if(!('0'<=str[i] && str[i]<='9')){
			ERROR("NOT DEC");
			return -1;
		}*/
		num = num + (str[i]-0x30);
		i++;
	}
	return num;
}

int tohex(char *str){
	int i=0;
	int num=0;
	while(str[i] != '\0'){	//Linux환경에서는 i+1 
		num = num*16;
		//A~F
		if(str[i]== 'A'){
			num+=(str[i]-0x41);
			continue;
		}
		else if(str[i]== 'B'){
			num+=(str[i]-0x42);
			continue;
		}
		else if(str[i]== 'C'){
			num+=(str[i]-0x43);
			continue;
		}
		else if(str[i]== 'D'){
			num+=(str[i]-0x44);
			continue;
		}
		else if(str[i]== 'E'){
			num+=(str[i]-0x45);
			continue;
		}
		else if(str[i]== 'F'){
			num+=(str[i]-0x46);
			continue;
		}
		/*
		if(!('0'<=str[i] && str[i]<='9')){
			ERROR("NOT HEX");
			return -1;
		}*/
		num = num+(str[i]-0x30);
		i++;
	}
	return num;
}

int byte_conversion(char *operand, FILE *fp){
	char *re = malloc(sizeof(char)*4);//BYTE_SIZE <= 4
	memset(re, 0, sizeof(char)*4);//memset 
	int i=0;

	while(operand[i+2]!='\''){
		re[i]=operand[i+2];
		i++;
	}
	
	if(operand[0]=='X'){
		i=0;
		while(re[i]!=0){
			fprintf(fp, "%c",re[i]);
			i++;
		}
		return i;
	}
	
	else if(operand[0]=='C'){
		i=0;
		while(re[i]!=0){
			fprintf(fp,"%02x",re[i]);
			i++;
		}
		return i;
	}
	else{
		ERROR("You must use type(CorX)");
	}
	free(re);
}
