#include "my_average.h"

#include "my_average.h"

int max_min_file(FILE *fsrc, int *max_i, int *min_i)
{
    float max, min;
    float element;
    int i = 0;

    int rc = fscanf(fsrc, "%f %f", &max, &min);
    if (rc == 2)
    {
        *max_i = 0;
        *min_i = 1;

        fseek(fsrc, 0L, SEEK_SET);
        while (fscanf(fsrc, "%f", &element) == 1)
        {
            if (element > max)
            {
                max = element;
                *max_i = i;
            }
            else if (element < min)
            {
                min = element;
                *min_i = i;
            }
            i++;
        }
    }
    else
        return INPUT_ERROR;
    return OK;
}
float average(FILE *fsrc, int min_i, int max_i)
{
    int begin = (min_i < max_i) ? min_i : max_i;
    int end = (min_i > max_i) ? min_i : max_i;

    float average_num = 0, element;
    int i = 0;

    while (fscanf(fsrc, "%f", &element) == 1)
    {
        if ((i > begin) && (i < end))
            average_num += element;

        i++;
    }
    average_num = average_num / (float)(end - begin - 1);

    return average_num;
}
