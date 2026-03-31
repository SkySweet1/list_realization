#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// 0.1  элемент списка                   typedef struct Node
// 0.2  сам список                       typedef struct Link_List
// 0.3  создать элемент                  Node* create_Node            
// 0.4  создать сам список               Link_List* create_List    
// 1    добавить в начало                push_FRONT 
// 2    добавить в конец                 push_BACK
// 3    вставить по индексу              insert_INDX
// 4    удалить из начала                pop_FRONT
// 5    удалить из конца                 pop_BACK
// 6    удалить по индексу               remove_INX
// 7    понять какой элемент по счету    find_INLIST
// 8    получить элемент по индексу      get_INDX
// 9    изменить элемент по индексу      change_INDX
// 10   узнать размер списка             size_LIST
// 11   пуст ли список                   is_EMPT
// 12   очистить список                  clean_LIST
// 13   показать список                  print_LIST
// 14   удалить список                   destroy_LIST


/* 0.1
    здесь будет описывать сам элемент списка

    int data;           это сами данные которые можно заменять
    struct Node* next   это указатель на сделующий элемент

*/ 
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* 0.2
    ну а уже здесь мы описываем сам список (то что он будет содержать)
    Node* head;         это первый элемент (хедер, поэтому head)
    int size;           это размер списка

*/
typedef struct Link_List {
    Node* head;
    int size;
} Link_List;

/* 0.3
    здесь мы создаем элемент
    выделяем под него память

    newNode->data = data;           кладем данные в элемент
    newNode->next = NULL;           делаем след элемент пустым -> конец списка
*/
Node* create_Node(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    if(newNode == NULL){
        perror("newNode memory invalid\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

/* 0.4
    создаем сам список получаеться

    все NULL потому что мы создаем без каких либо эл внутри (создаем пустой список)
*/
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

/* 1
    надо добавить в начало:

    создаем новый элемент
    newNode->next = list->head;             новый эл указывает на старый передний эл
    list->head = newNode;                   ну а теперь передний эл указывает на новый эл

    так же увеличиваем размер
*/
void push_FRONT(Link_List* list, int data){
    Node* newNode = create_Node(data);

    newNode->next = list->head;

    list->head = newNode;

    list->size++;
}

/* 2
    добавляем в конец

    создаем новый эл

    if(list->head == NULL){list->head = newNode;}       
    если список пуст то новый эл становиться первым

    else {Node* curr = list->head;while(curr->next != NULL)
    {curr = curr->next;}curr->next = newNode;}
    если нет то создаем эл который начинается с первого эл (головы) и идем до посл эл

    ну и когда дошли то заменяем этот элемент

    так же увеличиваем размер
*/
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

/* 3
    тут мы будем вставлять элемент по индексу в список

    рассмотрим возможные случаи
    (indx < 0 || indx > list->size)         это проверка индексе (нормальный ли он вообще)
    (indx == 0)                             если 0 то (в полне логично) вставляем эл в начало

    создаем новый элемент

    for(int i = 0; i < indx - 1; i++){curr = curr->next;}
    находим узел перед которым будем вставлять

    newNode->next = curr->next;             новый->следующий
    curr->next = newNode;                   предыдущий->новый
    ну тупо вставили в список между двумя другими эл в списке

    увеличиваем размер (т к вставили еще один элемент)

*/
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

/* 4
    здесь мы будем удалять элемент путем замены элемента на новый (ну а так же очистим его)
    в данном случае будем удалять с начала

    (list->head == NULL)                проверяем на пустоту

    Node* tm = list->head;              создаем указатель на первый элемент,
    int data = tm->data;                и даем ему значение первого элемента

    list->head = list->head->next;      заменяем его

    очищаем
    и уменьшаем размер (т к задача была удаляли элемент)
*/
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

/* 5
    удаляем из конца

    (list->head == NULL)                если лист пустой то ошибка

    (list->head->next == NULL)          если след элемент пустой то удаляем первый и единственный элемент

    ну а если все норм то создаем указатель на хедер и идем до нужного элемента

    создаем переменную на которую мы будем заменять элемент, так же передаем ему значение
    заменяем и очищаем
*/
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

/* 4
    надо удалить элемент по указаному индексу

    проверяем индекс
    если индекс 0, то просто удаляем первый
    
    далее, создаем указатель на хедер (первый элемент)

    циклом идем до нужного элемента (по индексу)

    создаем переменную на которую мы будем заменять элемент, так же передаем ему значение
    заменяем и очищаем
*/
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

/* 7
    надо понять какой элемент по счету

    Node* curr = list->head;            указатель на хедер

    создаем переменную индекса (то что нам потом надо будет узнать)

    с помощью while идем до нужного элемента, паралельно увеличивая индекс

    ну и когда мы дошли до него то возвращаеться индекс (т к условие)

    а если ненашли то exit(1)
*/
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

/* 8 
    надо вернуть значение элемента по указаному индексу

    (indx < 0 || indx >= list->size)                            проверка индекса
    Node* curr = list->head;                                    указатель на хедер (1-ый элемент)

    циклом идем до нужного элемента и возвращаем значение       return curr->data;
*/
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

/* 9
    заменяем элемент по индексу

    (indx < 0 || indx >= list->size)            проверяем сам индекс 

    создадим переменную которая будет указывать на 1 эл списка
    с помощью цикла идем к необходимому элементу

    curr->data = data;                          ну и заменяем его
*/
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

/* 10
    просто вывозвращаем размер т к требуеся просто размер листа 
*/
int size_LIST(const Link_List* list){
    return list->size;
}

// 11
bool is_EMPT(const Link_List* list){
    return list->head == NULL;
}

/* 12
    надо очистить
    через цикл (пока 1 элемент не исчезнет),
    каждый раз создаем элемент и заменяем одно на другое
    то что мы заменили очищаем)

*/
void clean_LIST(Link_List* list){
    while(list->head != NULL){
        Node* tm = list->head;
        list->head = list->head->next;
        free(tm);
    }

    list->size = 0;
}

/* 13
    выводим вест лист через цикл и добавляем \n

*/
void print_LIST(const Link_List* list){
    Node* curr = list->head;

    while(curr != NULL){
        printf("%d ", curr->data);

        curr = curr->next;
    }

    printf("\n");
}

/* 14
    просто очищаем весь лист и очищаем память которую он занимал

*/
void destroy_LIST(Link_List* list){
    clean_LIST(list);
    free(list);
}