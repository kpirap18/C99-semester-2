#include "my_utils.h"

int file_size(FILE *const fsrc, size_t *size)
{
    fseek(fsrc, 0, SEEK_END);

    *size = ftell(fsrc);

    if ((*size <= 0) || (*size < sizeof(student_r)))
        return OPEN_ERROR;

    *size = *size / sizeof(student_r);

    return fseek(fsrc, 0, SEEK_SET);;
}

int checking_file_for_correct(FILE *f)
{
    student_r var_for_check;
    memset(&var_for_check, 0, sizeof(student_r));

    if (f == NULL)
        return OPEN_ERROR;

    size_t size;
    file_size(f, &size);

    if (size <= 0)
        return FILE_EMPTY;

    fseek(f, 0L, SEEK_SET);

    for (size_t i = 0; i < size; i++)
    {
        int read = fread(&var_for_check, sizeof(student_r), 1, f);

        if (read != 1)
            return INVALID_ARG;
    }

    return OK;
}
