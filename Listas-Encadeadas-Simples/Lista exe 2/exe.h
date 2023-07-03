#include <stdio.h>
#include <stdlib.h>

typedef struct noLista {
   int elemento;
   struct noLista *proximo;
} lista, noLista;

int listavazia(lista *l) {
   return l == NULL;
}

int listacheia(lista *l) {
   return 0;  // Assumindo que a lista não tem limite de capacidade
}

int tamanholista(lista *l) {
   int tamanho = 0;
   noLista *noAtual = l;
   
   while (noAtual != NULL) {
      tamanho++;
      noAtual = noAtual->proximo;
   }
   
   return tamanho;
}

int iniciolista(lista *l) {
   if (!listavazia(l))
      return l->elemento;
   else {
      printf("A lista está vazia.\n");
      return -1;  // Valor de sentinela para indicar erro
   }
}

int fimlista(lista *l) {
   if (!listavazia(l)) {
      noLista *noAtual = l;
      
      while (noAtual->proximo != NULL)
         noAtual = noAtual->proximo;
      
      return noAtual->elemento;
   } else {
      printf("A lista está vazia.\n");
      return -1;  // Valor de sentinela para indicar erro
   }
}

int elementolista(lista *l, int no) {
   if (!listavazia(l)) {
      int contador = 0;
      noLista *noAtual = l;
      
      while (noAtual != NULL) {
         if (contador == no)
            return noAtual->elemento;
         
         contador++;
         noAtual = noAtual->proximo;
      }
      
      printf("O número do nó está fora do intervalo válido.\n");
      return -1;  // Valor de sentinela para indicar erro
   } else {
      printf("A lista está vazia.\n");
      return -1;  // Valor de sentinela para indicar erro
   }
}

int noelementolista(lista *l, int elemento) {
   if (!listavazia(l)) {
      int contador = 0;
      noLista *noAtual = l;
      
      while (noAtual != NULL) {
         if (noAtual->elemento == elemento)
            return contador;
         
         contador++;
         noAtual = noAtual->proximo;
      }
      
      printf("O elemento não foi encontrado na lista.\n");
      return -1;  // Valor de sentinela para indicar erro
   } else {
      printf("A lista está vazia.\n");
      return -1;  // Valor de sentinela para indicar erro
   }
}

int qtdelementolista(lista *l, int elemento) {
   int quantidade = 0;
   noLista *noAtual = l;
   
   while (noAtual != NULL) {
      if (noAtual->elemento == elemento)
         quantidade++;
      
      noAtual = noAtual->proximo;
   }
   
   return quantidade;
}

void inicializalista(lista *l) {
   *l = NULL;
}

void liberalista(lista *l) {
   noLista *noAtual = *l;
   
   while (noAtual != NULL) {
      noLista *noRemover = noAtual;
      noAtual = noAtual->proximo;
      free(noRemover);
   }
   
   *l = NULL;
}

void insereiniciolista(lista *l, int elemento) {
   noLista *novoNo = (noLista*) malloc(sizeof(noLista));
   novoNo->elemento = elemento;
   novoNo->proximo = *l;
   *l = novoNo;
}

void inserefimlista(lista *l, int elemento) {
   noLista *novoNo = (noLista*) malloc(sizeof(noLista));
   novoNo->elemento = elemento;
   novoNo->proximo = NULL;
   
   if (listavazia(l)) {
      *l = novoNo;
   } else {
      noLista *noAtual = *l;
      
      while (noAtual->proximo != NULL)
         noAtual = noAtual->proximo;
      
      noAtual->proximo = novoNo;
   }
}

void inserelista(lista *l, int elemento, int no) {
   if (no < 0) {
      printf("O número do nó deve ser maior ou igual a 0.\n");
      return;
   }
   
   if (no == 0) {
      insereiniciolista(l, elemento);
      return;
   }
   
   noLista *novoNo = (noLista*) malloc(sizeof(noLista));
   novoNo->elemento = elemento;
   
   noLista *noAtual = *l;
   int contador = 0;
   
   while (noAtual != NULL) {
      if (contador == no - 1) {
         novoNo->proximo = noAtual->proximo;
         noAtual->proximo = novoNo;
         return;
      }
      
      contador++;
      noAtual = noAtual->proximo;
   }
   
   printf("O número do nó está fora do intervalo válido.\n");
}

void removeiniciolista(lista *l) {
   if (!listavazia(l)) {
      noLista *noRemover = *l;
      *l = (*l)->proximo;
      free(noRemover);
   } else {
      printf("A lista está vazia.\n");
   }
}

void removefimlista(lista *l) {
   if (!listavazia(l)) {
      noLista *noAtual = *l;
      noLista *noAnterior = NULL;
      
      while (noAtual->proximo != NULL) {
         noAnterior = noAtual;
         noAtual = noAtual->proximo;
      }
      
      if (noAnterior != NULL)
         noAnterior->proximo = NULL;
      else
         *l = NULL;
      
      free(noAtual);
   } else {
      printf("A lista está vazia.\n");
   }
}

void removenolista(lista *l, int no) {
   if (!listavazia(l)) {
      if (no == 0) {
         removeiniciolista(l);
         return;
      }
      
      noLista *noAtual = *l;
      noLista *noAnterior = NULL;
      int contador = 0;
      
      while (noAtual != NULL) {
         if (contador == no) {
            if (noAnterior != NULL)
               noAnterior->proximo = noAtual->proximo;
            else
               *l = noAtual->proximo;
            
            free(noAtual);
            return;
         }
         
         contador++;
         noAnterior = noAtual;
         noAtual = noAtual->proximo;
      }
      
      printf("O número do nó está fora do intervalo válido.\n");
   } else {
      printf("A lista está vazia.\n");
   }
}

void removelista(lista *l, int elemento) {
   if (!listavazia(l)) {
      noLista *noAtual = *l;
      noLista *noAnterior = NULL;
      
      while (noAtual != NULL) {
         if (noAtual->elemento == elemento) {
            if (noAnterior != NULL)
               noAnterior->proximo = noAtual->proximo;
            else
               *l = noAtual->proximo;
            
            free(noAtual);
            return;
         }
         
         noAnterior = noAtual;
         noAtual = noAtual->proximo;
      }
      
      printf("O elemento não foi encontrado na lista.\n");
   } else {
      printf("A lista está vazia.\n");
   }
}

void invertelista(lista *l) {
   if (!listavazia(l)) {
      noLista *noAtual = *l;
      noLista *noAnterior = NULL;
      noLista *noProximo = NULL;
      
      while (noAtual != NULL) {
         noProximo = noAtual->proximo;
         noAtual->proximo = noAnterior;
         noAnterior = noAtual;
         noAtual = noProximo;
      }
      
      *l = noAnterior;
   } else {
      printf("A lista está vazia.\n");
   }
}

void exibeelementolista(lista *l, int elemento) {
   if (!listavazia(l)) {
      int contador = 0;
      noLista *noAtual = *l;
      
      while (noAtual != NULL) {
         if (noAtual->elemento == elemento)
            printf("O elemento %d está no nó %d.\n", elemento, contador);
         
         contador++;
         noAtual = noAtual->proximo;
      }
      
      printf("O elemento não foi encontrado na lista.\n");
   } else {
      printf("A lista está vazia.\n");
   }
}

void exibeestruturalista(lista *l) {
   if (!listavazia(l)) {
      noLista *noAtual = *l;
      
      while (noAtual != NULL) {
         printf("%d -> ", noAtual->elemento);
         noAtual = noAtual->proximo;
      }
      
      printf("NULL\n");
   } else {
      printf("A lista está vazia.\n");
   }
}

int main() {
   lista l;
   inicializalista(&l);

   insereiniciolista(&l, 10);
   insereiniciolista(&l, 20);
   insereiniciolista(&l, 30);
   inserefimlista(&l, 40);
   inserelista(&l, 50, 2);

   exibeestruturalista(&l);  // Saída esperada: 30 -> 20 -> 50 -> 10 -> 40 -> NULL

   removeiniciolista(&l);
   removefimlista(&l);
   removenolista(&l, 1);
   removenolista(&l, 2);
   removenolista(&l, 0);

   exibeestruturalista(&l);  // Saída esperada: A lista está vazia.

   insereiniciolista(&l, 60);
   insereiniciolista(&l, 70);
   inserefimlista(&l, 80);
   inserelista(&l, 90, 1);

   exibeestruturalista(&l);  // Saída esperada: 70 -> 90 -> 60 -> 80 -> NULL

   exibeelementolista(&l, 60);  // Saída esperada: O elemento 60 está no nó 2.
   exibeelementolista(&l, 100);  // Saída esperada: O elemento não foi encontrado na lista.

   printf("Tamanho da lista: %d\n", tamanholista(&l));  // Saída esperada: Tamanho da lista: 4

   invertelista(&l);

   exibeestruturalista(&l);  // Saída esperada: 80 -> 60 -> 90 -> 70 -> NULL

   liberalista(&l);

   return 0;
}
