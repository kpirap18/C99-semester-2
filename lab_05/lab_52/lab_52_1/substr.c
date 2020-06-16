#include "my_utils.h"

int surname_substr_bin(FILE *const f_in, FILE *const f_out, const char *substr)
{
    size_t size;
    student_r student;
    memset(&student, 0, sizeof(student_r));
    file_size(f_in, &size);

    int count_substr = 0;

    for (size_t i = 0; i < size; ++i)
    {
        get_student_by_pos(f_in, i, &student);
        char *check = strstr(student.surname, substr);
        int check_ = check - student.surname;
        if (check_ == 0)
        {
            fwrite(&student, sizeof(student_r), 1, f_out);
            count_substr++;
        }
    }

    return count_substr;
}

int surname_substr_txt(student_r students[], FILE *const f_out, int n, const char *substr)
{
    int count_substr = 0;
    for (int i = 0; i < n; i++)
    {
        if (strncmp(students[i].surname, substr, strlen(substr)) == 0)
        {
            print_struct_to_file_txt(f_out, students[i]);
            count_substr++;
        }
    }

    return count_substr;
}
