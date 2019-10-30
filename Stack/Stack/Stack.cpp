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
   return _vec.back();
}

bool Stack::empty()
{
    return _vec.empty();
}

bool Stack::test()
{
    stack <int> stl_stack;
    stl_stack.push(10);
    stl_stack.push(12);
    stl_stack.push(20);
    Stack my_stack;
    my_stack.push(10);
    my_stack.push(12);
    my_stack.push(20);

    for (int i = 0; i < stl_stack.size(); i++)
    {
        if (stl_stack.top() != my_stack.top())
        {
            throw exception("top function is invalid");
        }

        if (stl_stack.size() != my_stack.size())
        {
            throw exception("size function is invalid");
        }

        if (stl_stack.empty() != my_stack.empty())
        {
            throw exception("empty function is invalid");
        }

        stl_stack.pop();
        my_stack.pop();
    }

    return true;
}
