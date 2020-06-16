#include "my_utils.h"

void get_student_by_pos(FILE *fsrc, int pos, product_r *er)
{
    pos = pos * sizeof(product_r);
    fseek(fsrc, pos, SEEK_SET);
    fread(er, sizeof(product_r), 1, fsrc);
}
void put_student_by_pos(FILE *fsrc, int pos, product_r er)
{
    pos = pos * sizeof(product_r);
    fseek(fsrc, pos, SEEK_SET);
    fwrite(&er, sizeof(product_r), 1, fsrc);
}
