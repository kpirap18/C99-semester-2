#ifndef _MY_UTILS_H
#define _MY_UTILS_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define MAX_COUNT_RECORD 100
#define MAX_LEN_SURNAME 26
#define MAX_LEN_NAME 11
#define COUNT_MARK 4
#define EPS 1e-06

#define OK 0
#define NOT_ENOUGH_ARG 53
#define OPEN_ERROR -2
#define FILE_EMPTY 42
#define GET_PUT_ERROR -3
#define NO_MATCHES -4
#define INVALID_ARG -5

typedef struct
{
    char surname[MAX_LEN_SURNAME];
    char name[MAX_LEN_NAME];
    unsigned int marks[COUNT_MARK];
} student_r;


void print_struct_to_file_txt(FILE *const f, student_r s);
void struct_print(student_r s);
void print_file_bin(FILE *const f);

void sort_file_bin(FILE *const fsrc);
void sort_file_txt(student_r students[], int n);

void get_student_by_pos(FILE *fsrc, int pos, student_r *er);
void put_student_by_pos(FILE *fsrc, int pos, student_r er);

void file_copy_bin(FILE *const f_in_out, FILE *const f_copy);
int from_file_to_array(FILE *const f, student_r student[]);

int checking_file_for_correct(FILE *f);
int file_size(FILE *const fsrc, size_t *size);

double average_student(unsigned int *arr, int size);
double average_all_students_txt(student_r *students, int len_student);
double average_all_students_bin(FILE *const f);

int surname_substr_bin(FILE *const f_in, FILE *const f_out, const char *substr);
int surname_substr_txt(student_r students[], FILE *const f_out, int n, const char *substr);

int file_new_del_los(FILE *const f, FILE *const f_copy);
void arr_new_del_los(student_r *students, int len_student, FILE *const f_in_out);

#endif // _MY_UTILS_H

