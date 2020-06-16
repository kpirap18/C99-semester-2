#include "my_average.h"

int main(int argc, char **argv)
{
    FILE *fsrc;
    int result;

    int min_i = 0, max_i = 0;

    fsrc = fopen(argv[1], "r");
    if (argc != 2)
    {
        printf("main.exe <source file>\n");

        result = NOT_ENOUGH_ARG;
    }
    else
    {
        if (fsrc == NULL)
        {
            fprintf(stderr, "Could not open %s because of %s\n", argv[1], strerror(errno));

            result = OPEN_ERROR;
        }
        else
        {
            result = max_min_file(fsrc, &max_i, &min_i);
            
            if ((result) || (abs(min_i - max_i) - 1 == 0))
                fprintf(stderr, "Input error\n");
            else
            {
                fseek(fsrc, 0L, SEEK_SET);
                float average_ = average(fsrc, min_i, max_i);
                fclose(fsrc);
                printf("Average: %f", average_);
            }
        }
    }

    return result;
}