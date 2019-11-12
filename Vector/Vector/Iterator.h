#pragma once
class Iterator
{
public:
    Iterator(int* arr);
    int operator*();
    bool operator==(Iterator& it);
    bool operator!=(Iterator& it);
    Iterator operator++(int);
private:
    int* ptr;
};
