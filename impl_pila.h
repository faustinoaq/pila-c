#include <stdio.h>
#include "pila.h"

// Constructor

pila * new_pila(int size) {
  pila * p;
  
  p = malloc(sizeof(struct pila)); // asigna memoria limpia al puntero p
  
  // el content es un array de punteros de tamaño size donde cada uno tiene una cantidad de memoria, limpia la memoria, queda todo en ceros.
  p->content = calloc(size, sizeof(int));
  
  // Atributos de un object
  
  p->size = size;
  p->index = 0;
  
  p->push = pila_push;
  p->pop = pila_pop;
  
  return p;
}


// Push: permite introducir un valor en la pila
void pila_push(pila * this, int val) {
  
  if (this->index < this->size) {
    
    this->content[this->index] = val;
    this->index++;
    
  } else {
    
    int * aux, i;
    aux = this->content;
    // aux->index = this->index++;
    // aux->content = this->content;
    for(i=0; i < this->size; i++) {
      printf("aux[%d]: %d\n", i, aux[i]);
    }
    printf("\n");
    
    this->content = calloc(this->size++, sizeof(int));
    this->content=aux;
    this->content[this->index] = val;
    this->index++;
    
    // this->content = aux->content;
    // this->index++;
    
    // printf("Se modificó la pila\n");
    
    
  }
  
}


// Pop: permite obtener el ultimo valor
int pila_pop(pila * this) {
  int valor=0;
  if(this->index > 0) {
    
    this->index--;
    valor = this->content[this->index];
    this->content[this->index] = 0;
    
  } else {
    
    printf("La pila está vacía\n");
    
  }
  
  return valor;
}

