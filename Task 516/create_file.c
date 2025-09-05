#include <stdio.h> // стандартный ввод-вывод
#include "create_file.h"


/// @brief функция для создания обновленного инвентарного файла
/// @param f1 файл, в котором хранится сколько изделий каких видов продукции хранится на складе
/// @param f2 файл, содержащий сведения о том, на сколько уменьшилось или увеличилось количество изделий
/// по некоторым видам продукции
/// @param g обновленный инвентарный файл
void create_file(FILE *f1, FILE *f2, FILE *g){
    int id1, id2, count1, count2, count;
    while (fscanf(f1, "%d %d", &id1, &count1) == 2) {
        count = count1;
        
        // Сбрасываем указатель f2 в начало файла для каждого id1
        rewind(f2);
        
        while (fscanf(f2, "%d %d", &id2, &count2) == 2) {
            if (id1 == id2) {
                count += count2;
            }
        }
        
        fprintf(g, "%d %d\n", id1, count);
    }

}