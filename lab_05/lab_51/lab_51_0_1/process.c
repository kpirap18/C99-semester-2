#include "process.h"

int process(FILE *f, int *max)
{
    int previos_num = 0, current_num = 0;
    int flag = 0;

    if (fscanf(f, "%d", &previos_num) == 1)
    {
        while (fscanf(f, "%d", &current_num) == 1)
        {
            flag = 1;
            if ((previos_num < 0) && (current_num > 0))
            {
                if (current_num > *max)
                    *max = current_num;
            }

            previos_num = current_num;
        }

        if (flag == 0)
            return INPUT_ERROR;
    }
    else
    {
        return NO_INPUT_DATA;
    }

    return OK;
}
