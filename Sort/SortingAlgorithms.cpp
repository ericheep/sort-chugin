#include "SortingAlgorithms.h"


SortingAlgorithms::SortingAlgorithms()
{
}

SortingAlgorithms::~SortingAlgorithms()
{
}


void SortingAlgorithms::insertionSort (vector<float>& arr, int n, int& i, int& j)
{
    float value = arr[i];

    while (j > 0 && arr[j - 1] > value)
    {
        arr[j] = arr[j - 1];
        j--;

        return;
    }

    i++;
    j = i;
    arr[j] = value;
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
