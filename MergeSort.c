#include <stdio.h>
#include <math.h>
#define n 6

void mergesort(int *v, int ini, int fim){
  int meio;

  if(ini < fim){
      meio = floor((ini + fim)/2.0);
      printf("--Recursivo--\ninicio:%i \nMeio: %i \nFim: %i\n\n", ini, meio, fim);
      mergesort(v, ini, meio);
      mergesort(v, meio+1, fim);
      
   } else if (ini != n && fim != n)  printf("--Quebra--\ninicio:%i \nMeio: %i \nFim: %i\nVetor: [ %i ]\n\n", ini, meio, fim, v[ini]);
}

int main(){
  int v[n] = {1, 2, 3, 4, 5, 6};
  
   mergesort(v, 0, n);
}

