#include "my_utils.h"

int file_new_del_los(FILE *const f, FILE *const f_copy)
{
    double average_overall = average_all_students_bin(f);

    fseek(f, 0L, SEEK_SET);

    size_t size;
    file_size(f, &size);

    student_r student;
    memset(&student, 0, sizeof(student_r));

    int new_count = 0;
    for (size_t i = 0; i < size; i++)
    {
        get_student_by_pos(f, i, &student);
        if (fabs(average_student(student.marks, COUNT_MARK) - average_overall) < EPS || \
            (average_student(student.marks, COUNT_MARK) - average_overall) >= EPS)
        {
            fwrite(&student, sizeof(student_r), 1, f_copy);
            new_count++;
        }
    }

    return new_count;
}
void arr_new_del_los(student_r *students, int len_student, FILE *const f_in_out)
{
    double average_overall = average_all_students_txt(students, len_student);

    for (int i = 0; i < len_student; i++)
        if (fabs(average_student(students[i].marks, COUNT_MARK) - average_overall) < EPS || \
            (average_student(students[i].marks, COUNT_MARK) - average_overall) >= EPS)
        {
            print_struct_to_file_txt(f_in_out, students[i]);
        }
}
