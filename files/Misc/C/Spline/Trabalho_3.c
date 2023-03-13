#include <stdio.h>
#include <math.h>

float func(int questao, float x, float y){
	switch(questao){
		case 1:
			return 2 * x;								//se aproxima de: x²+1
		case 3:
			return y + x * x + 3;
		case 4:
			return 2 * (2 * sin(x)+cos(x))-5 * sin(x);	//se aproxima de: 2*sin(x)+cos(x)
		default:
			return 0;
	}
}

void euler(int questao, float h, float min, float max, float x[12], float y[12]){
	int i, n;

	n=(max-min)/h;
	printf("//////////////////\n\n");
	printf("Intervalo: [%.2f, %.2f]\t passo: h=%.2f\n\n", min, max, h);
	
//	printf("Poligono(");	//comando para geogebra
	
	for (i=1;i<=n;i++){
		x[i]=x[i-1]+h;
		y[i]=y[i-1]+h*(func(questao,x[i-1],y[i-1]));
//		printf("(%.6f,%.6f),",x[i-1],y[i-1]);	//comando para o geogebra
	

		switch(questao){
			case 1:
				if (i==1){
						printf("(X0, Y0)= (%.2f,  %.3f)\t= Y k  + h    * (2 * Xk )\n", x[0], y[0]);
				}
				printf("(X%d, Y%d)= (%.2f,  %.3f)\t= ", i, i, x[i], y[i]);
				printf("%.2f + %.2f * (2 * %.1f)\n",y[i-1],h,x[i-1]);
				break;
			case 3:
				if (i==1){
						printf("(X0, Y0)= (%.2f,  %.6f)\t= Y k   + h    * (x(t)   + t    * t    + 3)\n", x[0], y[0]);
				}
				printf("(X%d, Y%d)= (%.2f,  %.6f)\t= ", i, i, x[i], y[i]);
				printf("%.2f\t+ %.2f * (%.2f\t + %.2f * %.2f + 3)\n",y[i-1],h,y[i-1],x[i-1],x[i-1]);
				break;
			case 4:
				if (i==1){
						printf("(X0, Y0)= (%.1f,  %.6f)\t= Y k\t+ h     * (2 * (2 * sen(x   ) + cos(x   )) - 5 * sen(x   ))\n", x[0], y[0]);
				}
				printf("(X%d, Y%d)= (%.1f,  %.6f)\t= ", i, i, x[i], y[i]);
				printf("%.2f\t + %.2f * (2 * (2 * sen(%.2f) + cos(%.2f)) - 5 * cos(%.2f))\n",y[i-1],h,x[i-1],x[i-1],x[i-1]);
				break;
		}
		
	}
	
//	printf("(%.6f,%.6f))",x[i-1],y[i-1]);	//comando para o geogebra
	printf("\n");
}

void limite(int* min, int* max){
	printf("Digite o Limite Minimo:\t");
	scanf("%d", min);
	printf("Digite o Limite Maximo:\t");
	scanf("%d", max);
}

void passo(float* h){
	printf("Digite o passo:\t");
	scanf("%d", h);
}
 
void pvi(int questao, float x[11], float y[11]){
	printf("Equacao Y(x)=2x\n");
	printf("Digite a solucao inicial: Y(x):x=");
	scanf("%f", &x[0]);
	y[0]=func(questao,x[0],y[0]);
	printf("Solucao inicial: Y(%.3f)=%.3f\n", x[0], y[0]);
}

void formulas(int questao){
	printf("Formula do X:\t\t X k+1=X k + h\n");
	printf("Formula do Y:\t\t Y k+1=Y k + h * F(x,y)\n");
	switch(questao){
		case 1:
			printf("Formula do F(x,y)\t F(x,y)=2 * x\n");
			printf("Solucao inicial:\t Y(0)=1\n\n");
			break;
		case 3:
			printf("Formula do F(x,y)\t F(t,x)=x(t) + t * t + 3\n");
			printf("Solucao inicial:\t X(0)=-2\n\n");
			break;
		case 4:
			printf("Formula do F(x,y)\t F(t,x)=2 * (2 * sen(t) + cos(t))-5 * sen(t)\n");
			printf("Solucao inicial:\t X(0)=1\n\n");
			break;
			
	}
}

void questao_1(float h, float min, float max, float x[12], float y[12]){
	min=0.0;
	max=1.0;
	x[0]=0;
	y[0]=1;
	int questao=1;
	printf("QUESTAO %d V V V\n\n", questao);
//	limite(&minimo, &maximo);
//	passo(&h);
//	pvi(questao,x,y);
	formulas(questao);
	h=0.1;
	euler(questao,h,min,max,x,y);	
	h=0.2;
	euler(questao,h,min,max,x,y);
	h=0.25;
	euler(questao,h,min,max,x,y);
	
}

void questao_3(float h, float min, float max, float t[12], float x[12]){
	min=0.0;
	max=2.0;
	t[0] = 0;
	x[0] = -2;
	int questao=3;
	printf("QUESTAO %d V V V\n\n", questao);
//	limite(&minimo, &maximo);
//	passo(&h);
//	pvi(questao,x,y);
	formulas(questao);
	h=0.25;
	euler(questao,h,min,max,t,x);	
}

void questao_4(float h, float min, float max, float t[12], float x[12]){
	min=0.0;
	max=4.0;
	t[0] = 0;
	x[0] = 1;
	int questao=4;
	printf("QUESTAO %d V V V\n\n", questao);
//	limite(&minimo, &maximo);
//	passo(&h);
//	pvi(questao,x,y);

	formulas(questao);
	h=0.5;
	euler(questao,h,min,max,t,x);	
}

int main(){
	float min, max, h, x[11], y[11];
	questao_1(min,max,h,x,y);
	questao_3(min,max,h,x,y);
	questao_4(min,max,h,x,y);
}
