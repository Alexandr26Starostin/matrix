#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "crooked_matrix_2.h"

static int crooked_matrix_2_read (int **len_of_line, int **array, int *index_of_line, int *index_of_array);
static void crooked_matrix_2_print (int *len_of_line, int *array, int index_of_line);

int crooked_matrix_2 ()
{
    int *len_of_line     = NULL; //указатель на длины всех строк
    int *array           = NULL; //указатель на все числа
    int index_of_array   = 0;    //количество всех чисел
    int index_of_line    = 0;    //количество строк

    if (crooked_matrix_2_read (&len_of_line, &array, &index_of_line, &index_of_array))
    {
        return 1;
    }

    crooked_matrix_2_print (len_of_line, array, index_of_line);

    return 0;
}

static int crooked_matrix_2_read (int **len_of_line, int **array, int *index_of_line, int *index_of_array)
{
    assert (len_of_line);
    assert (array);
    assert (index_of_line);
    assert (index_of_array);

    FILE *file;
    file = fopen ("crooked_matrix_2.txt", "r");     //! В конце каждой строки должен быть именно '\n', а не ' '. 
    if (file == 0)
    {
        printf ("file == 0");
        return 1;
    }

    int c                = 0;
    int number_of_symbol = 0;
    
    int size_array = 16;
    int size_line =  4;

    *len_of_line = (int *) calloc (size_line, sizeof (int));
    if (*len_of_line == 0)
    {
        printf ("len_of_line = 0");
        return 1;
    }

    *array = (int *) calloc (size_array, sizeof(int));
    if (*array == 0)
    {
        printf ("array = 0");
        return 1;
    }

    while ((c = getc (file)) != EOF)
    {
        if (c != '\n')
        {
            ungetc (c, file);

            fscanf (file, "%d", *array + *index_of_array);

            *index_of_array += 1;
            number_of_symbol++;
            
            if (*index_of_array % size_array == 0)
                {
                    size_array *= 2;

                    *array = (int *) realloc (*array, size_array * sizeof (int));
                    if (*array == 0)
                    {
                        printf ("array_from_realloc = 0");
                    }
                }
        }
        else
        {
            *(*len_of_line + *index_of_line) = number_of_symbol;  


            number_of_symbol = 0;
            *index_of_line += 1;

            if (*index_of_line % size_line == 0)
            {
                size_line *= 2;

                *len_of_line = (int *) realloc (*len_of_line, size_line * sizeof (int));
                if (*len_of_line == 0)
                {
                    printf ("len_of_line = 0");
                }
            }
        }
    }
    if (number_of_symbol != 0)
    {
        *(*len_of_line + *index_of_line) = number_of_symbol;
    }

    fclose (file);

    return 0;
}

static void crooked_matrix_2_print (int *len_of_line, int *array,  int index_of_line)
{
    assert (len_of_line);
    assert (array);

    for (int i = 0; i < index_of_line + 1; i++)
    {
        for (int k = 0; k < *(len_of_line + i); k++)
        {
            printf ("%3d ", *array);
            array += 1;
        }

        printf("\n");
    }

    free (array);
    free (len_of_line);

    printf("\n\n");
}

