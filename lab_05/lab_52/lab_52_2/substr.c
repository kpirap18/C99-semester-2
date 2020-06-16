#include "my_utils.h"

int check_substr(char *name, const char *substr)
{
    int len_name = strlen(name) - 1;
    int len_substr = strlen(substr) - 1;

    while (len_substr >= 0)
    {
        if (name[len_name] != substr[len_substr])
            return 1;

        len_substr--;
        len_name--;
    }

    return OK;
}
int surname_substr_bin(FILE *const f_in, const char *substr)
{
    size_t size, i;
    product_r product;
    memset(&product, 0, sizeof(product_r));
    file_size(f_in, &size);

    int count_substr = 0;

    for (i = 0; i < size; ++i)
    {
        get_student_by_pos(f_in, i, &product);
        if (check_substr(product.name, substr) == OK)
        {
            count_substr++;
            struct_print(product);
        }
    }
    if (count_substr == 0)
        return NO_MATCHES;

    return OK;
}

int surname_substr_txt(product_r products[], int n, const char *substr)
{
    int count_substr = 0;
    for (int i = 0; i < n; i++)
    {
        if (check_substr(products[i].name, substr) == OK)
        {
            count_substr++;
            struct_print(products[i]);
        }
    }

    return count_substr;
}
