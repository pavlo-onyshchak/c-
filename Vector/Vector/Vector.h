#pragma once
#include <string>
using namespace std;

class Iterator;

class Vector
{
public:
    Vector();
    Vector(initializer_list<int> init);
    void push_back(const int& val);
    void pop_back();
    int front();
    int back();
    Iterator begin();
    Iterator end();
    int size();
    bool empty();
    static bool test();
private:
    int _size;
    int _counter;
    int* _arr;
private:
    void resize();
};
