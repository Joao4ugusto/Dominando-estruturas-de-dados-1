#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _SNo{
  int val;
  struct _SNo *proximo;
} SNo;

typedef struct _Linked_List {
  SNo *primeiro;
} Linkedlist;

SNo *SNo_create(int val){
  SNo *sno = (SNo*) calloc(1, sizeof(SNo));
  sno->val = val;
  sno->proximo = NULL;
};

Linkedlist *Linkedlist_create(){
  Linkedlist *L = (Linkedlist*) calloc(1, sizeof(Linkedlist));
  L->primeiro = NULL;

  return L;
};

void Linkedlist_add_first(Linkedlist *L, int val){
  if(L->primeiro == NULL){
    SNo *p = SNo_create(val);
    L->primeiro = p;
  } else {
    SNo *p = SNo_create(val);
    p->proximo = L->primeiro;
    L->primeiro = p;
  }
}