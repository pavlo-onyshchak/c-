#pragma once
#include <vector>
using namespace std;
class Stack
{
public:
    Stack() = default;
    void push(const int& value);
    void pop();
    size_t size();
    int& top();
    bool empty();
    static bool test();
private:
    vector <int> _vec;
 };
