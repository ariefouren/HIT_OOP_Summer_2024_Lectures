// 
// Array<T> specialization for char
// 
#ifndef ARRAY2_H
#define ARRAY2_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>   // for isalpha() and tolower()
#include <cassert>
#include "Array1.h"

using namespace std;



class CharArrayIgnoreCase : public Array<char>
{
public:
    CharArrayIgnoreCase(int size = 10) : Array<char>(size) {};

    bool operator==(const Array& right) const
    {
        if (size != right.getSize())
            return false;    // arrays of different sizes

        // compare the characters, ignore the case 
        for (int i = 0; i < size; i++)
            if (tolower((*this)[i]) != tolower(right[i]))
                return false; // arrays are not equal

        return true;        // arrays are equal
    }
};
#endif



