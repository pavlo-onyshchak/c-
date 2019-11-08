#include "Iterator.h"

Iterator::Iterator(int* arr) : ptr(arr) {}

int Iterator::operator*()
{
    return *ptr;
}

bool Iterator::operator==(Iterator& it)
{
    return this->ptr == it.ptr;
}

bool Iterator::operator!=(Iterator& it)
{
    return this->ptr != it.ptr;
}

Iterator Iterator::operator++(int)
{
    Iterator it = this->ptr;
    this->ptr += 1;
    return it;
}
