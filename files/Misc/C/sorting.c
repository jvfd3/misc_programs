	/*	INCLUS�O DAS BIBLIOTECAS	*/

#include<stdlib.h>
#include<stdio.h>

int main () {
	
	/*	CRIA��O DAS VARI�VEIS	*/
	
	int i,j,choice,aux,n, sort[100];
	
	/*	TAMANO DO VETOR		*/
	
	printf("quantos espa�os ter� o vetor?\n");
	scanf("%d",&n);
	
	
	
	/*	LENDO OS VALORES	*/
	
	printf("diga os %d valores naturais a serem ordenados:\n\n",n);
	n=n--;
	for (i=0;i<=n;i++){
		
		printf("valor %d:\t",i+1);
		scanf("%d", &sort[i]);
		if((sort[i])<0){
			printf("Eu disse numero natural! maior ou igual a 0! tente novamente\n\n");
			i--;
		};		
	};
	
	/*	BARREIRA	*/

	printf("~~~~~~~~~~~~~~~~\n");
	
	/*	IMPRIMINDO		*/
	
	for (i=0;i<=n;i++){
		printf("%d",sort[i]);	
	};
	
	printf("\n\n");
	/*	 COME�O DO SORTING		*/
	
	j=0;
	
	do{
	   printf("escolha a forma de organiza��o:\n\n ordem crescente (digite 1)\nordem decrescente (digite 2)\n\n");
	   scanf("%d",&choice);
	   
	   if ((choice<1)||(choice>2)){
		    printf("EU DISSE: 1 OU 2!!! PQ VC BOTOU DIFERENTE? TENTE NOVAMENTE:\n");
	   };
	   

	}while ((choice<1)||(choice>2));
	
	/*	ORDENA��O CRESCENTE	*/
	
	if (choice==1){
		for (i=0;i<=n;i++){
			for (j=0;j<=n;j++){
				if(sort[j]>sort[j+1]){
		  		    aux=sort[j];
					sort[j]=sort[j+1];
					sort[j+1]=aux;    
				}
			}
		}
		
	}
	else if (choice==2){
	
        for (i=0;i<=n;i++){
			for (j=0;j<=n;j++){
				if(sort[j]<sort[j+1]){
		  		    aux=sort[j];
					sort[j]=sort[j+1];
					sort[j+1]=aux;    
				}
			}
		}
	
	};
	
	
	
	
	/*	IMPRIMINDO O VETOR ORGANIZADO	*/
	
	for (i=1;i<=n;i++){
		printf("%d",sort[i]);	
	};
	
	/*	FIM DO PROGRAMA	*/
	
	return 0;
}
