#include "Iterator.h"

Iterator::Iterator(Node* node)
{
    _iter = node;
}

Iterator Iterator::operator++(int)
{
    Iterator it = *this;
    if (_iter->next != nullptr)
    {
        this->_iter = this->_iter->next;
    }
    return it;
}

bool Iterator::operator==(Iterator& it)
{
    if (this->_iter != it._iter)
    {
        return false;
    }
    return true;
}

bool Iterator::operator!=(Iterator& it)
{
    if (this->_iter == it._iter)
    {
        return false;
    }
    return true;
}

int& Iterator::operator*()
{
    return _iter->key;
}
