filho(fabio,jose).
filho(fabio, jose).
filho(ana, jose ).
filho(carlos, jose).
filho(fabio, maria).
filho(ana, maria).
filho(carlos, maria).

filho(marcos, fabio).
filho(fatima, fabio).
filho(marcos, sonia).
filho(fatima, sonia).

filho(adriano, ana).
filho(claudia, ana).
filho(adriano, eduardo).
filho(claudia, eduardo).

filho(mario, carlos).
filho(paula, carlos).
filho(mario, mariana).
filho(paula, mariana).


homem(José).
homem(Fábio).
homem(Eduardo).
homem(Carlos).
homem(Marcos).
homem(Adriano).
homem(Mário).

mulher(Maria).
mulher(Sônia).
mulher(Ana).
mulher(Mariana).
mulher(Fátima).
mulher(Claudia).
mulher(Paula).


pai(y,x):- filho(x,y),homem(y).
mae(y,x):- filho(x,y),mulher(y).
irmao(x,y):- filho(x,z),filho(y,z).
avô(y,x):- pai(z,x);mae(z,x),pai(y,z).
avó(y,x):- pai(z,x);mae(z,x),mae(y,z).
tio(y,x):- pai(z,x);mae(z,x),irmao(z,y),homem(y).
tia(y,x):- pai(z,x);mae(z,x),irmao(z,y),mulher(y).
