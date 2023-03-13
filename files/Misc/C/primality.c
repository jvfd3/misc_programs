#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool testPrimality (int n){
    int i,count, remainder;
    for (i=1;i<=n;i++){
        remainder=n%i;
        if(remainder==0){count++;}
    }
    return ((count==2)?true:false);
}

int input(){
    int numberInput;
    scanf("%d", &numberInput);
    return numberInput;
}

void primality (){
    int number;
    do {
        printf("Input: ");
        number=input();
        if (!number) {break;};
		printf("\r Output: ");
        printf(testPrimality(number) ? "true\n" : "false\n");
    } while (number>=0);
    printf("End");
}


int main (){
    primality();
}
