#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "crooked_matrix_3.h"

static const int SIZE_OF_STRUCT = 1;
static const int SIZE_OF_ARRAY  = 1;

struct ptr_and_len_line 
{
    int  len;
};

static int crooked_matrix_3_read (ptr_and_len_line **ptr_struct, int **ptr_array, int *index_struct);
static void crooked_matrix_3_print (ptr_and_len_line *ptr_struct, int *ptr_array, int index_struct);

int crooked_matrix_3 ()
{
    ptr_and_len_line *ptr_struct   = NULL;
    int              *ptr_array    = NULL; 
    int               index_struct = 0;

    if (crooked_matrix_3_read (&ptr_struct, &ptr_array, &index_struct))
    {
        return 1;
    }

    crooked_matrix_3_print (ptr_struct, ptr_array, index_struct);

    return 0;
}

static int crooked_matrix_3_read (ptr_and_len_line **ptr_struct, int **ptr_array, int *index_struct)
{
    assert (ptr_struct);
    assert (ptr_array);

    FILE *file = fopen ("crooked_matrix_3.txt", "r");

    int c              = 0;
    int index_array    = 0;
    int len_line       = 0;
    int size_of_struct = SIZE_OF_STRUCT;
    int size_of_array  = SIZE_OF_ARRAY;

    *ptr_struct = (ptr_and_len_line *) calloc (size_of_struct, sizeof (ptr_and_len_line));
    if (*ptr_struct == 0)
    {
        printf ("ptr_struct = 0");
        return 1;
    }

    *ptr_array  = (int *) calloc (size_of_array, sizeof (int));
    if (*ptr_array == 0)
    {
        printf ("ptr_array = 0");
        return 1;
    }

    while ((c = getc (file)) != EOF)
    {
        if (c != '\n')
        {
            ungetc (c, file);

            fscanf (file, "%d", *ptr_array + index_array);

            index_array++;
            len_line++;

            if (size_of_array <= index_array)
            {
                size_of_array *= 2;

                *ptr_array = (int *) realloc (*ptr_array, size_of_array * sizeof (int));
                if (*ptr_array == 0)
                {
                    printf ("ptr_array = 0");
                    return 1;
                }
            }
        }
        else
        {
            *(*ptr_struct + *index_struct)  = {.len = len_line};
            *index_struct += 1; 

            len_line = 0;

            if (size_of_struct <= *index_struct)
            {
                size_of_struct *= 2;

                *ptr_struct = (ptr_and_len_line *) realloc (*ptr_struct, size_of_struct * sizeof (ptr_and_len_line));
                if (*ptr_struct == 0)
                {
                    printf ("ptr_struct = 0");
                    return 1;
                }
            }
        }
    }
    *(*ptr_struct + *index_struct) = {.len = len_line};
    *index_struct += 1;

    fclose (file);

    return 0;
}

static void crooked_matrix_3_print (ptr_and_len_line *ptr_struct, int *ptr_array, int index_struct)
{
    for (int i = 0; i < index_struct; i++)
    {
        for (int k = 0; k < (*(ptr_struct + i)).len; k++)
        {
            printf ("%3d ", *(ptr_array + k));
        }
        ptr_array += (*(ptr_struct + i)).len;

        printf ("\n");
    }

    free (ptr_struct);
    free (ptr_array);
}