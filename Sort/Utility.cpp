#include "Utility.h"
#include <cmath>


Utility::Utility()
{
}

Utility::~Utility()
{
}

bool Utility::isSorted(vector<float>& v, int size) {
    for (int i = 0; i < size - 1; i++)
    {
        if (v[i] > v[i + 1]) {
            return false;
        }
    }

    return true;
}

void Utility::shuffleVector (vector<float>& v, int size)
{
    int j;
    float tmp;

    for (int i = size - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        tmp = v[j];
        v[j] = v[i];
        v[i] = tmp;
    }
}

void Utility::createEqualizedVector (vector<float>& v, int size)
{
    for (int i = 0; i < size; i++)
    {
        v[i] = (i * (1.0/size)) * 2.0 - 1.0;
    }

    shuffleVector(v, size);
}

void Utility::createRandomizedVector (vector<float>& v, int size)
{
    for (int i = 0; i < size; i++) {
        v[i] = ((double) rand() / RAND_MAX) * 2.0 - 1.0;
    }
}

void Utility::createSineSortedVector (vector<float>& v, int size)
{
    for (int i = 0; i < size; i++) {
        v[i] = sin((i * (1.0/size)) * (M_PI * 2.0));
    }
}

void Utility::createReverseSortedVector (vector<float>& v, int size)
{
    for (int i = 0; i < size; i++) {
        v[i] = (1.0 - i * (1.0/size)) * 2.0 - 1.0;
    }
}
