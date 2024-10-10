#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void merge_2(vector<int>& vector, int l, int m, int r)
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


void merge_sort(vector<int>& vector, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        // Sort first and second halves
        merge_sort(vector, left, mid);
        merge_sort(vector, mid + 1, right);

        // Merge the sorted halves
        merge_2(vector, left, mid, right);
    }
}