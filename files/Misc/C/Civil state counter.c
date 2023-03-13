#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"");
char n[64];int fim=1,ec,s=0,c=0,v=0,d=0,sj=0;
while(fim==1){
printf(" Digite seu nome ou \"fim\"");scanf("%s" ,&n); system("cls");
	if(strcmp(n,"fim")!=0){
		printf("\n Informe seu estado civil ( do 1 ao 5):");
		scanf("%d",&ec);
		system("cls");
		switch(ec){
			case 1:s++; break;
			case 2:c++; break;
			case 3:v++; break;
			case 4:d++; break;
			case 5:sj++;break; }}
			
			else{fim=0;}
		}
		
		printf("Há %d de pessoas Solteiras\n Há %d de pessoas Casadas\n Há %d de pessoas viúvas\n Há %d de pessoas Divorciadas\n %d de pessoas separadas judicialmente", s,c,v,d,sj);

	return 0;
}
