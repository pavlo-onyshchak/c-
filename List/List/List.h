#pragma once
#include <memory>

using namespace std;

class Iterator;

class List
{
private:
    struct Node
    {
        Node(int val) :key(val) {};
        int key;
        shared_ptr<Node> next = nullptr;
    };
public:
    using iterator = Iterator;
    friend class Iterator;
    List();
    void push_back(const int& val);
    void push_front(const int& val);
    void pop_back();
    void pop_front();
    Iterator begin() const;
    Iterator end() const;
    size_t size();
    bool empty() const;
    void show();
    static bool test();
private:
    shared_ptr<Node> _head = nullptr;
    shared_ptr<Node> _end = nullptr;
};
