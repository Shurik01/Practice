#include <stdio.h>
void find_sqr(int n){
    for (unsigned i = 5; i < n+1; ++i){
        if (i % 4 == 1 && i != 1){
            printf("%u\n", i);
        }
    }
}