#include "command.h"

int command_c(FILE *fsrc, char *count_str)
{
    size_t wrote;
    int count;

    char *point = strchr(count_str, '.');
    if (point == NULL)
        count = atoi(count_str);
    else
        return WRITE_ERROR;

    if (count <= 0)
        return WRITE_ERROR;

    srand((unsigned int)time(NULL));
    for (int i = 0; i < count; i++)
    {
        int r = rand() % 100;
        wrote = fwrite(&r, sizeof(int), 1, fsrc);

        if (wrote != 1)
            return WRITE_ERROR;
    }

    return OK;
}
int file_size(FILE *fsrc, size_t *size)
{
    long size_1;

    if (fseek(fsrc, 0L, SEEK_END))
        return OPEN_ERROR;

    size_1 = ftell(fsrc);

    if (size_1 <= 0)
        return OPEN_ERROR;

    *size = size_1;

    return fseek(fsrc, 0L, SEEK_SET);;
}
int command_p(FILE *fsrc)
{
    size_t size;
    int num;
    size_t read;
    int rc = 0;

    rc = file_size(fsrc, &size);

    if (rc == 0)
    {
        if (size < sizeof(int))
            return READ_ERROR;
        for (size_t i = 0; ((rc == 0) && i < size / sizeof(int)); i++)
        {
            read = fread(&num, sizeof(int), 1, fsrc);

            if (read == 1)
                printf("%d ", num);
            else
                rc = READ_ERROR;
        }
    }
    else
        rc = WRITE_ERROR;

    return rc;
}

int command_s(FILE *fsrc)
{
    size_t i, j, n = 0;

    int rc = file_size(fsrc, &n);

    if (rc == 0)
    {
        if (n < sizeof(int))
            return READ_ERROR;
        n = n / sizeof(int);
        for (i = 1; i < n; i++)
        {
            int temp = get_number_by_pos(fsrc, i, &rc);

            for (j = i - 1; j + 1 > 0 && get_number_by_pos(fsrc, j, &rc) > temp; --j)
            {
                int buf = get_number_by_pos(fsrc, j, &rc);
                put_number_by_pos(fsrc, j + 1, buf, &rc);
            }
            put_number_by_pos(fsrc, j + 1, temp, &rc);
        }
    }

    return rc;
}
