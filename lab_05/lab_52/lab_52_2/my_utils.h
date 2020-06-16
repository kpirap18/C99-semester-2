#ifndef _MY_UTILS_H
#define _MY_UTILS_H

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define MAX_COUNT_RECORD 1000
#define MAX_LEN_MAKER 16
#define MAX_LEN_NAME 31
#define EPS 1e-06

#define OK 0
#define NOT_ENOUGH_ARG 53
#define OPEN_ERROR -2
#define FILE_EMPTY 42
#define GET_PUT_ERROR -3
#define NO_MATCHES -4
#define INVALID_ARG -5
#define READ_ERROR -6

typedef struct
{
    char name[MAX_LEN_NAME];
    char maker[MAX_LEN_MAKER];
    unsigned int price;
    unsigned int count;
} product_r;


void print_struct_to_file_txt(FILE *const f, product_r s);
void struct_print(product_r s);
void print_file_bin(FILE *const f);

void sort_file_bin(FILE *const fsrc);
void sort_file_txt(product_r students[], int n);

void get_student_by_pos(FILE *fsrc, int pos, product_r *er);
void put_student_by_pos(FILE *fsrc, int pos, product_r er);

void file_copy_bin(FILE *const f_in_out, FILE *const f_copy);
int from_file_to_array(FILE *const f, product_r student[]);

int checking_file_for_correct(FILE *f);
int file_size(FILE *const fsrc, size_t *size);

int entry_struct(product_r *product);
int add_info(FILE *const f, const product_r product);
int add_info_txt(product_r products[], const product_r product, int len, FILE *f);

int surname_substr_bin(FILE *const f_in, const char *substr);
int surname_substr_txt(product_r students[], int n, const char *substr);
int check_substr(char *name, const char *substr);


#endif // _MY_UTILS_H
