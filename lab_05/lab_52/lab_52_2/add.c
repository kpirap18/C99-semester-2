#include "my_utils.h"

int entry_struct(product_r *product)
{
    setbuf(stdout, NULL);
    int rc;
    printf("Enter name: ");
    rc = scanf("%s", product->name);
    printf("Enter manufactorer: ");
    rc += scanf("%s", product->maker);
    printf("Enter price: ");
    rc += scanf("%u", &(product->price));
    printf("Enter count: ");
    rc += scanf("%u", &(product->count));

    return (rc == 4) ? OK : READ_ERROR;
}

int add_info(FILE *const f, const product_r product)
{
    size_t size;
    file_size(f, &size);

    int pos = 0;
    product_r prod_add;
    memset(&prod_add, 0, sizeof(product_r));

    for (size_t i = 0; i < size; i++)
    {
        get_student_by_pos(f, pos, &prod_add);

        if ((product.price == prod_add.price && product.count > prod_add.count) || (product.price > prod_add.price))
            break;
        ++pos;
    }

    for (int i = size - 1; i >= pos; i--)
    {
        get_student_by_pos(f, i, &prod_add);
        put_student_by_pos(f, i + 1, prod_add);
    }

    put_student_by_pos(f, pos, product);

    return OK;
}

int add_info_txt(product_r products[], const product_r product, int len, FILE *f)
{
    product_r prod;
    memset(&prod, 0, sizeof(product_r));
    int pos = 0;

    for (int i = 0; i < len; i++)
    {
        if ((product.price == products[i].price && product.count > products[i].count) || (product.price > products[i].price))
            break;
        ++pos;
    }

    for (int i = len - 1; i >= pos; i--)
    {
        prod = products[i];
        products[i] = products[i + 1];
        products[i + 1] = prod;
    }

    products[pos] = product;

    for (int i = 0; i < len + 1; i++)
    {
        print_struct_to_file_txt(f, products[i]);
    }

    return OK;
}
