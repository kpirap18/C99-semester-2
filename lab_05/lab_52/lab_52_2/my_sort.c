#include "my_utils.h"

void sort_file_txt(product_r products[], int n)
{
    product_r buf;
    memset(&buf, 0, sizeof(product_r));

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (products[i].price < products[j].price)
            {
                buf = products[i];
                products[i] = products[j];
                products[j] = buf;
            }
            else
            {
                if (products[i].price == products[j].price)
                {
                    if (products[i].count < products[j].count)
                    {
                        buf = products[i];
                        products[i] = products[j];
                        products[j] = buf;
                    }
                }
            }
        }
    }
}
void sort_file_bin(FILE *const fsrc)
{
    size_t i, j, n = 0;
    product_r product_f, product_s;
    memset(&product_f, 0, sizeof(product_r));
    memset(&product_s, 0, sizeof(product_r));

    file_size(fsrc, &n);

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; ++j)
        {
            get_student_by_pos(fsrc, i, &product_f);
            get_student_by_pos(fsrc, j, &product_s);

            if (product_f.price < product_s.price)
            {
                put_student_by_pos(fsrc, i, product_s);
                put_student_by_pos(fsrc, j, product_f);
            }
            else
            {
                if (product_f.price == product_s.price)
                {
                    if (product_f.count < product_s.count)
                    {
                        put_student_by_pos(fsrc, i, product_s);
                        put_student_by_pos(fsrc, j, product_f);
                    }
                }
            }
        }
    }
}

