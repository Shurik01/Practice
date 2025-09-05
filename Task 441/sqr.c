#include "sqr.h"
#include <stdio.h>

/**
 * @brief: среди чисел 1, ..., n находит те, которые можно представить в виде суммы квадратов двух натуральных чисел
 * @param n: верхняя граница
 * @details i = j^2 + x^2, x^2 = i - j^2  
 */
void find_sqr(int n) {
    for (unsigned i = 1; i <= n; i++) {
        int flag = 0;
        // !flag продолжает цикл, если не нашлось чисел в виде которых можно представить сумму, выходит в ином случае
        for (unsigned j = 1; j * j <= i && !flag; j++) { 
            for (unsigned k = 1; k * k <= i && !flag; k++) { 
                if (j * j + k * k == i) {
                    flag = 1;
                }
            }
        }
        if (flag) {
            printf("%u\n", i);
        }
    }
}