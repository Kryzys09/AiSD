#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node{
    struct node* next;
    int value;
} Node;

typedef struct{
    Node* first;
    int size;
} List;

void printList(List *list); // metoda drukująca listę
void addNode(List *list, Node *node); // metoda dodająca dany węzeł
void addValue(List *list, int value); // metoda dodająca nowy węzeł z daną wartością
Node* pop(List *list); // metoda usuwająca i zwracająca pierwszy element z listy
Node* top(List *list); // metoda zwracająca pierwszy element listy
Node* getNode(List *list, int value); // metoda zwracająca pierwszy element o danej wartości
void removeNode(List *list, Node *node); // metoda usuwająca dany element z listy
Node* getIndex(List *list, int index); // metoda zwracająca element o danym indeksie
Node* removeIndex(List *list, int index); // metoda usuwająca i zwracająca element o danym ineksie
List* megre(List *l1, List *l2); // funkcja łącząca dwie listy


int main(int argc, char** argv){
    List *l1 = malloc(sizeof(List));
    List *l2 = malloc(sizeof(List));
    int size = 1000;
    
    for(int i=0; i<size; i++){
        addValue(l1, i);
    }
    
    for(int i=size; i>0; i--){
        addNode(l2, removeIndex(l1, rand() % i));
    }
    clock_t start, end;
    
    printf("Time taken by getting first element: ");
    start = clock();
    for(int i=0; i<1000000; i++){
        getIndex(l2, 0);
    }
    end = clock();
    printf("%fs\n", (double) (end-start)/CLOCKS_PER_SEC);
    
    printf("Time taken by getting last element: ");
    start = clock();
    for(int i=0; i<1000000; i++){
        getIndex(l2, l2->size -1);
    }
    end = clock();
    printf("%fs\n", (double) (end-start)/CLOCKS_PER_SEC);
    
    printf("Time taken by getting middle element: ");
    start = clock();
    for(int i=0; i<1000000; i++){
        getIndex(l2, l2->size/2);
    }
    end = clock();
    printf("%fs\n", (double) (end-start)/CLOCKS_PER_SEC);
    
    printf("Time taken by getting to a radnom element: ");
    start = clock();
    for(int i=0; i<1000000; i++){
        getIndex(l2, rand()%(l2->size-1));
    }
    end = clock();
    printf("%fs\n", (double) (end-start)/CLOCKS_PER_SEC);
    
    return 0;
}

void addNode(List *list, Node *newNode){
    if(list->size == 0)
        list->first = newNode;
    else{
        Node *first = list->first;
        while(first->next != NULL){
            first = first->next;
        }
        first->next = newNode;
    }
    list->size++;
}

void addValue(List *list, int value){
    Node *newNode = malloc(sizeof(newNode));
    newNode->next = NULL;
    newNode->value = value;
    if(list->size == 0)
        list->first = newNode;
    else{
        Node *first = list->first;
        while(first->next != NULL){
            first = first->next;
        }
        first->next = newNode;
    }
    list->size++;
}

Node* pop(List *list){
    if(list->size == 0)
        return NULL;
    Node* node = list->first;
    list->first = node->next;
    node->next = NULL;
    list->size--;
    return node;
}

Node* top(List *list){
    return list->first;
}

Node* getNode(List *list, int value){
    Node* node = list->first;
    while(node != NULL && node->value != value){
        node = node->next;
    }
    return node;
}

void removeNode(List *list, Node *node){
    Node* search = list->first;
    while(search != NULL && search != node){
        search = search->next;
    }
    if(search == node)
        node->next = NULL;
        list->size--;
}

Node* getIndex(List *list, int index){
    Node* node = list->first;
    for(int i=0; i<index; i++){
        node = node->next;
    }
    return node;
}

Node* removeIndex(List *list, int index){
    if(index == 0)
        return pop(list);
    
    Node* node = list->first;
    for(int i=1; i<index; i++){
        node = node->next;
    }
    Node* temp = node->next;
    node->next = temp->next;
    temp->next = NULL;
    list->size--;
    return temp;
}

List* megre(List *l1, List *l2){
    if(l1->size == 0)
        return l2;
    Node* node = l1->first;
    while(node->next != NULL){
        node = node->next;
    }
    node->next = l2->first;
    l1->size += l2->size;
    return l1;
}

void printList(List *list){
    printf("Size: %d\n", list->size);
    Node *first = list->first;
    while(first != NULL){
        printf("%d -> ", first->value);
        first = first->next;
    }
    printf("NULL\n");
}
