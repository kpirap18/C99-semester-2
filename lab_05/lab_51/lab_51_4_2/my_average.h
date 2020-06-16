#ifndef _MY_AVERAGE_H
#define _MY_AVERAGE_H

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>

#define EPS 1e-06
#define OK 0
#define NOT_ENOUGH_ARG -1
#define OPEN_ERROR -2
#define INPUT_ERROR -3

int max_min_file(FILE *fsrc, int *max_i, int *min_i);
float average(FILE *fsrc, int min_i, int max_i);

#endif // _MY_AVERAGE_H
