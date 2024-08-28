#include <stdio.h>
#include <assert.h>

#include "matrix_sum.h"

void  matrix_sum (const int *data_1, const int *data_2,  int *data_3, size_t vertical, size_t horizontal)
{
    assert (data_1);
    assert (data_2);
    assert (data_3);

    for (size_t y = 0; y < vertical; y++)
    {
        assert (y <= vertical);
        for (size_t x = 0; x < horizontal; x++)
        {
            assert (x <= horizontal);

           *(data_3 + horizontal * y + x) = *(data_1 + horizontal * y + x) + *(data_2 + horizontal * y + x);
        }
    }
    printf ("\n\n\n");
}