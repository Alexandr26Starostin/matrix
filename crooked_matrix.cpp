#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "crooked_matrix.h"

static int crooked_matrix_read (int **len_of_line, int **array, int *all_line);
static int crooked_matrix_print (int *array, int *len_of_line, int all_line);

int crooked_matrix ()
{
    int all_line     = 0;
    int *len_of_line = NULL;  //указатель на начало записи всех длин строк
    int *array       = NULL;        //указатель на все числа

    if (crooked_matrix_read (&len_of_line, &array, &all_line))
    {
        return 1;
    }
    printf ("\n\n\n");
    crooked_matrix_print (array, len_of_line, all_line);

    return 0;
}

static int crooked_matrix_read (int ** len_of_line, int **array, int *all_line)
{
    assert (all_line);
    assert (len_of_line);
    assert (array);

    FILE *file;
    file = fopen ("crooked_matrix.txt", "r");     

    if (file == 0)
    {
        printf ("file == 0");
        return 1;
    }

    fscanf (file, "%d", all_line);

    *len_of_line = (int *) calloc (*all_line, sizeof (int));
    if (*len_of_line == 0)
    {
        printf ("len_of_line = 0");
        return 1;
    }

    int sum = 0;

    for (int i = 0; i < *all_line; i++)
    {
        fscanf (file, "%d", *len_of_line + i);
        sum += *(*len_of_line + i);
    }

    *array = (int *) calloc (sum, sizeof(int));
    if (*array == 0)
    {
        printf ("array = 0");
        return 1;
    }

    for (int i = 0; i < sum; i++)
    {
        fscanf (file, "%d", *array + i);
    }
    printf("\n");

    fclose (file); 

    return 0;
}

static int crooked_matrix_print (int *array, int *len_of_line, int all_line)
{
    assert (len_of_line);
    assert (array);

    for (int i = 0; i < all_line; i++)
    {
        for (int k = 0; k < *(len_of_line + i); k++)
        {
            printf ("%3d ", *array);
            array += 1;
        }

        printf ("\n");
    }

    free (array);
    free (len_of_line);

    printf ("\n\n");

    return 0;
}