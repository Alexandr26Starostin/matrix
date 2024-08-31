#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "matrix_const.h"
#include "matrix_print.h"
#include "matrix_sum.h"
#include "write_matrix_from_file.h"
#include "matrix_ladder.h"
#include "crooked_matrix.h"
#include "crooked_matrix_2.h"
#include "crooked_matrix_3.h"

int main()
{
    int matrix_3[5][7] = {};

    size_t vertical = sizeof (matrix_1) / sizeof (matrix_1[0]);
    size_t horizontal = sizeof (matrix_1[0]) / sizeof (matrix_1[0][0]);

    matrix_print (*matrix_1, vertical, horizontal);
    matrix_print (*matrix_2, vertical, horizontal);
    matrix_sum   (*matrix_1, *matrix_2, *matrix_3, vertical, horizontal);
    matrix_print (*matrix_3, vertical, horizontal);
    

    if (write_matrix_from_file ())
    {
        return 1;
    }

    if (write_ladder())
    {
        return 2;
    }

    if (crooked_matrix ())
    {
        return 3;
    }

    if (crooked_matrix_2 ())
    {
        return 4;
    }

    if (crooked_matrix_3 ())
    {
        return 5;
    }

    return 0;
}