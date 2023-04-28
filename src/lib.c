/**
\file lib.c
\brief Файл з реалізацією функцій

Цей файл, містить реалізацію функції mul_matrix.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/**
 
 Функція mul_matrix
 \param **matrix1 - масив першої матриці.
 \param **matrix2 - масив другої матриці.
 \param **result_mul_matrix - масив матриці у яку ми запишиме результат.
 \param links1 - кількість строк у матриці з результатом.
 \param colums2 - кількість стовпців у матриці з результатом.
 \param links2 - кількість стовпців першої матриці або кількість строк другої матриці.
 \return Повертає матрицю з результатами множення.
 
 
 Послідовність дій
 
- Створюємо 2 цикли що перебирають елемнти у матрицях які ми перемножуємо та задає адрес у результуючій матриці куди ми записуємо результат.

- Створюємо 3 цикл який задає адрес конкретного значення у матрицях matrix1 та matrix2.

- Помножуємо елемнти у матрицях, складаемо їх та записуємо у нашу результуючу матрицю.

- Повртаємо матрицю в якій знаходиться результат множення.  

*/

void mul_matrix(float **matrix1, float **matrix2, float **result_mul_matrix, unsigned int links1, unsigned int colums2, unsigned int links2)
{
	for (unsigned int i = 0; i < links1; i++) {
		for (unsigned int j = 0; j < colums2; j++) {
			
			*(*(result_mul_matrix + i) + j) = 0;
			
			for (unsigned int f = 0; f < links2; f++) {
				*(*(result_mul_matrix + i) + j) += *(*(matrix1 + i) + f) * *(*(matrix2 + f) + j);
			}
		}
	}
	
	return 0;

}
