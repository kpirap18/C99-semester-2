#include "get_put.h"

int get_number_by_pos(FILE *fsrc, size_t pos, int *er)
{
    int num = 0;
    pos = pos * sizeof(int);
    int rc = fseek(fsrc, pos, SEEK_SET);
    if (rc == 0)
        rc = fread(&num, sizeof(int), 1, fsrc);
    if (rc != 1)
        *er = GET_PUT_ERROR;
    return num;
}
int put_number_by_pos(FILE *fsrc, size_t pos, int num, int *er)
{
    pos = pos * sizeof(int);
    int rc = fseek(fsrc, pos, SEEK_SET);
    if (rc == 0)
        rc = fwrite(&num, sizeof(int), 1, fsrc);
    if (rc != 1)
        *er = GET_PUT_ERROR;
    return OK;
}
