#include "my_utils.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    FILE *f_in;
    FILE *f_out, *f_in_out;

    if ((argc == 3) && ((strcmp(argv[1], "sb") == 0)))
    {
        f_in = fopen(argv[2], "r+b");

        int check_f = checking_file_for_correct(f_in);

        if (check_f != OK)
        {
            if (check_f == OPEN_ERROR)
            {
                printf("Open error\n");

                return OPEN_ERROR;
            }

            if (check_f == INVALID_ARG)
            {
                printf("Invalid argument in file\n");
                fclose(f_in);

                return INVALID_ARG;
            }

            if (check_f == FILE_EMPTY)
            {
                printf("File is empty\n");
                fclose(f_in);
                return FILE_EMPTY;
            }
        }

        sort_file_bin(f_in);
        print_file_bin(f_in);

        fclose(f_in);

        return OK;
    }

    if ((argc == 3) && ((strcmp(argv[1], "st") == 0)))
    {
        f_in = fopen(argv[2], "r");

        if (f_in == NULL)
        {
            printf("Open error");
            return OPEN_ERROR;
        }

        student_r students[MAX_COUNT_RECORD];
        memset(&students, 0, sizeof(student_r));

        int len_student = from_file_to_array(f_in, students);

        if (len_student == INVALID_ARG)
        {
            printf("Invalid argument in file\n");
            fclose(f_in);
            return INVALID_ARG;
        }

        sort_file_txt(students, len_student);

        for (int k = 0; k < len_student; k++)
            struct_print(students[k]);

        fclose(f_in);

        return OK;
    }

    if ((argc == 5) && ((strcmp(argv[1], "fb") == 0)))
    {
        f_in = fopen(argv[2], "rb");
        f_out = fopen(argv[3], "wb");


        int check_f = checking_file_for_correct(f_in);

        if (check_f != OK)
        {
            if (check_f == OPEN_ERROR)
            {
                printf("Open error\n");

                return OPEN_ERROR;
            }

            if (check_f == INVALID_ARG)
            {
                printf("Invalid argument in file\n");
                fclose(f_in);

                return INVALID_ARG;
            }

            if (check_f == FILE_EMPTY)
            {
                printf("File is empty\n");
                fclose(f_in);
                return FILE_EMPTY;
            }
        }
        int rc = surname_substr_bin(f_in, f_out, argv[4]);

        if (rc == 0)
        {
            fclose(f_in);
            fclose(f_out);

            printf("No mathes");

            return NO_MATCHES;
        }

        fclose(f_in);
        fclose(f_out);

        return OK;
    }
    if ((argc == 5) && ((strcmp(argv[1], "ft") == 0)))
    {
        f_in = fopen(argv[2], "r");
        f_out = fopen(argv[3], "w");

        if (f_in == NULL)
        {
            printf("Open error");
            return OPEN_ERROR;
        }

        student_r students[MAX_COUNT_RECORD];
        memset(&students, 0, sizeof(student_r));

        int len_student = from_file_to_array(f_in, students);

        if (len_student == INVALID_ARG)
        {
            printf("Invalid argument in file\n");
            fclose(f_in);
            fclose(f_out);
            return INVALID_ARG;
        }

        int rc = surname_substr_txt(students, f_out, len_student, argv[4]);

        if (rc == 0)
        {
            fclose(f_in);
            fclose(f_out);

            printf("No mathes");

            return NO_MATCHES;
        }

        fclose(f_in);
        fclose(f_out);

        return OK;
    }
    if ((argc == 3) && ((strcmp(argv[1], "db") == 0)))
    {
        FILE *f_copy;
        f_in_out = fopen(argv[2], "rb");
        f_copy = fopen("copy.bin", "wb");

        int check_f = checking_file_for_correct(f_in_out);

        if (check_f != OK)
        {
            if (check_f == OPEN_ERROR)
            {
                printf("Open error\n");

                return OPEN_ERROR;
            }

            if (check_f == INVALID_ARG)
            {
                printf("Invalid argument in file\n");
                fclose(f_in_out);

                return INVALID_ARG;
            }

            if (check_f == FILE_EMPTY)
            {
                printf("File is empty\n");
                fclose(f_in_out);
                return FILE_EMPTY;
            }
        }

        int new_length = file_new_del_los(f_in_out, f_copy);

        fclose(f_in_out);
        fclose(f_copy);

        f_in_out = fopen(argv[2], "wb");
        f_copy = fopen("copy.bin", "rb");

        file_copy_bin(f_in_out, f_copy);

        truncate(argv[2], new_length);
        truncate("copy.bin", 0);

        fclose(f_in_out);
        fclose(f_copy);

        return OK;
    }
    if ((argc == 3) && ((strcmp(argv[1], "dt") == 0)))
    {
        f_in_out = fopen(argv[2], "r");

        if (f_in_out == NULL)
        {
            printf("Open error");
            return OPEN_ERROR;
        }

        student_r students[MAX_COUNT_RECORD];
        memset(&students, 0, sizeof(student_r));

        int len_student = from_file_to_array(f_in_out, students);

        if (len_student == INVALID_ARG)
        {
            printf("Invalid argument in file\n");
            fclose(f_in_out);
            return INVALID_ARG;
        }

        student_r new_students[MAX_COUNT_RECORD];
        memset(&new_students, 0, sizeof(student_r));

        fclose(f_in_out);
        f_in_out = fopen(argv[2], "w");

        arr_new_del_los(students, len_student, f_in_out);

        fclose(f_in_out);

        return OK;
    }

    printf("Not enough argument\n");
    return NOT_ENOUGH_ARG;
}


