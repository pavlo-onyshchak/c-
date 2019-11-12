#include "Stack.h"
#include <stack>
using namespace std;


void Stack::push(const int& value)
{
    _vec.push_back(value);
}

void Stack::pop()
{
    _vec.pop_back();
}

size_t Stack::size()
{
    return _vec.size();
}

int& Stack::top()
{
    return _vec[_vec.size() - 1];
}

bool Stack::empty()
{
    if (!_vec.size())
    {
        return true;
    }
    return false;
}

bool Stack::test()
{
    stack <int> stl_stack;
    stl_stack.push(10);
    stl_stack.push(12);

    this->push(10);
    this->push(12);

    if (stl_stack.top() != this->top())
    {
        throw exception("top function is invalid");
    }

    if (stl_stack.size() != this->size())
    {
        throw exception("size function is invalid");
    }

    if (stl_stack.empty() != this->empty())
    {
        throw exception("empty function is invalid");
    }

    stl_stack.pop();
    this->pop();
    if ((stl_stack.top() != this->top()) || (stl_stack.size() != this->size()))
    {
        throw exception("pop function is invalid");
    }

    return true;
}
