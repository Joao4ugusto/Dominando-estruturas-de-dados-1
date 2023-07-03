typedef struct{
   int elemento;
   struct noLista *proximo;
} lista, noLista;

int listavazia (lista *l);
int listacheia (lista *l);
int tamanholista (lista *l);

int iniciolista (lista *l);
int fimlista (lista *l);
int elementolista (lista *l, int no);
int noelementolista (lista *l, int elemento);
int qtdelementolista (lista *l, int elemento);

void inicializalista (lista *l);
void liberalista (lista *l);

void insereiniciolista (lista *l, int elemento);
void inserefimlista (lista *l, int elemento);
void inserelista (lista *l, int elemento, int no);

void removeiniciolista (lista *l);
void removefimlista (lista *l);
void removenolista (lista *l, int no);
void removelista (lista *l, int elemento);

void invertelista (lista *l);

void exibeelementolista (lista *l, int elemento);
void exibeestruturalista (lista *l);
