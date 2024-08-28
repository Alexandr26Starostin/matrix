#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "write_matrix_from_file.h"

static int matrix_read (int **begin_array_1, int *vertical, int *horizontal);
static void array_print (const int *array, int vertical, int horizontal);

int write_matrix_from_file ()
{
    int *begin_array_1 = 0;
    int vertical = 0, horizontal = 0;

    if (matrix_read(&begin_array_1, &vertical, &horizontal))
    {
        return 1;
    }

    array_print (begin_array_1, vertical, horizontal);

    free (begin_array_1);

    printf("\n\n");

    return 0;
}

void array_print (const int *array, int vertical, int horizontal)
{
    assert (array);
    
    for (int i = 0; i < vertical * horizontal; i++)
    {
        if (i % vertical == 0)
        {
            printf ("\n");
        }

        printf ("%5d ", *(array + i));
    }
}

static int matrix_read (int **begin_array_1, int *vertical, int *horizontal)
{
    assert(begin_array_1);
    assert(vertical);
    assert(horizontal);

    FILE *file;
    file = fopen ("matrix_1.txt", "r");

    if (file == 0)
    {
         printf ("file = 0");
         return 1;
    }

    fscanf (file, "%d %d", vertical, horizontal);

    int scale = *vertical * *horizontal;

    *begin_array_1 =  (int *) calloc (scale, sizeof (int));

    if (*begin_array_1 == 0)
    {
        printf ("begin_array_1 = 0");
        return 1;
    }

    for (int i = 0; i < scale; i++) 
    {
        if (fscanf (file, "%d", (*begin_array_1 + i)) == EOF)
        {
            printf ("File 'matrix_1.txt' not corrective");
            return 1;
        }
    }

    fclose (file);

    return 0;
}