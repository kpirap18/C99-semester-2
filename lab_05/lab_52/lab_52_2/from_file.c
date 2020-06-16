#include "my_utils.h"

int from_file_to_array(FILE *const f, product_r product[])
{
    char s[5];
    int i = 0;
    int rc = 1;
    while (fgets(product[i].name, MAX_LEN_NAME, f) != NULL)
    {
        product[i].name[strlen(product[i].name) - 1] = '\0';
        rc = 0;
        if (fgets(product[i].maker, MAX_LEN_MAKER, f) == NULL)
            return INVALID_ARG;

        product[i].maker[strlen(product[i].maker) - 1] = '\0';

        rc += fscanf(f, "%u", &product[i].price);
        rc += fscanf(f, "%u", &product[i].count);

        if (rc != 2)
            return INVALID_ARG;

        i++;
        fgets(s, 5, f);
    }

    if (i)
        return i;
    else
        return INVALID_ARG;
}
void file_copy_bin(FILE *const f_in_out, FILE *const f_in)
{
    size_t size, i;
    file_size(f_in, &size);

    product_r product;
    memset(&product, 0, sizeof(product_r));

    for (i = 0; i < size; ++i)
    {
        get_student_by_pos(f_in, i, &product);
        fwrite(&product, sizeof(product_r), 1, f_in_out);
    }
}
