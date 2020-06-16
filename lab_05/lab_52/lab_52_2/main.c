#include "my_utils.h"

int main(int argc, char **argv)
{
    setbuf(stdout, NULL);

    if ((argc == 4) && ((strcmp(argv[1], "sb") == 0)))
    {
        FILE *f_in;
        FILE *f_out;
        f_in = fopen(argv[2], "rb");
        f_out = fopen(argv[3], "wb");

        int check_f = checking_file_for_correct(f_in);

        if (check_f != OK)
        {
            if (check_f == OPEN_ERROR)
            {
                //printf("Open error\n");

                return OPEN_ERROR;
            }

            if (check_f == INVALID_ARG)
            {
                //printf("Invalid argument in file\n");
                fclose(f_in);

                return INVALID_ARG;
            }

            if (check_f == FILE_EMPTY)
            {
                //printf("File is empty\n");
                fclose(f_in);
                return FILE_EMPTY;
            }
        }

        file_copy_bin(f_out, f_in);
        fclose(f_out);
        f_out = fopen(argv[3], "r+b");
        truncate(argv[2], 0);
        sort_file_bin(f_out);

        fclose(f_in);
        fclose(f_out);

        return OK;
    }

    if ((argc == 4) && ((strcmp(argv[1], "st") == 0)))
    {
        FILE *f_in;
        FILE *f_out;
        f_in = fopen(argv[2], "r");

        if (f_in == NULL)
        {
            //printf("Open error");
            return OPEN_ERROR;
        }

        product_r products[MAX_COUNT_RECORD];
        memset(&products, 0, sizeof(product_r));

        int len_student = from_file_to_array(f_in, products);

        if (len_student == INVALID_ARG)
        {
            //printf("Invalid argument in file\n");
            fclose(f_in);
            return INVALID_ARG;
        }

        sort_file_txt(products, len_student);


        f_out = fopen(argv[3], "w");
        for (int k = 0; k < len_student; k++)
        {
            print_struct_to_file_txt(f_out, products[k]);
        }

        fclose(f_in);
        fclose(f_out);

        return OK;
    }

    if ((argc == 4) && ((strcmp(argv[1], "fb") == 0)))
    {
        FILE *f_in;
        f_in = fopen(argv[2], "rb");

        int check_f = checking_file_for_correct(f_in);

        if (check_f != OK)
        {
            if (check_f == OPEN_ERROR)
            {
                //printf("Open error\n");

                return OPEN_ERROR;
            }

            if (check_f == INVALID_ARG)
            {
                //printf("Invalid argument in file\n");
                fclose(f_in);

                return INVALID_ARG;
            }

            if (check_f == FILE_EMPTY)
            {
                //printf("File is empty\n");
                fclose(f_in);
                return FILE_EMPTY;
            }
        }
        int rc = surname_substr_bin(f_in, argv[3]);

        if (rc)
        {
            fclose(f_in);
            //printf("No mathes");

            return NO_MATCHES;
        }

        fclose(f_in);

        return OK;
    }
    if ((argc == 4) && ((strcmp(argv[1], "ft") == 0)))
    {
        FILE *f_in;
        f_in = fopen(argv[2], "r");

        if (f_in == NULL)
        {
            //printf("Open error");
            return OPEN_ERROR;
        }

        product_r products[MAX_COUNT_RECORD];
        memset(&products, 0, sizeof(product_r));

        int len_student = from_file_to_array(f_in, products);

        if (len_student == INVALID_ARG)
        {
            //printf("Invalid argument in file\n");
            fclose(f_in);
            return INVALID_ARG;
        }

        int rc = surname_substr_txt(products, len_student, argv[3]);

        if (rc == 0)
        {
            fclose(f_in);

            //printf("No mathes");

            return NO_MATCHES;
        }

        fclose(f_in);

        return OK;
    }
    if ((argc == 3) && ((strcmp(argv[1], "ab") == 0)))
    {
        FILE *f_in_out;
        f_in_out = fopen(argv[2], "r+b");

        int check_f = checking_file_for_correct(f_in_out);

        if (check_f != OK)
        {
            if (check_f == OPEN_ERROR)
            {
                //printf("Open error\n");

                return OPEN_ERROR;
            }

            if (check_f == INVALID_ARG)
            {
                //printf("Invalid argument in file\n");
                fclose(f_in_out);

                return INVALID_ARG;
            }

            if (check_f == FILE_EMPTY)
            {
                //printf("File is empty\n");
                fclose(f_in_out);
                return FILE_EMPTY;
            }
        }

        product_r product;
        memset(&product, 0, sizeof(product_r));

        if (entry_struct(&product) == READ_ERROR)
        {
            //printf("Read error");
            return READ_ERROR;
        }

        add_info(f_in_out, product);

        fclose(f_in_out);

        return OK;
    }
    if ((argc == 3) && ((strcmp(argv[1], "at") == 0)))
    {
        FILE *f_in_out;
        f_in_out = fopen(argv[2], "r");

        if (f_in_out == NULL)
        {
            //printf("Open error");
            return OPEN_ERROR;
        }

        product_r products[MAX_COUNT_RECORD];
        memset(&products, 0, sizeof(product_r));

        int len_product = from_file_to_array(f_in_out, products);

        if (len_product == INVALID_ARG)
        {
            //printf("Invalid argument in file\n");
            fclose(f_in_out);
            return INVALID_ARG;
        }

        product_r product;
        memset(&product, 0, sizeof(product_r));

        if (entry_struct(&product) == READ_ERROR)
        {
            //printf("Read error");
            return READ_ERROR;
        }

        fclose(f_in_out);
        f_in_out = fopen(argv[2], "w");
        add_info_txt(products, product, len_product, f_in_out);


        fclose(f_in_out);

        return OK;
    }

    //printf("Not enough argument\n");
    return NOT_ENOUGH_ARG;
}
