//-----------------------------------------------------------------------------
// Entaro ChucK Developer!
// This is a Chugin boilerplate, generated by chugerate!
//-----------------------------------------------------------------------------

// this should align with the correct versions of these ChucK files
#include "chuck_dl.h"
#include "chuck_def.h"

// general includes
#include <iostream>
#include <math.h>
#include <limits.h>
#include <vector>
#include <stdio.h>

#include "SortingAlgorithms.h"
#include "Utility.h"


CK_DLL_CTOR(sort_ctor);
CK_DLL_DTOR(sort_dtor);

CK_DLL_MFUN(sort_setFreq);
CK_DLL_MFUN(sort_getFreq);
CK_DLL_MFUN(sort_setSize);
CK_DLL_MFUN(sort_getSize);
CK_DLL_MFUN(sort_isSorted);

CK_DLL_MFUN(sort_setReinitialize);
CK_DLL_MFUN(sort_getReinitialize);

CK_DLL_MFUN(sort_setSine);
CK_DLL_MFUN(sort_setEqualize);
CK_DLL_MFUN(sort_setRandom);
CK_DLL_MFUN(sort_setReverse);

CK_DLL_MFUN(sort_setInterpolation);
CK_DLL_MFUN(sort_getInterpolation);
CK_DLL_MFUN(sort_getIteration);
CK_DLL_MFUN(sort_getPosition);

CK_DLL_MFUN(sort_setInsertion);
CK_DLL_MFUN(sort_setSelection);
CK_DLL_MFUN(sort_setBubble);
CK_DLL_MFUN(sort_setShuffle);

CK_DLL_TICK(sort_tick);
t_CKINT sort_data_offset = 0;

using namespace std;


class Sort
{
public:
    Sort (t_CKFLOAT fs)
    {
        samplingFrequency = fs;

        freq = 0.0;
        size = 0;
        sorted = false;

        position = 0;
        interpolation = 0;

        reinitialize = true;

        stepTotal = 0;

        sortingType = INSERTION;
        initialShape = RANDOM;

        // populates the vector
        setFreq(220.0);

        initializeSamples();
    }

    float setFreq (t_CKFLOAT f)
    {
        freq = f;
        setSize(int(samplingFrequency/f));

        return freq;
    }

    float getFreq()
    {
        return freq;
    }

    int setSize (t_CKINT s)
    {
        size = s;
        samples.resize(s);
        initializeSamples();

        return size;
    }

    int getSize()
    {
        return size;
    }

    int isSorted()
    {
        if (sorted) {
            return 1;
        } else {
            return 0;
        }
    }

    int setInterpolation (t_CKINT i)
    {
        interpolation = i;
        return interpolation;
    }

    int getInterpolation()
    {
        return interpolation;
    }

    int setReinitialize(t_CKINT r)
    {
        if (r == 1) {
            reinitialize = true;
        } else {
            reinitialize = false;
        }
        return r;
    }

    int getReinitialize()
    {
        if (reinitialize) {
            return 1;
        }
        return 0;
    }

    float getPosition()
    {
        return position;
    }

    void setEqualize()
    {
        initialShape = EQUALIZE;
    }

    void setRandom()
    {
        initialShape = RANDOM;
    }

    void setSine()
    {
        initialShape = SINE;
    }

    void setReverse()
    {
        initialShape = REVERSE;
    }

    void initializeSamples()
    {
        switch(initialShape)
        {
        case RANDOM:
            util.randomizeVector(samples, size);
            break;
        case EQUALIZE:
            util.equalizeVector(samples, size);
            break;
        case SINE:
            util.sineSortVector(samples, size);
            break;
        case REVERSE:
            util.reverseSortVector(samples, size);
            break;

        default:
            break;
        }
    }

    void sort(int& stepTotal)
    {
        switch(sortingType)
        {
        case INSERTION:
            algorithms.insertionSort(samples, size, stepTotal);
            break;
        case SELECTION:
            algorithms.selectionSort(samples, size, stepTotal);
            break;
        case BUBBLE:
            algorithms.bubbleSort(samples, size, stepTotal);
            break;
        case SHUFFLE:
            util.shuffleVector(samples, size);
            stepTotal = 0;
            break;
        default:
            break;
        }
    }

    void setInsertion()
    {
        sortingType = INSERTION;
    }

    void setSelection()
    {
        sortingType = SELECTION;
    }

    void setBubble()
    {
        sortingType = BUBBLE;
    }

    void setShuffle()
    {
        sortingType = SHUFFLE;
    }

    int getIteration()
    {
        return stepTotal;
    }

    SAMPLE tick (SAMPLE in)
    {
        position++;

        if (position > size) {
            position = 0;
        }

        if (position == 0) {
            if (util.isSorted(samples, size)) {
                sorted = true;
                if (reinitialize) {
                    initializeSamples();
                }
                stepTotal = 0;
            }
            else {
                sorted = false;
            }

            sort(stepTotal);
            stepTotal++;
        }


        return samples[position];
    }


private:
    float freq;
    float samplingFrequency;

    int size;
    int position;
    int interpolation;

    int stepTotal;

    bool sorted;

    vector<float> samples;

    enum InitialShape
    {
        RANDOM = 0,
        EQUALIZE,
        SINE,
        REVERSE
    };

    bool reinitialize;

    enum SortingTypes
    {
        INSERTION = 0,
        SELECTION,
        BUBBLE,
        SHUFFLE
    };

    // enums
    InitialShape initialShape;
    SortingTypes sortingType;

    // classes
    SortingAlgorithms algorithms;
    Utility util;
};


CK_DLL_QUERY( Sort )
{
    // hmm, don't change this...
    QUERY->setname(QUERY, "Sort");
    QUERY->begin_class(QUERY, "Sort", "UGen");

    // register the constructor/deconstructor (probably no need to change)
    QUERY->add_ctor(QUERY, sort_ctor);
    QUERY->add_dtor(QUERY, sort_dtor);

    // for UGen's only: add tick function
    QUERY->add_ugen_func(QUERY, sort_tick, NULL, 1, 1);

    QUERY->add_mfun(QUERY, sort_setFreq, "float", "freq");
    QUERY->add_arg(QUERY, "float", "arg");
    QUERY->add_mfun(QUERY, sort_getFreq, "float", "freq");

    QUERY->add_mfun(QUERY, sort_isSorted, "int", "sorted");

    QUERY->add_mfun(QUERY, sort_setEqualize, "void", "setEqualize");
    QUERY->add_mfun(QUERY, sort_setRandom, "void", "setRandom");
    QUERY->add_mfun(QUERY, sort_setSine, "void", "setSine");
    QUERY->add_mfun(QUERY, sort_setReverse, "void", "setReverse");

    QUERY->add_mfun(QUERY, sort_setReinitialize, "int", "setReinitialize");
    QUERY->add_arg(QUERY, "int", "arg");
    QUERY->add_mfun(QUERY, sort_getReinitialize, "int", "getReinitialize");

    QUERY->add_mfun(QUERY, sort_setInterpolation, "int", "interpolation");
    QUERY->add_arg(QUERY, "int", "arg");
    QUERY->add_mfun(QUERY, sort_getInterpolation, "int", "interpolation");

    QUERY->add_mfun(QUERY, sort_getIteration, "int", "iteration");

    QUERY->add_mfun(QUERY, sort_getPosition, "int", "position");

    QUERY->add_mfun(QUERY, sort_setSize, "int", "size");
    QUERY->add_arg(QUERY, "int", "arg");
    QUERY->add_mfun(QUERY, sort_getSize, "int", "size");

    QUERY->add_mfun(QUERY, sort_setInsertion, "void", "setInsertion");
    QUERY->add_mfun(QUERY, sort_setSelection, "void", "setSelection");
    QUERY->add_mfun(QUERY, sort_setBubble, "void", "setBubble");
    QUERY->add_mfun(QUERY, sort_setShuffle, "void", "setShuffle");

    // this reserves a variable in the ChucK internal class to store
    // referene to the c++ class we defined above
    sort_data_offset = QUERY->add_mvar(QUERY, "int", "@s_data", false);

    // end the class definition
    // IMPORTANT: this MUST be called!
    QUERY->end_class(QUERY);

    // wasn't that a breeze?
    return TRUE;
}


// implementation for the constructor
CK_DLL_CTOR(sort_ctor)
{
    // get the offset where we'll store our internal c++ class pointer
    OBJ_MEMBER_INT(SELF, sort_data_offset) = 0;

    // instantiate our internal c++ class representation
    Sort * s_obj = new Sort(API->vm->get_srate());

    // store the pointer in the ChucK object member
    OBJ_MEMBER_INT(SELF, sort_data_offset) = (t_CKINT) s_obj;
}


// implementation for the destructor
CK_DLL_DTOR(sort_dtor)
{
    // get our c++ class pointer
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    // check it
    if( s_obj )
    {
        // clean up
        delete s_obj;
        OBJ_MEMBER_INT(SELF, sort_data_offset) = 0;
        s_obj = NULL;
    }
}


// implementation for tick function
CK_DLL_TICK(sort_tick)
{
    // get our c++ class pointer
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);

    // invoke our tick function; store in the magical out variable
    if(s_obj) *out = s_obj->tick(in);

    // yes
    return TRUE;
}

CK_DLL_MFUN(sort_setFreq)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_float = s_obj->setFreq(GET_NEXT_FLOAT(ARGS));
}


CK_DLL_MFUN(sort_getFreq)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_float = s_obj->getFreq();
}

CK_DLL_MFUN(sort_setSize)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_int = s_obj->setSize(GET_NEXT_INT(ARGS));
}

CK_DLL_MFUN(sort_getSize)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_int= s_obj->getSize();
}

CK_DLL_MFUN(sort_isSorted)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_int= s_obj->isSorted();
}

CK_DLL_MFUN(sort_setReinitialize)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_int = s_obj->setReinitialize(GET_NEXT_INT(ARGS));
}

CK_DLL_MFUN(sort_getReinitialize)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_int = s_obj->getReinitialize();
}

CK_DLL_MFUN(sort_setSine)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    s_obj->setSine();
}

CK_DLL_MFUN(sort_setRandom)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    s_obj->setRandom();
}

CK_DLL_MFUN(sort_setEqualize)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    s_obj->setEqualize();
}

CK_DLL_MFUN(sort_setReverse)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    s_obj->setReverse();
}

CK_DLL_MFUN(sort_setInterpolation)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_int = s_obj->setInterpolation(GET_NEXT_INT(ARGS));
}

CK_DLL_MFUN(sort_getInterpolation)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_int = s_obj->getInterpolation();
}

CK_DLL_MFUN(sort_getIteration)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_int = s_obj->getIteration();
}

CK_DLL_MFUN(sort_getPosition)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    RETURN->v_int = s_obj->getPosition();
}

CK_DLL_MFUN(sort_setInsertion)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    s_obj->setInsertion();
}

CK_DLL_MFUN(sort_setSelection)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    s_obj->setSelection();
}

CK_DLL_MFUN(sort_setBubble)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    s_obj->setBubble();
}

CK_DLL_MFUN(sort_setShuffle)
{
    Sort * s_obj = (Sort *) OBJ_MEMBER_INT(SELF, sort_data_offset);
    s_obj->setShuffle();
}
