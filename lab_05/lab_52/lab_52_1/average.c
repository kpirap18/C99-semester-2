#include "my_utils.h"

double average_student(unsigned int *arr, int size)
{
    double sum_stud = 0;

    for (int i = 0; i < size; ++i)
        sum_stud += arr[i];

    sum_stud /= COUNT_MARK;
    return sum_stud;
}
double average_all_students_bin(FILE *const f)
{
    size_t size;
    file_size(f, &size);

    student_r student;
    memset(&student, 0, sizeof(student_r));

    double sum = 0;
    double ave = 0;

    for (size_t i = 0; i < size; ++i)
    {
        get_student_by_pos(f, i, &student);
        sum += average_student(student.marks, COUNT_MARK);
    }

    ave = sum / size;

    return ave;
}
double average_all_students_txt(student_r *students, int len_student)
{
    double sum = 0;

    for (int i = 0; i < len_student; ++i)
    {
        sum += average_student(students[i].marks, COUNT_MARK);
    }

    sum /= len_student;

    return sum;
}

