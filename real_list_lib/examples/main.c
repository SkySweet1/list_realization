#include <stdio.h>
#include "linkedlist.h"

int main(void) {
    Link_List* list = create_List();
    
    printf("пуст ли? %d\n", is_EMPT(list));
    
    push_BACK(list, 10);
    push_BACK(list, 20);
    push_BACK(list, 30);
    printf("после push_BACK 10, 20, 30: ");
    print_LIST(list);
    
    push_FRONT(list, 5);
    printf("после push_FRONT 5 ");
    print_LIST(list);
    printf("размер -> %d\n", size_LIST(list));
    
    insert_INDX(list, 2, 15);
    printf("после insert_INDX(2, 15) ");
    print_LIST(list);
    
    printf("0: %d\n", get_INDX(list, 0));
    printf("2: %d\n", get_INDX(list, 2));
    printf("4: %d\n", get_INDX(list, 4));
    
    change_INDX(list, 2, 99);
    printf("gосле change_INDX(2, 99) ");
    print_LIST(list);
    
    printf("индекс 99 %d\n", find_INLIST(list, 99));
    printf("индекс 100 (нету) %d\n", find_INLIST(list, 100));
    
    int val = pop_FRONT(list);
    printf("удален из начала %d\n", val);
    printf("после pop_FRONT ");
    print_LIST(list);
    
    val = pop_BACK(list);
    printf("удаляем из конца %d\n", val);
    printf("после pop_BACK ");
    print_LIST(list);
    
    val = remove_INX(list, 1);
    printf("удаляем индекс 1 %d\n", val);
    printf("после remove_INX(1) ");
    print_LIST(list);
    
    clean_LIST(list);
    printf("после clean_LIST ");
    print_LIST(list);
    printf("пуст ли %d\n", is_EMPT(list));
    printf("размер %d\n", size_LIST(list));
    
    destroy_LIST(list);
    printf("уничтожаем\n");
    
    return 0;
}