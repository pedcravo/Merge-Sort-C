#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define n 6

void merge(int *v, int ini, int meio, int fim){
 	int *aux, p1, p2, tamanho, i, j, s;
	int fim1 = 0, fim2 = 0; 
  
  tamanho = fim - ini + 1;
  
  p1 = ini;
  p2 = meio + 1;
  
  aux = (int *) malloc(tamanho*sizeof(int));
  
  if(aux != NULL){
      for(i = 0; i < tamanho; i++){
          if(!fim1 && !fim2){
                if(v[p1]<v[p2]){
                    aux[i] = v[p1];
                    p1++;
                        
                } else {
                    aux[i] = v[p2++];
                }
                
                if(p1>meio){
                    fim1 = 1;
                }
                if(p2>fim){
                    fim2=1;
                } 
                
            } else{
                if(!fim1){
                    aux[i] = v[p1++];
                } else{
                    aux[i] = v[p2];
                    p2++;
                }
            }
        }
        
        for(j = 0, s = ini; j < tamanho; j++, s++){
            v[s] = aux[j];
        }
    }
    free(aux);
}

void mergeort(int *v, int ini, int fim){
  int meio;

  if(ini < fim){
      meio = floor((ini + fim)/2.0);
      printf("--Recursivo--\ninicio:%i \nMeio: %i \nFim: %i\n\n", ini, meio, fim);
      mergeort(v, ini, meio);
      mergeort(v, meio + 1, fim);
      merge(v, ini, meio, fim);
      
    } else if (ini != n && fim != n)  printf("--Quebra--\ninicio:%i \nMeio: %i \nFim: %i\nVetor: [ %i ]\n\n", ini, meio, fim, v[ini]);
}


int main(){
  int v[n] = {1, 2, 3, 4, 5, 6};
  
   mergeort(v, 0, n);
}

