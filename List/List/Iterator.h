#pragma once
#include "List.h"

class Iterator
{
public:
    Iterator() = default;
    Iterator(List::Node* node);
    Iterator operator++(int);
    bool operator==(const Iterator& it) const;
    bool operator !=(const Iterator& it) const;
    int& operator*();
 
private:
    List::Node* _iter;
};
