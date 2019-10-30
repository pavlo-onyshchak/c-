#pragma once

class Iterator;

struct Node
{
    int key;
    Node* next;
};

class List
{
public:
    List();
    void push_back(const int& val);
    void pop_back();
    Iterator begin();
    Iterator end();
    size_t size();
    bool empty();
    void show();
    static bool test();
private:
    Node* _head = nullptr;
    Node* _end = nullptr;
};