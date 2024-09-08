// 
// File: CharArrayIgnoreCase.h
// definition of not-template class CharArrayIgnoreCase
// that inherits from specialization Array<char> of template class Array
#pragma once

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>   // for isalpha() and tolower()
#include <cassert>
#include "Array1.h"

using namespace std;

#define DEFAULT_CHAR_ARRAY_SIZE 10

// regular (non-template) class can't inherit from template class:
// class CharArrayIgnoreCase : public Array<T>; // error !!!

// regular class can inherit from specialization of template class:
// class CharArrayIgnoreCase inherits 
// from specialization Array<char> of template class Array
// CharArrayIgnoreCase overrides operator== to compare
// the characters of the arrays ignoring the case
class CharArrayIgnoreCase : public Array<char>
{
public:
    CharArrayIgnoreCase(int size = DEFAULT_CHAR_ARRAY_SIZE) : 
            Array<char>(size) {};
    bool operator==(const Array& right) const
    {
        if (this->getSize() != right.getSize())
            return false;    // arrays of different sizes

        // compare the characters, ignore the case 
        for (int i = 0; i < this->getSize(); i++)
            if (tolower((*this)[i]) != tolower(right[i]))
                return false; // arrays are not equal

        return true;        // arrays are equal
    }
};




