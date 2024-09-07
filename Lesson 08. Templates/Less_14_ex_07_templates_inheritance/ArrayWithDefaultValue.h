#pragma once
// class CharArrayIgnoreCase : public Array<T>; // error !!!


template <class T>
class ArrayWithDefaultValue : public Array<T>
{
private:
    T defaulValue;
};

template <>
class Array<int> : public Array<double> {
private: 
    int defaultValue = -1;
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


