#include "conjunto.h"

TipoConjunto CriaVazio(){
  TipoConjunto Conj;  //declara conjunto
  Conj.tam = 0; //declara que seu tamanho é 0
  return Conj;
} //cria conjunto vazio


TipoConjunto CriaRandom(int n){
  srand(time(NULL)); //rand vai gerar numeros realmente aleatorios de acordo com o relogio do pc
  int a, b;
  TipoConjunto Conj;  //declara novo conjunto
  Conj = CriaVazio(); //como vazio
  Conj.tam = n; //e aumenta seu tamanho a cada valor adicionado
  
  for(a = 0; a < n; a++){
    b = rand() % 100; //preeche com valores randoms de 0 a 99   
    if(Pertence(Conj, b)){ //checa para nao repetir valores no conjunto
      a--;
    }
    else{
      Conj.num[a] = b;
    }
  }
  return Conj;
} //Cria um conjunto com n numeros aleatorios

int Pertence(TipoConjunto c, int x){
  int a;
  for(a = 0; a < c.tam; a++){ //percorre o vetor
    if (c.num[a] == x){ //checa se algum valor é igual
      return 1;
    }
  }
  return 0;
} //Testa se x pertence ao conjunto, 0 se f, 1 se v


int Tamanho(TipoConjunto c){
  return c.tam; //retorna o tamanho do vetor
} //retorna o numero de elementos do conjunto


int Insere(TipoConjunto *c, int x){
  int aux;
  aux = Pertence(*c, x);
  if(c->tam == 20){
    return -1;
  }
  else if (aux || x > 99 || x < 0){ //casos que a inserção não é possivel
    return 0;
  }
  else{
    c->num[c->tam] = x; //ultima casa do vetor será posto o valor de x
    c->tam++; //e o tamanho do vetor deve ser aumentado
    return 1;
  }
} //insere x no conjunto, retorna 1 se ok, 0 se já existe, ou elemento invalido. -1 se conjunto cheio


TipoConjunto Uniao(TipoConjunto c1, TipoConjunto c2){
  TipoConjunto uniao;
  uniao = CriaVazio(); //cria conjunto onde a uniao vai ser feita
  uniao.tam = c1.tam;
  int a;
  for(a = 0; a < c1.tam; a++){
    uniao.num[a] = c1.num[a]; //preenche c1 em uniao
  }
  for(a = 0; a < c2.tam; a++){
    if(!Pertence(c1, c2.num[a])){ //checa se os conjuntos tem itens repetidos antes de unir
      uniao.num[uniao.tam] = c2.num[a]; 
      uniao.tam++;
      if(uniao.tam > 20){ //checa se uniao vai alem do tamanho permitido
        return CriaVazio();
      }
    } 
  }
return uniao;
} //retorna a uniao dos conjuntos c1 e c2, se o conjunto resultante tem mais de 20 elementos,
  //retorna um conjunto vazio
            
                                      
TipoConjunto Intersecao(TipoConjunto c1, TipoConjunto c2){
  int a, b;
  TipoConjunto intersecao;
  intersecao = CriaVazio();
  for(a = 0; a < c1.tam; a++){
    for(b = 0; b < c2.tam; b++){
      if(c1.num[a] == c2.num[b]){ //percorre todos itens e checa se sao iguais
        intersecao.num[intersecao.tam] = c1.num[a];
        intersecao.tam++; //aumenta o valor do tamanho a cada item
      }
    }
  }
  return intersecao;
} //retorna a intersecao dos conjuntos c1 e c2


void Imprime(TipoConjunto c){
  int a;
  printf("{");
  for(a = 0; a < c.tam; a++){
    printf("%d", c.num[a]);
    if(a != (c.tam) - 1){
      printf(",");
    }
  }
  printf("}\n");
}
