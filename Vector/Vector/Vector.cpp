#include <iostream>
#include <vector>
#include "Vector.h"
#include "Iterator.h"
using namespace std;

Vector::Vector()
{
    _size = 10;
    _counter = 0;
    _arr = new int[_size];
    _arr[_counter] = 0;
    _counter++;
}

Vector::Vector(initializer_list<int> init)
{
    _size = 10;
    _counter = 0;
    _arr = new int[_size];
    _arr[_counter] = 0;
    _counter++;
    for (auto it = init.begin(); it != init.end(); it++)
    {
        push_back(*it);
    }
}

void Vector::push_back(const int& val)
{
    if (_counter == _size - 1)
    {
        resize();
    }
    _arr[_counter - 1] = val;
    _arr[_counter] = 0;
    _counter++;
}

void Vector::pop_back()
{
    _counter--;
}

int Vector::front()
{
    return _arr[0];
}

int Vector::back()
{
    if (_counter < 2)
    {
        return 0;
    }
    return _arr[_counter - 2]; //because _counter -1 is end(),and i dont know how to do it better;
}

Iterator Vector::begin()
{
    return Iterator(_arr);
}

Iterator Vector::end()
{
    return Iterator(_arr + _counter -1);
}

int Vector::size()
{
    if (!_counter)
    {
        return 0;
    }
   return _counter - 1;
}

bool Vector::empty()
{
    return size() == 0;
}

void Vector::resize()
{
    _size *= 2;
    auto tmp = new int[_size];
    copy(_arr, _arr + _size, tmp);
    delete[] _arr;
    _arr = tmp;
}

bool Vector::test()
{
    auto my_vec = Vector{ 11,12,13,14 };
    vector<int> stl_vec = { 11,12,13,14 };
    for (auto i = 0; i < stl_vec.size(); i++)
    {
        if (*my_vec.begin() != *stl_vec.begin())
        {
            throw exception("begin() is incorrect");
        }
        if (my_vec.front() != stl_vec.front())
        {
            throw exception("front() is incorrect");
        }
        if (my_vec.back() != stl_vec.back())
        {
            throw exception("back() is incorrect");
        }
        if (my_vec.size() != stl_vec.size())
        {
            throw exception("size() is incorrect");
        }
        if (my_vec.empty() != stl_vec.empty())
        {
            throw exception("empty() is incorrect");
        }
        my_vec.pop_back();
        stl_vec.pop_back();
    }
    return true;
}
