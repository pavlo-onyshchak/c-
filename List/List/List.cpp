#include "List.h"
#include "Iterator.h"
#include <iostream>
#include <list>

using namespace std;

List::List()
{
    auto node = make_shared<Node>(0);
    _end = node;
}

void List::push_back(const int& val)
{
    if (_head == nullptr)
    {
        auto node = make_shared<Node>(val);
        node->next = _end;
       _head = node;
    }
    else 
    {
        auto node = make_shared<Node>(val);
        auto it = _head;
        while (it->next != _end)
        {
            it = it->next;
        }
        it->next = node;
        node->next = _end;
     }
}

void List::push_front(const int& val)
{
    if (_head == nullptr)
    {
        auto node = make_shared<Node>(val);
        node->next = _end;
        _head = node;
    }
    else
    {
        auto node = make_shared<Node>(val);
        auto it = _head;
        _head = node;
        node->next = it;
    }
}

void List::pop_back()
{
    auto ptr = _head;
    if (this->size() == 1)
    {
        _head.reset();
        return;
    }
    while (ptr->next->next != _end)
    {
        ptr = ptr->next;
    }
    ptr->next = _end;
}

void List::pop_front()
{
    if (this->size() == 1)
    {
        _head.reset();
        return;
    }
    _head = _head->next;
}

Iterator List::begin() const
{
    return { _head.get() };
}

Iterator List::end() const
{
    return { _end.get() };
}


size_t List::size()
{
    auto size = 0;
    auto ptr = _head;
    if (ptr == nullptr)
    {
        return 0;
    }
    while (ptr != _end)
    {
        size++;
        ptr = ptr->next;
    }
    return size;
}

bool List::empty() const
{
    return _head == nullptr;
}

void List::show()
{
    for (auto it = _head; it != _end; it = it->next)
    {
        cout << it->key << endl;
    }
}

bool List::test()
{
    List my_list;
    list <int> stl_list;
    my_list.push_back(11);
    my_list.push_back(20);
    my_list.push_back(30);

    stl_list.push_back(11);
    stl_list.push_back(20);
    stl_list.push_back(30);
    auto my_begin = my_list.begin();
    auto stl_begin = stl_list.begin();
    if (*my_begin != *stl_begin)
    {
        throw exception("Invalid begin) function");
    }
   
    for (int i = 0; i < 3; i++)
    {
        if (stl_list.size() != my_list.size())
        {
            throw exception("Invalid size");
        }
        stl_list.pop_back();
        my_list.pop_back();
    }

    if (my_list.empty() != stl_list.empty())
    {
        throw exception("Invalid empty() function");
    }

    return true;
}
