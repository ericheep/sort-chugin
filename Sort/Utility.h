#pragma once
#include <vector>

using namespace std;


class Utility
{
public:
    Utility();
    ~Utility();

    bool isSorted (vector<float>& v, int size);
    void shuffleVector (vector<float>& v, int size);

    void createEqualizedVector (vector<float>& v, int size);
    void createRandomizedVector (vector<float>& v, int size);
    void createSineSortedVector (vector<float>& v, int size);
    void createReverseSortedVector (vector<float>& v, int size);

private:

};
