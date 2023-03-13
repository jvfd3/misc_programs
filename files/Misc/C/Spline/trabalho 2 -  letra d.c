def integra(coef):
  #integra:
  for i in range(15):
    coef[i]=coef[i]/(4-(i%4));
  '''
    0=0/(4-(0)%4) 0=0/4 
    1=1/(4-(1)%4) 0=0/3 
    2=2/(4-(2)%4) 0=0/2 
    3=3/(4-(3)%4) 0=0/1 
    4=4/(4-(4)%4) 0=0/4 
    5=5/(4-(5)%4) 0=0/3 
    5=5/(4-(5)%4) 0=0/3
  '''
  #fim integração

# integral 1= [0.5-0] coef [0,3]
def int1(x, c):
  return c[0]*x**4+c[1]*x**3+c[2]*x**2+c[3]*x**1

# integral 2= [1-0.5] coef [4,7]
def int2(x, c):
  return c[4]*x**4+c[5]*x**3+c[6]*x**2+c[7]*x**1

# integral 3= [1.5-1] coef [8,11]
def int3(x, c):
  return c[8]*x**4+c[9]*x**3+c[10]*x**2+c[11]*x**1

# integral 4= [2-1.5] coef [12,16]
def int4(x, c):
  return c[12]*x**4+c[13]*x**3+c[14]*x**2+c[15]*x**1

def somaints(c):
  return ((int1(0.5,c)-int1(0.0,c))+(int2(1.0,c)-int2(0.5,c))+(int3(1.5,c)-int3(1.0,c))+(int4(2.0,c)-int4(1.5,c)))

def letra_d(x,cf,cg):
  sf= Simpson(x,cf)       #Simpson usando f(x)
  integra(cf)             #Integrando coeficientes f(x)
  sif= somaints(cf)       #Soma Integrais usando f(x)
  diff= sf-sif            #Diferença entre sf e sif
  erro1f= diff/sf         #Erro usando o Simpson como real
  erro2f= diff/sif        #Erro usando a integral definida como real

  sg= Simpson(x,cg)       #Simpson usando f(x)
  integra(cg)             #Integrando coeficientes f(x)
  sig= somaints(cg)       #Soma Integrais usando f(x)
  difg= sg-sig            #Diferença entre sf e sif
  erro1g= difg/sg         #Erro usando o Simpson como real
  erro2g= difg/sig        #Erro usando a integral definida como real

  print("Simpson f(x):\t\t\t",sf)
  print("Integral definida f(x):\t\t", sif)
  print("Diferença entre os métodos:\t", diff)
  #print("O Erro é de:\t", erro1f," ou\t", erro2f)
  print()

  print("Simpson g(x):\t\t\t", sg)
  print("Integral definida g(x):\t\t", sig)
  print("Diferença entre os métodos:\t", difg)
  #print("O Erro é de:\t", erro1g," ou\t", erro2g)
  print()

  #TODO 1: Criar uma matriz separada com os coeficientes integrados para poder executar o bloco mais vezes
  #TODO 2: Integrar de uma forma mais bonita
  
letra_d(Xs,coeficientes_f, coeficientes_g)