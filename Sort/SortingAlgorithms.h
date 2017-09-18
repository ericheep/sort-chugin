#pragma once

#include <vector>

using namespace std;


class SortingAlgorithms
{
public:
    SortingAlgorithms();
    ~SortingAlgorithms();

    bool stepsExceeded(int steps, int stepTotal);
    void insertionSort(vector<float>& arr, int size, int stepTotal);
    // void selectionSort(vector<float>& arr, int n, int step);
    // void bubbleSort(vector<float>& arr, int n, int step);

private:

};
