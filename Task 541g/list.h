#include <stdio.h>
#include <stdlib.h>

/* Автор: Пархоменко А.В.
 * Модуль для работы с двусвязным списком.
 */


//Узел списка
struct Node {
    double data; 
    struct Node *next;
    struct Node *prev;
};

typedef struct Node Node;

/// @brief создает узел списка
/// @param data 
/// @return возрвращает узел списка
Node* create_node(double data);


/// @brief выводит значения хранящиеся в списке
/// @param first 
void output_list(Node * first);


/// @brief добавляет элемент в конце списка
/// @param head узел списка
/// @param data действительное число
void add_to_list_end(Node* head, double data);


/// @brief добавляет элемент в начало списка
/// @param head узел списка
/// @param data действителное число
/// @return список
Node* add_to_list_begin(Node* head, double data);


/// @brief создает список из рандомных действительных чисел в диапазоне от -100 до 100
/// @param n количество элементов списка
/// @return возрвращает список
Node* create_random_list(size_t n);

/// @brief сортирует список в порядке, в котором с начала идут отрицательные, потом положительные, при этом и те и
/// другие идут в обратном порядке
/// @param head узел списка
/// @return отсортированный список
Node* sort_list(Node * head);


/// @brief функция для очистки списка
/// @param head  узел списка
void freelist(Node* head);