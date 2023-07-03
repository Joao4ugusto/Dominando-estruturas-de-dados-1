int listavazia (lista *l){
  if(l->proximo == 0) {
    return 1;
  } 
  return 0;
}

int listacheia (lista *l){
  return 0;
}

int tamanholista (lista *l){;}

int iniciolista (lista *l){;}
int fimlista (lista *l){;}
int elementolista (lista *l, int no){;}
int noelementolista (lista *l, int elemento){;}
int qtdelementolista (lista *l, int elemento){;}

void inicializalista (lista *l){
  l->proximo = NULL;
}

void liberalista (lista *l){;}

void insereiniciolista (lista *l, int elemento){
   noLista *noAlocado = (noLista * ) malloc(sizeof(noLista));
   noAlocado->elemento = elemento;
   if(listavazia (l))
   noAlocado->proximo = NULL; // se estiver vazia;
   else
   noAlocado->proximo = l->proximo;
   l->proximo = noAlocado;
}

void inserefimlista (lista *l, int elemento){;}
void inserelista (lista *l, int elemento, int no){;}

void removeiniciolista (lista *l){;}
void removefimlista (lista *l){;}
void removenolista (lista *l, int no){;}
void removelista (lista *l, int elemento){;}

void invertelista (lista *l){;}

void exibeelementolista (lista *l, int elemento){;}

void exibeestruturalista (lista *l){
  // Segunda forma
  noLista *noAtual = l->proximo;
  printf("&LISTA: %x  &1No': %x\n", &l, l->proximo);
  if(!listavazia (l)){
    printf("\n&No Elemento &proximo\n");
    do {
      l = l->proximo;
      printf("%x  %d  %x\n", &(*l) ,l->elemento, l->proximo);
    } while (l->proximo != NULL);
  }
  // Primeira forma de fazer 
  // printf("&LISTA: %x  &1No': %x\n", &l, l->proximo);
  // if(!listavazia (l)){
  //   printf("\n&No Elemento &proximo\n");
  //   do {
  //     l = l->proximo;
  //     printf("%x  %d  %x\n", &(*l) ,l->elemento, l->proximo);
  //   } while (l->proximo != NULL);
  // }
}
