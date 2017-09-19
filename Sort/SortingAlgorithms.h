#pragma once

#include <vector>

using namespace std;


class SortingAlgorithms
{
public:
    SortingAlgorithms();
    ~SortingAlgorithms();

    bool stepsExceeded(int steps, int stepTotal);
    void insertionSort(vector<float>& v, int size, int stepTotal);
    void selectionSort(vector<float>& v, int size, int stepTotal);
    void bubbleSort(vector<float>& v, int size, int stepTotal);

private:

};
