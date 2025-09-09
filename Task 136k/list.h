#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//для предотвращения многократного включения одного и того же заголовочного файла.
#ifndef LIST_H
#define LIST_H

/* Автор: Пархоменко А.В.
 * Модуль для работы с односвязным списком.
 */


//Узел списка
struct Node {
    double data;  
    struct Node * next;
};

typedef struct Node Node;

/// @brief создает узел списка
/// @param data 
/// @return возрвращает список
Node* create_node(double data);

/// @brief выводит значения хранящиеся в списке
/// @param first 
void output_list(Node * first);


/// @brief создает список из рандомных чисел
/// @param n количество элементов списка
/// @return возрвращает список
Node* create_random_list(size_t n);

/// @brief вычисляет сумму элементов списка
/// @param head 
/// @return сумму элементов
float calculate_sum(Node* head);


/// @brief удаляет все узлы
/// @param head 
void freeList(Node* head);

#endif