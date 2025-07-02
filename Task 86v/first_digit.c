#include <stdio.h>
#include <locale.h>
#include <windows.h>
/* Автор: Пархоменко А.В.
 * Задача: Дано натуральное число n. Найти первую цифру числа n.
 */
int main() {
int n; // натуральное число n
setlocale(LC_ALL, ".UTF-8");
SetConsoleCP(CP_UTF8);              // задать кодировку для ввода
SetConsoleOutputCP(CP_UTF8);        // задать кодировку для ввода

printf("Введите натуральное число n\n");
scanf("%i", &n);
//делим число на 10, пока в нем не останется одна цифра
 while (n >= 10 || n <= -10) {  
        n /= 10;
 }
 n = abs(n);
printf("Первая цифра числа n = %i", n);
}