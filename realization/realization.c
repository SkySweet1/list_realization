#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Link_List {
    Node* head;
    int size;
} Link_List; 

Node* create_Node(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        perror("newNode memory invalid\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

Link_List* create_List(void){
    Link_List* list = (Link_List*)malloc(sizeof(Link_List));

    if(list == NULL){
        perror("list memory invalid\n");
        exit(EXIT_FAILURE);
    }

    list->head = NULL;
    list->size = 0;

    return list;
}

void push_FRONT(Link_List* list, int data){
    Node* newNode = create_Node(data);

    newNode->next = list->head;

    list->head = newNode;

    list->size++;
}

void push_BACK(Link_List* list, int data){
    Node* newNode = create_Node(data);

    if(list->head == NULL){
        list->head = newNode;

    } else {
        Node* curr = list->head;

        while(curr->next != NULL){
            curr = curr->next;

        }

        curr->next = newNode;
    }

    list->size++;
}

void insert_INDX(Link_List* list, int indx, int data){
    if(indx < 0 || indx > list->size){
        perror("index outsize diap\n");
        exit(EXIT_FAILURE);
    }

    if(indx == 0){
        push_FRONT(list, data);
        return;
    }

    Node* newNode = create_Node(data);
    Node* curr = list->head;

    for(int i = 0; i < indx - 1; i++){
        curr = curr->next;
    }

    newNode->next = curr->next;

    curr->next = newNode;

    list->size++;
}

int pop_FRONT(Link_List* list){
    if(list->head == NULL){
        perror("empty list\n");
        exit(EXIT_FAILURE);
    }

    Node* tm = list->head;
    int data = tm->data;

    list->head = list->head->next;

    free(tm);

    list->size--;

    return data;
}

int pop_BACK(Link_List* list){
    if(list->head == NULL){
        perror("empty list\n");
        exit(EXIT_FAILURE);
    }

    if(list->head->next == NULL){
        return pop_FRONT(list);
    }

    Node* curr = list->head;

    while(curr->next->next != NULL){
        curr = curr->next;
    }

    Node* tm = curr->next;
    int data = tm->data;

    curr->next = NULL;

    free(tm);

    list->size--;

    return data;
}

int remove_INX(Link_List* list, int indx){
    if(indx < 0 || indx >= list->size){
        perror("index outsize diap\n");
        exit(EXIT_FAILURE);
    }

    if(indx == 0){
        return pop_FRONT(list);
    }

    Node* curr = list->head;

    for(int i = 0; i < indx - 1; i++){
        curr = curr->next;

    }

    Node* tm = curr->next;
    int data = tm->data;

    curr->next = tm->next;

    free(tm);

    list->size--;

    return data;
}

int find_INLIST(const Link_List* list, int data){
    Node* curr = list->head;

    int indx = 0;

    while(curr != NULL){
        if(curr->data == data){
            return indx;
        }

        curr = curr->next;
        indx++;
    }

    return -1;
}

int get_INDX(const Link_List* list, int indx){
    if(indx < 0 || indx >= list->size){
        perror("outsize diap\n");
        exit(EXIT_FAILURE);
    }

    Node* curr = list->head;

    for(int i = 0; i < indx; i++){
        curr = curr->next;
    }

    return curr->data;
}

void change_INDX(Link_List* list, int indx, int data){
    if(indx < 0 || indx >= list->size){
        perror("outsize diap\n");
        exit(EXIT_FAILURE);
    }

    Node* curr = list->head;

    for(int i = 0; i < indx; i++){
        curr = curr->next;
    }

    curr->data = data;
}

int size_LIST(const Link_List* list){
    return list->size;
}

bool is_EMPT(const Link_List* list){
    return list->head == NULL;
}

void clean_LIST(Link_List* list){
    while(list->head != NULL){
        Node* tm = list->head;
        list->head = list->head->next;
        free(tm);
    }

    list->size = 0;
}

void print_LIST(const Link_List* list){
    Node* curr = list->head;

    while(curr != NULL){
        printf("%d ", curr->data);

        curr = curr->next;
    }

    printf("\n");
}

void destroy_LIST(Link_List* list){
    clean_LIST(list);
    free(list);
}