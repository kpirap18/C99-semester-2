#include "my_utils.h"

int from_file_to_array(FILE *const f, student_r student[])
{
    int i = 0;
    while (fscanf(f, "%s %s", student[i].surname, student[i].name) == 2)
    {
        int rc;
        for (int j = 0; j < COUNT_MARK; j++)
        {
            rc = fscanf(f, "%u", &student[i].marks[j]);

            if (rc == 0)
                return INVALID_ARG;
        }

        i++;
    }

    if (i)
        return i;
    else
        return INVALID_ARG;
}
void file_copy_bin(FILE *const f_in_out, FILE *const f_copy)
{
    size_t size;
    file_size(f_copy, &size);

    student_r student;
    memset(&student, 0, sizeof(student_r));

    for (size_t i = 0; i < size; ++i)
    {
        get_student_by_pos(f_copy, i, &student);
        fwrite(&student, sizeof(student_r), 1, f_in_out);
    }
}
