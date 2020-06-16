#include "my_utils.h"

void print_struct_to_file_txt(FILE *const f, student_r s)
{
    fprintf(f, "%s\n", s.surname);
    fprintf(f, "%s\n", s.name);

    for (int j = 0; j < COUNT_MARK; j++)
        fprintf(f, "%d ", s.marks[j]);
    fprintf(f, "\n");
}
void struct_print(student_r s)
{
    printf("%s\n", s.surname);
    printf("%s\n", s.name);

    for (int i = 0; i < COUNT_MARK; i++)
        printf("%u ", s.marks[i]);

    printf("\n");
}

void print_file_bin(FILE *const f)
{
    fseek(f, 0L, SEEK_SET);

    student_r student;
    memset(&student, 0, sizeof(student_r));
    size_t n = 0;
    file_size(f, &n);

    for (size_t i = 0; i < n; i++)
    {
        fread(&student, sizeof(student_r), 1, f);
        struct_print(student);
    }
}
