Лабораторна робота 12. Взаємодія з користувачем шляхом механізму введення/виведення

Панкеєв Владислав Олексійович 922-Б

Множення матрць

Основна частина:
Вміст файлу main.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lib.h"

int main()
{
	float **matrix1;
	float **matrix2;
	float **result_mul_matrix;
	unsigned int links1;
	unsigned int colums1;
	unsigned int links2;
	unsigned int colums2;
	int error_input;
	int true_input;
	int leave = 1;
	int true_result = 1;
	
	//Цикл для запису розмірів матриць
	while (true_result == 1) {
	
		true_input = 1;
		while (true_input == 1) {
		
			printf("\n\nВведіть кількість строк та кількість стовпців через \":\" для першої матриці:");
			scanf("%d:%d", &links1, &colums1);
			
			printf("\nВведіть кількість строк та кількість стовпців через \":\" для другої матриці:");
			scanf("%d:%d", &links2, &colums2);

			if (colums1 != links2 || getchar() != ' ') {
			
				while (getchar() != ' ');
					
				printf("\n\nВи ввели незрозуміле значення!!!!");
				printf("\nЯк що ви хочите ввести значення ще раз введіть 1, для завершення операції введіть 0:");
				scanf("%d", &error_input);

				while (error_input < 0 || error_input >= 2) {
					printf("\nЯк що ви хочите ввести значення ще раз введіть 1, для завершення операції введіть 0:");
					scanf("%d", &error_input);
					while (getchar() != ' ');
						
				}

				if (error_input == 0) {
					leave = 0;
					true_input = 0;
				}
				
			} else
				true_input = 0;

			if (leave == 0)
				return 0;
		}

		//Виділяємо місце для запису елементів матриці
		matrix1 = malloc(sizeof(float *) * links1);
		for (unsigned int i = 0; i < links1; i++)
			*(matrix1 + i) = malloc(sizeof(float) * colums1);

		matrix2 = malloc(sizeof(float *) * links2);
		for (unsigned int i = 0; i < links2; i++)
			*(matrix2 + i) = malloc(sizeof(float) * colums2);
					
			printf("\nВведіть значення першої матриці по строках:");
			for (unsigned int i = 0; i < links1; i++) {
				for (unsigned int j = 0; j < colums1; j++)
					scanf("%f", &*(*(matrix1 + i) + j));
			}

			printf("\nВведіть значення другої матриці по строках:");
			for (unsigned int i = 0; i < links2; i++) {
				for (unsigned int j = 0; j < colums2; j++)
					scanf("%f", &*(*(matrix2 + i) + j));
			}

			if (getchar() != ' ') {
			
				while (getchar() != ' ');
					
				printf("\n\nВи ввели незрозуміле значення, або кількість введених вами значень не відповідає розмірам матриць!!!!");
				printf("\nЯк що ви хочите змінити розмір матриці то введіть 2, як що ще раз записати значення то 1, для завершення операції введіть 0:");
				scanf("%d", &error_input);

				while (error_input < 0 || error_input >= 3) {
					printf("\nЯк що ви хочите змінити розмір матриці то введіть 2, як що ще раз записати значення то 1, для завершення операції введіть 0:");
					scanf("%d", &error_input);
					while (getchar() != ' ');
				}

				if (error_input == 0) {
					
					leave = 0; 
					true_input = 0;

					for (unsigned int i = 0; i < links1; i++){
					free(*(matrix1 + i));	
					}
					free(matrix1);
					matrix1 = NULL;

					for (unsigned int i = 0; i < links2; i++) {
						free(*(matrix2 + i));	
					}
					free(matrix2);
					
					}else if (error_input == 2){
						
					for (unsigned int i = 0; i < links1; i++) {
						free(*(matrix1 + i));
						}
					free(matrix1);

					for (unsigned int i = 0; i < links2; i++) {
						free(*(matrix2 + i));
						}
						free(matrix2);

						true_input = 2;
						}

						} else
						true_input = 0;


						if (leave == 0)
	return 0;
}
					
					
		
		// Як що всі дані були введено коректно то множимо матриці і виводимо результат
		if (true_input == 0) {
		
			
			result_mul_matrix = malloc(sizeof(float *) * links1);
			for (unsigned int i = 0; i < links1; i++)
				*(result_mul_matrix + i) = malloc(sizeof(float) * colums2);

			mul_matrix(matrix1, matrix2, result_mul_matrix, links1, colums2, links2);
			
			printf("\n\nРезультат множення матриць");
			for (unsigned int i = 0; i < links1; i++) {
				printf("\n[");
				for (unsigned int j = 0; j < colums2; j++)
					printf(" %.2f\t", *(*(result_mul_matrix + i) + j));

				printf("\b]");
			}

			for (unsigned int i = 0; i < links1; i++) {
				free(*(matrix1 + i));
				free(*(result_mul_matrix + i));
			}
			free(matrix1);
			free(result_mul_matrix);

			for (unsigned int i = 0; i < links2; i++) {
				free(matrix2[i]);
			}
			free(matrix2);

			printf("\n\nЯк що ви хочите повторити операцію то введіть 1, для виходу з програми введіть 0:");
			scanf("%d", &true_result);
		}
	}

	return 0;
}

lib.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

int mul_matrix(float **matrix1, float **matrix2, float **result_mul_matrix, unsigned int links1, unsigned int colums2, unsigned int links2)
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

lib.h

int mul_matrix(float **a, float **b, float **c, unsigned int d, unsigned int e, unsigned int f);

test.c
 
#include "../src/lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include <math.h>

#define EPSILON 0.000001

START_TEST(test_mul_matrix_size_2x2)
{	
	float a = 0;
	unsigned int links = 2;
	unsigned int colums = 2;
	
	float **matrix1 = malloc(sizeof(float *) * links);
	float **matrix2 = malloc(sizeof(float *) * links);
		for (unsigned int i = 0; i < links; i++){
		
				*(matrix1 + i) = malloc(sizeof(float) * colums);
				*(matrix2 + i) = malloc(sizeof(float) * colums);
		}
				
	for (unsigned int i = 0; i < links; i++) {
		for (unsigned int j = 0; j < colums; j++) {
			
			a += 1;
			*(*(matrix1 + i) + j) = a;
			*(*(matrix2 + i) + j) = a; 
		}
	}
	
	float **expected_matrix = malloc(sizeof(float *) * links);
	float **actual_matrix = malloc(sizeof(float *) * links);
		for (unsigned int i = 0; i < links; i++){
		
				*(expected_matrix + i) = malloc(sizeof(float) * colums);
				*(actual_matrix + i) = malloc(sizeof(float) * colums);
		}
	
	*(*(expected_matrix + 0) + 0) = 7;
	*(*(expected_matrix + 0) + 1) = 10;
	*(*(expected_matrix + 1) + 0) = 15;
	*(*(expected_matrix + 1) + 1) = 22;
	

	mul_matrix(matrix1, matrix2, actual_matrix, links, colums, colums);
	
	for (unsigned int i = 0; i < links; i++) {
	
		for (unsigned int j = 0; j < colums; j++) {
			
			if(fabs(*(*(actual_matrix + i) + j)  - *(*(expected_matrix + i) + j) ) < EPSILON)
			{
				ck_assert_int_eq(1,1);
			}
			else
			{
				ck_assert_int_eq(1,0);
			}
			
		}
	}
	
	for (unsigned int i = 0; i < links; i++) {
			free(*(matrix1 + i));
			free(matrix2[i]);
			free(*(expected_matrix + i));
			free(*(actual_matrix + i));
		}
		free(matrix1);
		free(matrix2);
		free(expected_matrix);
		free(actual_matrix);
}
END_TEST

START_TEST(test_mul_matrix_size_3x2_2x3)
{	
	float a = 0;
	unsigned int links1 = 3;
	unsigned int colums1 = 2;
	unsigned int links2 = 2;
	unsigned int colums2 = 3;
	
	float **matrix1 = malloc(sizeof(float *) * links1);
		for (unsigned int i = 0; i < links1; i++)
				*(matrix1 + i) = malloc(sizeof(float) * colums1);
				
	for (unsigned int i = 0; i < links1; i++) {
		for (unsigned int j = 0; j < colums1; j++) {
			
			a += 1;
			*(*(matrix1 + i) + j) = a; 
		}
	}
	
	float **matrix2 = malloc(sizeof(float *) * links2);
		for (unsigned int i = 0; i < links2; i++)
				*(matrix2 + i) = malloc(sizeof(float) * colums2);
	
	a = 0;
			
	for (unsigned int i = 0; i < links2; i++) {
		for (unsigned int j = 0; j < colums2; j++) {
			
			a += 1;
			*(*(matrix2 + i) + j) = a; 
		}
	}
	
	float **actual_matrix = malloc(sizeof(float *) * links1);
	float **expected_matrix = malloc(sizeof(float *) * links1);
	
		for (unsigned int i = 0; i < links1; i++){
		
				*(expected_matrix + i) = malloc(sizeof(float) * colums2);
				*(actual_matrix + i) = malloc(sizeof(float) * colums2);
		}
	
	*(*(expected_matrix + 0) + 0) = 9;
	*(*(expected_matrix + 0) + 1) = 12;
	*(*(expected_matrix + 0) + 2) = 15;
	*(*(expected_matrix + 1) + 0) = 19;
	*(*(expected_matrix + 1) + 1) = 26;
	*(*(expected_matrix + 1) + 2) = 33;
	*(*(expected_matrix + 2) + 0) = 29;
	*(*(expected_matrix + 2) + 1) = 40;
	*(*(expected_matrix + 2) + 2) = 51;
	

	actual_matrix = mul_matrix(matrix1, matrix2, actual_matrix, links1, colums2, links2);
	
	
	
	for (unsigned int i = 0; i < links1; i++) {
	
		for (unsigned int j = 0; j < colums2; j++) {
			
			if(fabs(*(*(actual_matrix + i) + j)  - *(*(expected_matrix + i) + j) ) < EPSILON)
			{
				ck_assert_int_eq(1,1);
			}
			else
			{
				ck_assert_int_eq(1,0);
			}
			
		}
	}
	
	for (unsigned int i = 0; i < links1; i++) {
			free(*(matrix1 + i));
			free(*(expected_matrix + i));
			free(*(actual_matrix + i));
		}
		free(matrix1);
		free(expected_matrix);
		free(actual_matrix);

	for (unsigned int i = 0; i < links2; i++) {
			free(matrix2[i]);
		}
		free(matrix2);
	
}
END_TEST

START_TEST(test_mul_matrix_size_3x2_2x4)
{	
	float a = 0;
	unsigned int links1 = 3;
	unsigned int colums1 = 2;
	unsigned int links2 = 2;
	unsigned int colums2 = 4;
	
	float **matrix1 = malloc(sizeof(float *) * links1);
		for (unsigned int i = 0; i < links1; i++)
				*(matrix1 + i) = malloc(sizeof(float) * colums1);
				
	for (unsigned int i = 0; i < links1; i++) {
		for (unsigned int j = 0; j < colums1; j++) {
			
			a += 1;
			*(*(matrix1 + i) + j) = a; 
		}
	}
	
	float **matrix2 = malloc(sizeof(float *) * links2);
		for (unsigned int i = 0; i < links2; i++)
				*(matrix2 + i) = malloc(sizeof(float) * colums2);
	
	a = 0;
			
	for (unsigned int i = 0; i < links2; i++) {
		for (unsigned int j = 0; j < colums2; j++) {
			
			a += 1;
			*(*(matrix2 + i) + j) = a; 
		}
	}
	
	float **actual_matrix = malloc(sizeof(float *) * links1);
	float **expected_matrix = malloc(sizeof(float *) * links1);
	
		for (unsigned int i = 0; i < links1; i++){
		
				*(expected_matrix + i) = malloc(sizeof(float) * colums2);
				*(actual_matrix + i) = malloc(sizeof(float) * colums2);
		}
	
	*(*(expected_matrix + 0) + 0) = 11;   
	*(*(expected_matrix + 0) + 1) = 14;
	*(*(expected_matrix + 0) + 2) = 17;
	*(*(expected_matrix + 0) + 3) = 20;
	*(*(expected_matrix + 1) + 0) = 23;
	*(*(expected_matrix + 1) + 1) = 30;
	*(*(expected_matrix + 1) + 2) = 37;
	*(*(expected_matrix + 1) + 3) = 44;
	*(*(expected_matrix + 2) + 0) = 35;
	*(*(expected_matrix + 2) + 1) = 46;
	*(*(expected_matrix + 2) + 2) = 57;
	*(*(expected_matrix + 2) + 3) = 68;
	

	actual_matrix = mul_matrix(matrix1, matrix2, actual_matrix, links1, colums2, links2);
	
	
	for (unsigned int i = 0; i < links1; i++) {
	
		for (unsigned int j = 0; j < colums2; j++) {
			
			if(fabs(*(*(actual_matrix + i) + j)  - *(*(expected_matrix + i) + j) ) < EPSILON)
			{
				ck_assert_int_eq(1,1);
			}
			else
			{
				ck_assert_int_eq(1,0);
			}
			
		}
	}
	
	for (unsigned int i = 0; i < links1; i++) {
			free(*(matrix1 + i));
			free(*(expected_matrix + i));
			free(*(actual_matrix + i));
		}
		free(matrix1);
		free(expected_matrix);
		free(actual_matrix);

	for (unsigned int i = 0; i < links2; i++) {
			free(matrix2[i]);
		}
		free(matrix2);
	
}
END_TEST

Suite *lab_test_suite(void)
{
	Suite *s;
	TCase *tc_mul_matrix;

	s = suite_create("lab12");

	tc_mul_matrix = tcase_create("mul_matrix");

	tcase_add_test(tc_mul_matrix, test_mul_matrix_size_2x2);
	tcase_add_test(tc_mul_matrix, test_mul_matrix_size_3x2_2x3);
	tcase_add_test(tc_mul_matrix, test_mul_matrix_size_3x2_2x4);

	suite_add_tcase(s, tc_mul_matrix);

	return s;
}

int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;

	s = lab_test_suite();
	sr = srunner_create(s);

	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

Результат

Введіть кількість строк та кількість стовпців через ":" для першої матриці:
Введіть кількість строк та кількість стовпців через ":" для другої матриці:
Введіть значення першої матриці по строках:
Введіть значення другої матриці по строках:

Результат множення матриць
[ 7.00   10.00 ]
[ 15.00  22.00 ]

Як що ви хочите повторити операцію то введіть 1, для виходу з програми введіть 0:
Результат тесту та покриття коду

Running suite(s): lab12
100%: Checks: 3, Failures: 0, Errors: 0
llvm-profdata merge -sparse dist/test.profraw -o dist/test.profdata
llvm-cov report dist/test.bin -instr-profile=dist/test.profdata src/*.c
Filename                                         Regions    Missed Regions     Cover   Functions  Missed Functions  Executed       Lines      Missed Lines     Cover    Branches   Missed Branches     Cover
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/home/labaproga/lab12/src/lib.c          10                 0   100.00%           1                 0   100.00%          11                 0   100.00%           6                 0   100.00%
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
TOTAL                                                 10                 0   100.00%           1                 0   100.00%          11                 0   100.00%           6                 0   100.00%


Дослідження витоків

==41139== Memcheck, a memory error detector
==41139== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==41139== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==41139== Command: cat ./assets/text.txt
==41139== Parent PID: 41138
==41139==
==41139==
==41139== HEAP SUMMARY:
==41139==     in use at exit: 0 bytes in 0 blocks
==41139==   total heap usage: 46 allocs, 46 frees, 143,366 bytes allocated
==41139==
==41139== All heap blocks were freed -- no leaks are possible
==41139==
==41139== For lists of detected and suppressed errors, rerun with: -s
==41139== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

----------------------------------------------------------------------------

Структура проекту лабораторної роботи:
   
├── assets
│   └── text.txt
├── Doxyfile
├── Makefile
├── README.md
├── test
│   └── test.c
└── src
    ├── lib.c
    ├── lib.h
    └── main.c
