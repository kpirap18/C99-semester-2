#include "my_utils.h"

void struct_print(product_r p)
{
    printf("%s\n", p.name);
    printf("%s\n", p.maker);
    printf("%u\n", p.price);
    printf("%u\n", p.count);
}
void print_struct_to_file_txt(FILE *const f, product_r s)
{
    fprintf(f, "%s\n", s.name);
    fprintf(f, "%s\n", s.maker);
    fprintf(f, "%u\n", s.price);
    fprintf(f, "%u\n", s.count);
}
void print_file_bin(FILE *const f)
{
    fseek(f, 0L, SEEK_SET);

    product_r product;
    memset(&product, 0, sizeof(product_r));
    size_t n = 0;
    file_size(f, &n);

    for (size_t i = 0; i < n; i++)
    {
        fread(&product, sizeof(product_r), 1, f);
        struct_print(product);
    }
}
