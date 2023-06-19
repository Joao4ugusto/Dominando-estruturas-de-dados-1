#ifndef LINKED_LIST_H
#define LINLED_LIST_H

typedef struct _SNo SNo;
typedef struct _Linked_list Linkedlist;

Linkedlist *Linkedlist_create();
SNo *SNo_create(int val);
void Linkedlist_add_first(Linkedlist *L, int val);

#endif