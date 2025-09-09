#include "list.h"
#include <stdio.h>
#include <stdlib.h>


/// @brief создает узел списка
/// @param data 
/// @return возрвращает узел списка
Node* create_node(double data){
    Node * node = malloc(sizeof(struct Node));
    
    node->data = data;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

/// @brief выводит значения хранящиеся в списке
/// @param first 
void output_list(Node * first){
    if (first == NULL) return;
    Node * cur = first;
    while ( cur != NULL ){
        printf("%6.2f ", cur->data);  
        cur = cur->next;
    }
    printf("\n");  
}

/// @brief добавляет элемент в конце списка
/// @param head узел списка
/// @param data действительное число
void add_to_list_end(Node* head, double data){
    Node* cur_node = head;
    Node* new_node = create_node(data);

    if (new_node == NULL || cur_node == NULL)
        return;
    
    // Находим хвост
    while (cur_node->next != NULL)
        cur_node = cur_node->next;

    // Связывание хвоста и нового узла
    cur_node->next = new_node;
    new_node->prev = cur_node;
}


/// @brief добавляет элемент в начало списка
/// @param head узел списка
/// @param data действителное число
/// @return список
Node* add_to_list_begin(Node* head, double data) {
    Node* new_node = create_node(data);

    if (new_node == NULL) {
        return head;
    }
    
    // Связываем новый узел со списком
    new_node->next = head;
    
    // Если список был не пустой, связываем старую голову с новым узлом
    if (head != NULL) {
        head->prev = new_node;
    }
    
    // Новый узел становится новой головой
    return new_node;
}


/// @brief создает список из рандомных действительных чисел в диапазоне от -100 до 100
/// @param n количество элементов списка
/// @return возрвращает список
Node* create_random_list(size_t n){
    if (n == 0) return NULL;

    /*RAND_MAX - это константа, определенная в стандартной библиотеке C 
        rand() возвращает число от 0 до RAND_MAX; 1.0 * rand() / RAND_MAX дает число от 0.0 до 1.0
        *200 расширяет диапазон до [0, 200]; - 100 сдвигает диапазон до [-100, 100]*/
    Node * new_node = create_node((double)rand() / RAND_MAX * 200.0 - 100.0);
    n--;

    while (n != 0){
        add_to_list_end(new_node, ((double)rand() / RAND_MAX * 200.0 - 100.0));
        n--; 
    }

    return new_node;
}


/// @brief сортирует список в порядке, в котором с начала идут отрицательные, потом положительные, при этом и те и
/// другие идут в обратном порядке
/// @param head узел списка
/// @return отсортированный список
Node* sort_list(Node * head){
    if (head == NULL) return NULL;
        
    Node* cur = head;
    Node* negative_list = NULL;    // Для отрицательных 
    Node* non_negative_list = NULL; // Для неотрицательных 

    // Разделяем элементы на два списка
    while (cur != NULL){
        if (cur->data < 0){
            // Отрицательные добавляем в начало, таким образом получается обратный порядок
            negative_list = add_to_list_begin(negative_list, cur->data);
        } else {
            // Неотрицательные добавляем в начало, таким образом получается обратный порядок 
            non_negative_list = add_to_list_begin(non_negative_list, cur->data);
        }
        cur = cur->next;
    }

    // Объединяем списки: сначала отрицательные, потом неотрицательные
    if (negative_list == NULL) {
        return non_negative_list;
    }
    
    if (non_negative_list == NULL) {
        return negative_list;
    }

    // Находим конец списка отрицательных чисел
    Node* last_negative = negative_list;
    while (last_negative->next != NULL) {
        last_negative = last_negative->next;
    }

    // Соединяем конец отрицательных с началом неотрицательных
    last_negative->next = non_negative_list;
    non_negative_list->prev = last_negative;

    return negative_list;
}


/// @brief функция для очистки списка
/// @param head  узел списка
void freelist(Node* head) {
    if (head == NULL)
        return;
    
    Node* cur_node = head;

    while (cur_node->next != NULL){
        cur_node = cur_node->next;
        free(cur_node->prev);
    }
    // Освобождение последнего элемента
    free(cur_node);
}