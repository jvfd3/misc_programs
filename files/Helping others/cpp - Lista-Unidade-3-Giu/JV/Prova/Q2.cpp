#include <iostream>
using namespace std;

/*
Marque a opção que contém o correto uso da estrutura de repetição while para gerar múltiplas entradas de dados por parte do usuário do programa.

Opções de pergunta 2:
a) 
int num;
while (std::cout >> std::cin)

b) 
int num;
while (std::cout << num)

c) 
int num;
while (std::cin >> num)

d) 
int num;
while (std::cout >> num)

e) 
int num;
while (std::cin << num)
*/

int main_q2() {
  
  int num;
  while (std::cin >> num){
    cout << num;
  }
}