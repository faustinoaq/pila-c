#include <stdlib.h>
#include <stdio.h>
// #include "impl_pila.h"

//DECLARACION
typedef struct pila pila;

struct pila {
  int size;
  int index;
  int * content;
  void (* push)(pila * this, int val);
  int (* pop)(pila * this);
};

void pila_push(pila * this, int val);

int pila_pop(pila * this);

pila * new_pila(int size);


//UTILIZACIÓN
int main() {
  
  const long int n=1000000000;
  pila * p = new_pila(n);
  // long int * p;
  
  // p = calloc(n, sizeof(int));
  
  for (size_t i = 0; i < n; i++) {
    p->push(p, i);
    // p[i]=i;
  }
  
  // printf("El último elemento es %ld\n", p[n-1]);
  printf("El último elemento quitado %d\n", p->pop(p));
  
  return 0;
}


// IMPLEMENTACION
pila * new_pila(int size) {
  pila * p;
  p = malloc(sizeof(struct pila));
  p->content = calloc(size, sizeof(int));
  p->size = size;
  p->index = 0;
  p->push = pila_push;
  p->pop = pila_pop;
  return p;
}


void pila_push(pila * this, int val) {
  if (this->index < this->size) {
    this->content[this->index] = val;
    this->index++;
  } else {
    // int * aux, i;
    // aux = this->content;
    // this->content = calloc(this->size++, sizeof(int));
    // this->content=aux;
    // this->content[this->index] = val;
    // this->index++;
    printf("Overflow\n");
  }
}


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