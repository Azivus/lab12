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
	

	actual_matrix = mul_matrix(matrix1, matrix2, actual_matrix, links, colums, colums);
	
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
