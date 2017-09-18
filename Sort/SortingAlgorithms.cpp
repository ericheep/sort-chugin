#include "SortingAlgorithms.h"


SortingAlgorithms::SortingAlgorithms()
{
}

SortingAlgorithms::~SortingAlgorithms()
{
}


void SortingAlgorithms::insertionSort (vector<float>& v, int size, int& i, int& j)
{
    if (i < size) {
        float value = v[i];

        while (j > 0 && v[j - 1] > value)
        {
            v[j] = v[j - 1];
            j--;

            return;
        }

        i++;
        j = i;
        v[j] = value;
     }
}

/*
void SortingAlgorithms::selectionSort (vector<float>& arr, int n, int step)
{
    int i = step;
    int min = i;

    for (int j = i + 1; j < n; j++)
    {
        if (arr[j] < arr[min])
        {
            min = j;
        }
    }

    swap(arr[min], arr[i]);
}

void SortingAlgorithms::bubbleSort (vector<float>& arr, int n, int step)
{
    int i = step;

    for (int j = 0; j < n - 1 - i; j++) {
        if (arr[j] > arr[j + 1])
        {
            swap(arr[j], arr[j + 1]);
        }
        return;
    }
}
*/
