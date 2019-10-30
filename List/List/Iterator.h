#pragma once
#include "List.h"

class Iterator
{
public:
    Iterator() = default;
    Iterator(Node* node);
    Iterator operator++(int);
    bool operator==(Iterator& it);
    bool operator !=(Iterator& it);
    int& operator*();
 
private:
    Node* _iter;
};