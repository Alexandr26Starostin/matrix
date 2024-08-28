#include <stdio.h>
#include <assert.h>

#include "matrix_print.h"

void matrix_print (const int *data, size_t vertical, size_t horizontal)
{
    assert (data);
    for (size_t y = 0; y < vertical; y++)
    {
        assert (y <= vertical);
        for (size_t x = 0; x < horizontal; x++)
        {
            assert (x <= horizontal);
            printf ("matrix_1[%d][%d] = %d ", x, y, *(data + horizontal * y + x));
        }
        printf("\n");
    }
    printf ("\n\n\n");
}