#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

typedef struct Link_List Link_List;

Link_List* create_List(void);
void destroy_LIST(Link_List* list);

void push_FRONT(Link_List* list, int data);
void push_BACK(Link_List* list, int data);

void insert_INDX(Link_List* list, int indx, int data);

int pop_FRONT(Link_List* list);
int pop_BACK(Link_List* list);
int remove_INX(Link_List* list, int indx);

int find_INLIST(const Link_List* list, int data);
int get_INDX( const Link_List* list, int indx);

void change_INDX(const Link_List* list, int indx, int data);
int size_LIST(const Link_List* list);
bool is_EMPT(const Link_List* list);

void clean_LIST(Link_List* list);
void print_LIST(Link_List* list);

#endif