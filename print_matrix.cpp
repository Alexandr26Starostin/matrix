#include <TXLib.h>

#include "list_of_matrix.h"

void matrix_print (int *data, size_t vertical, size_t horizontal);       
void matrix_sum (int *data_1, int *data_2, int *data_3, size_t vertical, size_t horizontal);

int main()
{
    int matrix_1[][7] = { 
                {11, 12, 13, 14, 15, 16, 17},
                {21, 22, 23, 24, 25, 26, 27},
                {31, 32, 33, 34, 35, 36, 37},
                {41, 42, 43, 44, 45, 46, 47},
                {51, 52, 53, 54, 55, 56, 57}
              };
    
    int matrix_2[][7] = {
                {-12, -1, 0, 34, 78, 91, 30},
                {-12, -1, 0, 34, 78, 91, 30},
                {-12, -1, 0, 34, 78, 91, 30},
                {-12, -1, 0, 34, 78, 91, 30},
                {-12, -1, 0, 34, 78, 91, 30},
              };
    
    int matrix_3[][7] = {
                {-12, -1, 0, 34, 78, 91, 30},
                {-12, -1, 0, 34, 78, 91, 30},
                {-12, -1, 0, 34, 78, 91, 30},
                {-12, -1, 0, 34, 78, 91, 30},
                {-12, -1, 0, 34, 78, 91, 30},
              };

    size_t vertical = sizeof(matrix_1) / sizeof (matrix_1[0]);
    size_t horizontal = sizeof(matrix_1[0]) / sizeof (matrix_1[0][0]);

    matrix_print (*matrix_1, vertical, horizontal);
    printf("\n\n\n");

    matrix_print (*matrix_2, vertical, horizontal);
    printf("\n\n\n");

    matrix_sum (*matrix_1, *matrix_2, *matrix_3, vertical, horizontal);

    matrix_print (*matrix_3, vertical, horizontal);

    return 0;
}

void matrix_print (int *data, size_t vertical, size_t horizontal)
{
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
}

void matrix_sum (int *data_1, int *data_2, int *data_3, size_t vertical, size_t horizontal)
{
    for (size_t y = 0; y < vertical; y++)
    {
        assert (y <= vertical);
        for (size_t x = 0; x < horizontal; x++)
        {
            assert (x <= horizontal);

           *(data_3 + horizontal * y + x) = *(data_1 + horizontal * y + x) + *(data_2 + horizontal * y + x);
        }
    }
}