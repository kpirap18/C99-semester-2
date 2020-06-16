#ifndef _COMMAND_H
#define _COMMAND_H

#include "get_put.h"

int command_c(FILE *fsrc, char *count_str);
int file_size(FILE *fsrc, size_t *size);
int command_p(FILE *fsrc);
int command_s(FILE *fsrc);

#endif // _COMMAND_H
