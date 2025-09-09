#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

/*Автор: Пархоменко Александра
Задание: Даны натуральное число n, действительные числа a1,..., an. Вычислить:
2(a1 + ... + an)^2*/



int main(){
    srand(time(NULL));  // Инициализация генератора случайных чисел
    unsigned n;

    puts("Введите n");
    scanf("%u", &n);


    Node *head = create_random_list(n);

    puts("Изначальные значения:");
    output_list(head);

    // Вычисляем результат по формуле
    double sum = calculate_sum(head);
    double result = 2 * sum * sum;
    
    printf("Результат 2*(a1 + ... + an): %6.2f\n", result);

    freeList(head);

    return 0;
}