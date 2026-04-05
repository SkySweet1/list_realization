#include <stdio.h>
#include "linkedlist.h"

void print_int(const void* data){                                                      //функция печати для int
    printf("%d ", *(int*)data);
}

int compare_int(const void* a, const void* b){                                         //функция сравнения для int
    return *(int*)a - *(int*)b;
}

int main(void)
{
    Link_List* list = create_List();
    
    printf("пуст ли %d\n", is_EMPT(list));
    
    int a = 10, b = 20, c = 30, d = 5, e = 15, f = 99;                                   //создаём переменные для хранения данных
    int search1 = 99, search2 = 100;
    int new_val = 99;                                                                   //для change_INDX
    
    push_BACK(list, &a);
    push_BACK(list, &b);
    push_BACK(list, &c);
    printf("после push_BACK 10, 20, 30 ");
    print_LIST(list, print_int);                                                        //передаём функцию печати
    
    push_FRONT(list, &d);
    printf("после push_FRONT 5 ");
    print_LIST(list, print_int);
    printf("размер -> %d\n", size_LIST(list));
    
    push_INDX(list, 2, &e);
    printf("после push_INDX(2, 15) ");
    print_LIST(list, print_int);
    
    printf("0 -> %d\n", *(int*)get_INDX(list, 0));                                         //теперь get_INDX возвращает void*, нужно привести к int* и разыменовать
    printf("2 -> %d\n", *(int*)get_INDX(list, 2));
    printf("4 -> %d\n", *(int*)get_INDX(list, 4));
    
    change_INDX(list, 2, &new_val);
    printf("после change_INDX(2, 99) ");
    print_LIST(list, print_int);
    
    printf("индекс 99 %d\n", find_INLIST(list, &search1, compare_int));                //find_INLIST теперь требует функцию сравнения
    printf("индекс 100 (нету) %d\n", find_INLIST(list, &search2, compare_int));
    
    int* val = (int*)pop_FRONT(list);                                                   //теперь pop_FRONT возвращает void*
    printf("удален из начала %d\n", *val);
    printf("после pop_FRONT ");
    print_LIST(list, print_int);
    
    val = (int*)pop_BACK(list);
    printf("удаляем из конца %d\n", *val);
    printf("после pop_BACK ");
    print_LIST(list, print_int);
    
    val = (int*)remove_INX(list, 1);
    printf("удаляем индекс 1 %d\n", *val);
    printf("после remove_INX(1) ");
    print_LIST(list, print_int);
    
    clean_LIST(list);
    printf("после clean_LIST ");
    print_LIST(list, print_int);
    printf("пуст ли %d\n", is_EMPT(list));
    printf("размер %d\n", size_LIST(list));
    
    destroy_LIST(list);
    printf("уничтожаем\n");
    
    return 0;
}