# 1.1) Fazer uma função que retorne a raiz de um número
# tipo_de_retorno_da_funcao nome_da_funcao(tipo_da_variavel nome_da_variavel){}
#def nome_da_funcao(variaveis):
#  funcoes
import random


def quadrado(variavel):
  return variavel*variavel

def q1_1():
  print(quadrado(2))




# 1.2) Fazer um vetor de inteiros de tamanho 10, definido manualmente (criar ele já com valores pré definidos

def q1_2():
  #1.2.1.5) Automatizar o processo manual do vetor acima
  # me explica, vagabunda
  # a ideia é fazer uma função dentro do vetor, sem digitar um por vez
  # a função é y= N + 1 para cada elemento do vetor
  # for (int i = 0; i < tamanho_do_vetor; i++) {}
  # vetor2.append(i++)
  # print(vetor)
  # for (int i = 0; i < tamanho_do_vetor; i=i+1) {}
  n=1000
  vetor = 10*[n]
  for i in range (len(vetor)):
    insert = i+n
    print(insert)
    vetor.append(insert)

    
    # print(i+n)
    # print(' '+str(i)+' ', end='')
  # print()

  

# 1.2.1) Printar todos os elementos desse vetor
  print(vetor)
# 1.3) preencher ele com números aleatórios
  vetor2 = [i]
  vetor2 [i] = random.randint (0, 1000)
  for i in range (len(vetor)):
    print(vetor2)
# 1.4) criar uma struct ponto { int x; int y}
# 1.4.1) criar alguns pontos e os printar
# 1.4.2) criar um vetor de pontos
# 1.4.3) printar o vetor de pontos 

#QUESTÕES
  
def questoes():
  # q1_1()
  q1_2()

def inicio():
  questoes()

inicio()