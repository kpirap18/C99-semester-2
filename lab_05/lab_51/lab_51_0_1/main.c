#include "process.h"

#define LOGIC_ERROR -3

int main()
{
    setbuf(stdout, NULL);
    FILE *f = stdin;
    int max = 0;

    printf("Input integers: ");
    int result = process(f, &max);

    if (result == NO_INPUT_DATA)
        fprintf(stdout, "No input data");
    else if (result == INPUT_ERROR)
        fprintf(stdout, "Input error");
    else if (max)
        fprintf(stdout, "Max positive after negative: %d", max);
    else
    {
        fprintf(stdout, "Logic error");
        result = LOGIC_ERROR;
    }
    return result;
}
