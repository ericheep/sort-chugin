#include "SortingAlgorithms.h"


SortingAlgorithms::SortingAlgorithms()
{
}

SortingAlgorithms::~SortingAlgorithms()
{
}

bool SortingAlgorithms::stepsExceeded(int steps, int stepTotal)
{
    if (steps > stepTotal) return true;

    return false;
}


void SortingAlgorithms::insertionSort (vector<float>& v, int size, int stepTotal)
{
    // ugen logic
    int steps = 0;

    // sorting logic
    int i = 0;

    while (i < size) {
        int j = i;

        while (j > 0 && v[j - 1] > v[j])
        {
            if (stepsExceeded(steps, stepTotal)) return;

            swap(v[j], v[j - 1]);
            steps++;

            v[j] = v[j - 1];
            j--;
        }

        i++;
    }

    return;
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
