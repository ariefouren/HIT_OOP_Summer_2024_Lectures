// File: ArrayWithDefaultValue.h
// definition of template class ArrayWithDefaultValue
#pragma once

#include "Array1.h"
#define DEFAULT_ARRAY_SIZE 5
#define DEFAULT_INT_ARRAY_SIZE 10
#define DEFAULT_INT_VALUE -1

template <class T>
class ArrayWithDefaultValue : public Array<T>
{
    public:
    // constructor
    // create an array of size elements, each initialized to defaultValue
    ArrayWithDefaultValue(int size = DEFAULT_ARRAY_SIZE, 
                            T defaultValue = T()) : 
        Array<T>(size), defaultValue(defaultValue) 
    {
        // fill the array with the default value
        for (int i = 0; i < size; i++)
            (*this)[i] = defaultValue; // call overloaded operator[]
    };
  
private:
    T defaultValue;
};

/*
template <class T>
class ArrayWithDefaultValue : public Array<T>
{
private:
    U defaulValue;
};

template <class T>
class ArrayWithDefaultValue : public Array<U>
{
private:
    T defaulValue;
};

*/


