// Prática 1 - Sistemas Embarcados
// Objetivo: Ordenação de vetores e cálculo da mediana

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>


// Variáveis globais - dimensão e vetores de entrada e saída.
uint32_t dim;
uint8_t* vec_in;
uint8_t* vec_out;


// A função median retorna a mediana do vetor.
extern unsigned char median(uint32_t dim, uint8_t *vec_in, uint8_t *vec_out);
// A função aloc aloca os vetores de entrada e saída.
void aloc(uint32_t bags);

// Rotina principal
int main(){
  srand(time(NULL));
  
  uint32_t bags = 1024;
  aloc(bags);
  median(dim,vec_in,vec_out);
  bags = 1023;
  aloc(bags);
  median(dim,vec_in,vec_out);
  bags = 512;
  aloc(bags);
  median(dim,vec_in,vec_out);
  bags = 511;
  aloc(bags);
  median(dim,vec_in,vec_out);
  bags = 2;
  aloc(bags);
  median(dim,vec_in,vec_out);
  bags = 1;
  aloc(bags);
  median(dim,vec_in,vec_out);
  
  return 0;
}

// Rotina de alocação de vetores
void aloc(uint32_t bags){
  dim = bags;
  
  vec_in = (uint8_t *) malloc(dim);
  vec_out = (uint8_t *) malloc(dim);
  
  int i;
  
  // Inserção de valores iguais no vetor de entrada (Pior caso)
  
  for(i=0;i<dim;i++){
    vec_in[i] = 255;
  }
  
  
  // Inserção de valores aleatórios no vetor de entrada
  /*
  for(i=0;i<dim;i++){
    vec_in[i] = rand() % 255;
    printf("%d", vec_in[i]);
  }
  */
}