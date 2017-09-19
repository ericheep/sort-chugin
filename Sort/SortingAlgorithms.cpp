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

    while (i < size)
    {
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

void SortingAlgorithms::selectionSort (vector<float>& v, int size, int stepTotal)
{
    // ugen logic
    int steps = 0;

    // sorting logic, straight up wikipedia copy-paste
    // https://en.wikipedia.org/wiki/Selection_sort

    /* a[0] to a[n-1] is the array to sort */
    int i,j;

    /* advance the position through the entire array */
    /*   (could do j < n-1 because single element is also min element) */
    for (j = 0; j < size - 1; j++)
    {
        /* find the min element in the unsorted a[j .. n-1] */

        /* assume the min is the first element */
        int iMin = j;

        /* test against elements after j to find the smallest */
        for (i = j+1; i < size; i++) {
            /* if this element is less, then it is the new minimum */
            if (v[i] < v[iMin]) {
                /* found new minimum; remember its index */
                iMin = i;
            }
        }

        if(iMin != j)
        {
            if (stepsExceeded(steps, stepTotal)) return;
            swap(v[j], v[iMin]);
            steps++;
        }
    }
}

void SortingAlgorithms::bubbleSort (vector<float>& v, int size, int stepTotal)
{
    // ugen logic
    int steps = 0;

    // sorting logic, taken from geeksforgeeks
    // http://www.geeksforgeeks.org/bubble-sort/
    int i, j;
    for (i = 0; i < size - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < size - i - 1; j++) {
            if (v[j] > v[j + 1])
            {
                if (stepsExceeded(steps, stepTotal)) return;
                swap(v[j], v[j+1]);
                steps++;
            }
        }
    }
}
