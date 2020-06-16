#include "my_utils.h"

void sort_file_txt(student_r students[], int n)
{
    student_r buf;
    memset(&buf, 0, sizeof(student_r));

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (strcmp(students[i].surname, students[j].surname) > 0)
            {
                buf = students[i];
                students[i] = students[j];
                students[j] = buf;
            }
            else
            {
                if (strcmp(students[i].surname, students[j].surname) == 0)
                {
                    if (strcmp(students[i].name, students[j].name) > 0)
                    {
                        buf = students[i];
                        students[i] = students[j];
                        students[j] = buf;
                    }
                }
            }
        }
    }
}
void sort_file_bin(FILE *const fsrc)
{
    size_t i, j, n = 0;
    student_r student_f, student_s;
    memset(&student_f, 0, sizeof(student_r));
    memset(&student_s, 0, sizeof(student_r));

    file_size(fsrc, &n);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; ++j)
        {
            get_student_by_pos(fsrc, i, &student_f);
            get_student_by_pos(fsrc, j, &student_s);

            if (strcmp(student_f.surname, student_s.surname) > 0)
            {
                put_student_by_pos(fsrc, i, student_s);
                put_student_by_pos(fsrc, j, student_f);
            }
            else
            {
                if (strcmp(student_f.surname, student_s.surname) == 0)
                {
                    if (strcmp(student_f.name, student_s.name) > 0)
                    {
                        put_student_by_pos(fsrc, i, student_s);
                        put_student_by_pos(fsrc, j, student_f);
                    }
                }
            }
        }
    }
}
