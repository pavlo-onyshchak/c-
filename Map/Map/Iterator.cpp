#include "Iterator.h"

Iterator::Iterator(Node* node)
{
    _iter = node;
    _data = &node->_data;
}

pair<int, string>* Iterator::operator->()
{
    return _data;
}
