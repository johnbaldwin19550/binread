#include <stdio.h>

char translate(int digit);
int main(int argc, char *args[]){
	int rowsize=8;
	int colsize=256;
	FILE *inf;
	if(argc>4||argc<2){
		printf("Usage: binread [filename] -[rowsize] -[colsize]\n");
		return 1;
	}
	if(argc>2){
		int i=1;
		int numoptions=0;
		while(i<argc){
			if(args[i][0]=='-'){
				if(numoptions==0){
					rowsize=-atoi(args[i]);
				}else if(numoptions=1){
					colsize=-atoi(args[i], "r");
				}
				numoptions++;
			}else{
				inf=fopen(args[i], "r");
			}
			i++;
		}
	}else if(argc==2){
		inf=fopen(args[1], "r");
	}
	char x;
	int count=0;
	if(inf==NULL){
		printf("Unable to open file.\n");
		return 1;
	}else{
		while((x=fgetc(inf))!=EOF){
			count++;
			unsigned int code=x-0;
			int digit1=code/128;
			code-=digit1*128;
			int digit2=code/64;
			code-=digit2*64;
			int digit3=code/32;
			code-=digit3*32;
			int digit4=code/16;
			code-=digit4*16;
			int digit5=code/8;
			code-=digit5*8;
			int digit6=code/4;
			code-=digit6*4;
			int digit7=code/2;
			code-=digit7*2;
			int digit8=code;
			printf("%c%c%c%c%c%c%c%c ",translate(digit1),translate(digit2),translate(digit3),translate(digit4),translate(digit5),translate(digit6),translate(digit7),translate(digit8));
			//printf("%2x ", code);
			if(count%rowsize==0){
				printf("\n");
			}
			if(count%colsize==0){
				printf("\n");
			}
		}
	}
	printf("\n");
	return 0;
}
char translate(int digit){
	char result='#';
	if(digit==0){
		result='-';
	}
	return result;
}

