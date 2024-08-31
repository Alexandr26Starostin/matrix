#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "matrix_ladder.h"

static void ladder_print (int *array, int elements);
static int ladder_read (int **begin_ladder, int *elements);

int write_ladder()
{
    int *begin_ladder = 0;
    int elements = 0;

    if (ladder_read (&begin_ladder, &elements))
    {
        return 1;
    }

    ladder_print (begin_ladder, elements);

    free (begin_ladder);

    printf ("\n\n");

    return 0;
}

void ladder_print (int *array, int elements)
{
    assert(array);

    int max_len_line = 1, len_line = 0;
    for (int i = 0; i < elements; i++)
    {
        printf ("%4d ", *array + i);

        if (max_len_line == ++len_line)
        {
            printf ("\n");

            max_len_line++;
            len_line = 0;
        }
    }
}

static int ladder_read (int **begin_ladder, int *elements)
{
    assert(begin_ladder);
    assert(elements);

    FILE *file;
    file = fopen ("matrix_ladder.txt", "r");
        
    if (file == 0)
    {
        printf ("file = 0");
        return 1;
    }

    fscanf (file, "%d", elements);

    *begin_ladder =  (int *) calloc (*elements, sizeof (int));

    if (*begin_ladder == 0)
    {
        printf ("begin_ladder = 0");
        return 1;
    }

    for (int i = 0; i < *elements; i++) 
    {
        if (fscanf (file, "%d", (*begin_ladder + i)) == EOF)
        {
            printf ("File 'matrix_ladder.txt' not corrective");
            return 1;
        }
    }  

    fclose (file);

    return 0;
}