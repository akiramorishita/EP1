#ifndef Conjunto
#define Conjunto

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
typedef struct {
  int tam;
  int num[20];
} TipoConjunto;

TipoConjunto CriaVazio(); //cria conjunto vazio

TipoConjunto CriaRandom(int n); //Cria um conjunto com n numeros aleatorios

int Pertence(TipoConjunto c, int x); //Testa se x pertence ao conjunto, 0 se f, 1 se v

int Tamanho(TipoConjunto c); //retorna o numero de elementos do conjunto

int Insere(TipoConjunto *c, int x); //insere x no conjunto, retorna 1 se ok, 0 se já existe, ou elemento invalido. -1 se conjunto cheio

TipoConjunto Uniao(TipoConjunto c1, TipoConjunto c2); //retorna a uniao dos conjuntos c1 e c2, se o conjunto resultante tem mais de 20 elementos,
                                                      //retorna um conjunto vazio
TipoConjunto Intersecao(TipoConjunto c1, TipoConjunto c2); //retorna a intersecao dos conjuntos c1 e c2

void Imprime(TipoConjunto c); //imprime o conjunto c. ex.: {a,b,c,d}\n

#endif //fim Conjunto
