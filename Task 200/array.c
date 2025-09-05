#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <windows.h>
#include <time.h> 

/* Автор: Пархоменко А.В.
 * Задача: Даны целые числа a, n, x1,...,xn(n > 0). 
 Определить, каким по счету идёт в последовательности x1,...,xn член, равный a. 
 Если такого члена нет, то ответом должно быть число 0.
 */

/* @brief возращает номер того, каким по счету 
в последовательности x1, ..., xn идет член, равный a
если такого нет, возращает 0
@param arr: динамический массив целых чисел
@param size: размер массива
@param a: число для поиска 
@return номер числа в массиве*/
int arr_find(int *arr, unsigned size, int a){
  //цикл, i принимает значения от 0 до size - 1
  for (unsigned i = 0; i < size; ++i){
    if (arr[i] == a) {
      return ++i;
    } 
  }
  return 0;
}

/* @brief функция для вывода массива 
@param arr: динамический массив целых чисел
*/
void arr_output(int *arr, unsigned size){
     for (unsigned i = 0; i < size; ++i) {
        printf( "%d  ",arr[i]);
     }
}
/* @brief функция для заполнения массива случайными целыми числами от -100 до 100
@param arr: динамический массив целых чисел
@param size: размер массива*/
void arr_rand(int *arr, unsigned size){
  for (unsigned i = 0; i < size; ++i) {
    arr[i] = rand() % 200 - 100;
  }
}



int main() {

    srand(time(NULL));

setlocale(LC_ALL, ".UTF-8");
SetConsoleCP(CP_UTF8);              // задать кодировку для ввода
SetConsoleOutputCP(CP_UTF8);        // задать кодировку для ввода

int *arr; // указатель на массив
unsigned n; //количество элементов в массиве
int a; //число, которое ищем в массиве

printf( "Даны целые числа a, n, x1,...,xn(n > 0).\nОпределить, каким по счету идёт в последовательности x1,...,xn член, равный a. \nЕсли такого члена нет, то ответом должно быть число 0.");

printf( "Введите размер массива: \n" );

scanf( "%u", &n );

// выделение памяти под динамический массив: n * sizeof (int) байт
arr = malloc( n * sizeof(int) );

printf( "Массив, состоящий из n элементов:\n" );

arr_rand( arr, n );

arr_output( arr, n );

printf( "\n" );

printf( "Введите a (число, номер которого хотите найти)\n" );

scanf( "%d", &a );

// номер числа в массиве
int num = arr_find( arr, n, a );

if ( num > 0 ) {
printf( "Член в последовательности x1, ..., xn, равный a, идет под номером: %d", num );
}

else {
  printf( "Такого члена нет в последовательности" );
}

//очищаем память
free( arr );
return 0;

}