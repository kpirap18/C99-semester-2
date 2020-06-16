#include "my_utils.h"

void get_student_by_pos(FILE *fsrc, int pos, student_r *er)
{
    pos = pos * sizeof(student_r);
    fseek(fsrc, pos, SEEK_SET);
    fread(er, sizeof(student_r), 1, fsrc);
}
void put_student_by_pos(FILE *fsrc, int pos, student_r er)
{
    pos = pos * sizeof(student_r);
    fseek(fsrc, pos, SEEK_SET);
    fwrite(&er, sizeof(student_r), 1, fsrc);
}
