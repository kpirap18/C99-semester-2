/* Вариант 6.

   Создать три текстовых файла f1, f2, f3, содержащих любую информацию.
   Организовать обмен информацией из этих файлов по схеме f1 -> f2 -> f3 -> f1.
   Содержимое исходных и измененных файлов вывести на экран.
*/
#include "my_utils.h"

int main()
{
    FILE *f1, *f2, *f3;
    f1 = fopen("f1.txt", "r");
    f2 = fopen("f2.txt", "r");
    f3 = fopen("f3.txt", "r");

    if ((f1 == NULL) || (f2 == NULL) || (f3 == NULL))
    {
        printf("Open error f1.txt or f2.txt or f3.txt\n");
        return OPEN_ERROR;
    }

    char str_f[MAX_STR][STR_LEN];
    char str_s[MAX_STR][STR_LEN];
    char str_t[MAX_STR][STR_LEN];

    int count_f = from_file_to_array(f1, str_f);
    int count_s = from_file_to_array(f2, str_s);
    int count_t = from_file_to_array(f3, str_t);

    if ((count_f == INVALID_ARG) || (count_s == INVALID_ARG) || (count_t == INVALID_ARG))
    {
        printf("Invalid argument in f1.txt or f2.txt or f3.txt\n");
        return INVALID_ARG;
    }
    fclose(f1);
    fclose(f2);
    fclose(f3);

    f1 = fopen("f1.txt", "r");
    f2 = fopen("f2.txt", "r");
    f3 = fopen("f3.txt", "r");

    printf("In f1.txt before:\n");
    print_file_to_cons(f1, count_f);
    printf("In f2.txt before:\n");
    print_file_to_cons(f2, count_s);
    printf("In f3.txt before:\n");
    print_file_to_cons(f3, count_t);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    f1 = fopen("f1.txt", "w");
    f2 = fopen("f2.txt", "w");
    f3 = fopen("f3.txt", "w");

    print_array_to_file_txt(f2, str_f, count_f);
    print_array_to_file_txt(f3, str_s, count_s);
    print_array_to_file_txt(f1, str_t, count_t);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    f1 = fopen("f1.txt", "r");
    f2 = fopen("f2.txt", "r");
    f3 = fopen("f3.txt", "r");

    printf("In f1.txt after:\n");
    print_file_to_cons(f1, count_t);
    printf("In f2.txt after:\n");
    print_file_to_cons(f2, count_f);
    printf("In f3.txt after:\n");
    print_file_to_cons(f3, count_s);

    return OK;
}
