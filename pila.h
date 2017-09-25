// HEADER de pila, definición

// Definición del objeto/struct

typedef struct pila pila;  // nos ahorramos tener que escribir struct dentro de la estructura cuando definimos los punteros a los metodos

struct pila {
  int size; // Tamaño de la pila
  int index; // indice para trabajarlo como arreglo + - 
  int * content; // puntero numérico al que le asignaremos un espacio de memoria dependiendo del tamaño que queramos utilizar
  
  // métodos: no se pueden poner funciones dentro de una estructura en c, pero se pueden colocar punteros que apunten a una dirección de memoria de una función.
  
  // Investigar que es una pila
  // En c no tenemos clases por lo tanto tenemos que siempre tener claro que debemos pasar la referencia al objeto/estructura que queremos manipular
  
  // Push: permite introducir un valor en la pila
  void (* push)(pila * this, int val);
  // Pop: permite obtener el ultimo valor
  int (* pop)(pila * this);
  
};


// Definición de los métodos:

void pila_push(pila * this, int val);

int pila_pop(pila * this);

// Constructor: es el new que hay en otros lenguajes, solo que aqui hay que crearlo manualmente.

pila * new_pila(int size);

