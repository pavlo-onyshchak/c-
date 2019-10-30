#include "List.h"
#include "Iterator.h"
#include <iostream>
#include <list>

using namespace std;

List::List()
{
    auto* node = new Node();
    _end = node;
    _end->next = nullptr;
    node->key = 0;
}

void List::push_back(const int& val)
{
    if (_head == nullptr)
    {
        auto* node = new Node();
       _head = node;
        node->key = val;
        node->next = _end;
    }
    else 
    {
        auto* node = new Node();
        auto* it = _head;
        while (it->next != _end)
        {
            it = it->next;
        }
        it->next = node;
        node->next = _end;
        node->key = val;
     }
}

void List::pop_back()
{
    auto* ptr = _head;
    if (this->size() == 1)
    {
        _head = nullptr;
        return;
    }
    while (ptr->next->next != _end)
    {
        ptr = ptr->next;
    }
    ptr->next = _end;
}

Iterator List::begin()
{
    Iterator it(_head);
    return it;
}

Iterator List::end()
{
    Iterator it(_end);
    return it;
}


size_t List::size()
{
    auto size = 0;
    auto* ptr = _head;
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

bool List::empty()
{
    if (_head)
    {
        return false;
    }
    return true;
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
