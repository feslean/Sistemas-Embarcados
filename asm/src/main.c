// Pr�tica 1 - Sistemas Embarcados
// Objetivo: Ordena��o de vetores e c�lculo da mediana

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <inttypes.h>


// Vari�veis globais - dimens�o e vetores de entrada e sa�da.
uint32_t dim;
uint8_t* vec_in;
uint8_t* vec_out;


// A fun��o median retorna a mediana do vetor.
extern unsigned char median(uint32_t dim, uint8_t *vec_in, uint8_t *vec_out);
// A fun��o aloc aloca os vetores de entrada e sa�da.
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

// Rotina de aloca��o de vetores
void aloc(uint32_t bags){
  dim = bags;
  
  vec_in = (uint8_t *) malloc(dim);
  vec_out = (uint8_t *) malloc(dim);
  
  int i;
  
  // Inser��o de valores iguais no vetor de entrada (Pior caso)
  
  for(i=0;i<dim;i++){
    vec_in[i] = 255;
  }
  
  
  // Inser��o de valores aleat�rios no vetor de entrada
  /*
  for(i=0;i<dim;i++){
    vec_in[i] = rand() % 255;
    printf("%d", vec_in[i]);
  }
  */
}