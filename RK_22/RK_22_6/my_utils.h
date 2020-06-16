#ifndef MY_UTILS_H
#define MY_UTILS_H

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define OK 0
#define NUL 0
#define OPEN_ERROR 1
#define INVALID_ARG 2
#define MAX_STR 1000
#define STR_LEN 257

int from_file_to_array(FILE *const f, char str[MAX_STR][STR_LEN]);
void print_array_to_file_txt(FILE *const f, char str[MAX_STR][STR_LEN], int n);
void print_file_to_cons(FILE *f, int n);


#endif // MY_UTILS_H
