#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

void insertion_sort(vector<int> &vector, int anterior, int upper_boundry)
{
    for (int i = anterior + 1; i <= upper_boundry; i++)
    {
        int temp = vector[i];
        int j = i - 1;

        while (j >= anterior && vector[j] > temp)
        {
            vector[j + 1] = vector[j];
            j--;
        }
        vector[j + 1] = temp;
    }
}

void merge(vector<int> &vector, int l, int m, int r)
{
    int subarray1 = m - l + 1;
    int subarray2 = r - m;
    std::vector<int> temp_vector_left(subarray1);
    std::vector<int> temp_vector_right(subarray2);

    for (int i = 0; i < subarray1; i++)
    {
        temp_vector_left[i] = vector[l + i];
    }
    // aqui se copia a los vectores temporales los valores del vector principal
    for (int i = 0; i < subarray2; i++)
    {
        temp_vector_right[i] = vector[m + 1 + i];
    }

    int left_index = 0;
    int right_index = 0;
    int merge_index = l;

    while (left_index < subarray1 && right_index < subarray2)
    {
        if (temp_vector_left[left_index] <= temp_vector_right[right_index])
        {
            vector[merge_index] = temp_vector_left[left_index];
            left_index++;
        }
        else
        {
            vector[merge_index] = temp_vector_right[right_index];
            right_index++;
        }
        merge_index++;
    }

    while (left_index < subarray1)
    {
        vector[merge_index] = temp_vector_left[left_index];
        left_index++;
        merge_index++;
    }

    while (right_index < subarray2)
    {
        vector[merge_index] = temp_vector_right[right_index];
        right_index++;
        merge_index++;
    }
}

void tim_sort(vector<int> &set, int size)
{
    int subarray_lenght = 10;
    int upper_boundry = 0;
    for (int i = 0; i < size; i += subarray_lenght)
    {
        if ((i + subarray_lenght - 1) > (size - 1))
        {
            upper_boundry = i + subarray_lenght - 1;
        }
        else
        {
            upper_boundry = size - 1;
        }

        insertion_sort(set, i, upper_boundry);
    }

    for (int segment_size = 10; segment_size < size; segment_size = 2 * segment_size)
    {
        for (int left = 0; left < size; left += 2 * segment_size)
        {
            int mid = left + segment_size - 1;
            int right = min((left + 2 * segment_size - 1), (size - 1));

            if (mid < right)
            {
                merge(set, left, mid, right);
            }
        }
    }
}
