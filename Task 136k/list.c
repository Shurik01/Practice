#include "list.h"

/// @brief создает узел списка
/// @param data 
/// @return возрвращает список
Node* create_node(double data){
    struct Node* node = malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;

    return node;
}


/// @brief выводит значения хранящиеся в списке
/// @param first 
void output_list(Node * first){
    if (first == NULL) return;
    Node * cur = first;
    while ( cur != NULL ){
        printf("%4.2f ", cur->data);  // Форматированный вывод для double
        cur = cur->next;
    }
    printf("\n");  
}


/// @brief создает список из рандомных чисел
/// @param n количество элементов списка
/// @return возрвращает список
Node* create_random_list(size_t n){
    if ( n == 0 ) return NULL;

    Node * first = create_node( (double)rand() / RAND_MAX * 200.0f - 100.0f );
    n--;

    Node * last = first;

    while ( n != 0 ){
        /*RAND_MAX - это константа, определенная в стандартной библиотеке C 
        rand() возвращает число от 0 до RAND_MAX; 1.0 * rand() / RAND_MAX дает число от 0.0 до 1.0
        *200 расширяет диапазон до [0, 200]; - 100 сдвигает диапазон до [-100, 100]*/
        Node *new_node = create_node( (double)rand() / RAND_MAX * 200.0f - 100.0f );
        last->next = new_node;
        last = new_node;
        n--; 
    }
    return first;
}


/// @brief вычисляет сумму элементов списка
/// @param head 
/// @return сумму элементов
float calculate_sum(Node* head) {
    double sum = 0;
    Node* current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

/// @brief удаляет все узлы
/// @param head 
void freeList(Node* head) {
    if (head == NULL)
        return;

    while (head != NULL) {
        Node* cur = head;
        head = head->next;
        free(cur);
    }
}
