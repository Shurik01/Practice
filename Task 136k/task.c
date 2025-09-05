#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Автор: Пархоменко Александра
Задание: Даны натуральное число n, действительные числа a1,..., an. Вычислить:
2(a1 + ... + an)^2*/

//Узел списка
struct Node {
    double data;  
    struct Node * next;
};

typedef struct Node Node;

/// @brief создает узел списка
/// @param data 
/// @return возрвращает список
Node* create_node(float data){
    Node * node = malloc(sizeof(struct Node));
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

Node* create_random_list(size_t n){
    if ( n == 0 ) return NULL;

    Node * first = create_node( (double)(rand() % 100) );
    n--;

    Node * last = first;

    while ( n != 0 ){
        Node *new_node = create_node( (double)(rand() % 100) );
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
    float sum = 0;
    Node* current = head;
    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }
    return sum;
}

void freeList(Node* head) {
    if (head == NULL)
        return;

    while (head != NULL) {
        Node* cur = head;
        head = head->next;
        free(cur);
    }
}

int main(){
    srand(time(NULL));  // Инициализация генератора случайных чисел
    int n;

    puts("Введите n");
    scanf("%d", &n);

    if (n <= 0) {
        printf("n должно быть натуральным числом!\n");
        return 1;
    }

    Node *head = create_random_list(n);

    puts("Изначальные значения:");
    output_list(head);

    // Вычисляем результат по формуле
    float sum = calculate_sum(head);
    float result = 2 * sum * sum;
    
    printf("Сумма элементов: %6.2f\n", sum);
    printf("Результат 2*(сумма)^2: %6.2f\n", result);

    freeList(head);

    return 0;
}