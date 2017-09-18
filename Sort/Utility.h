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

    void randomizeVector (vector<float>& v, int size);
    void equalizeVector (vector<float>& v, int size);
    void sineSortVector (vector<float>& v, int size);
    void reverseSortVector (vector<float>& v, int size);

private:

};
