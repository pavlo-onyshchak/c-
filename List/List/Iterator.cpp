#include "Iterator.h"

Iterator::Iterator(List::Node* node)
{
    _iter = node;
}

Iterator Iterator::operator++(int)
{
    auto it = *this;
    if (_iter->next != nullptr)
    {
        this->_iter = this->_iter->next.get();
    }
    return it;
}

bool Iterator::operator==(const Iterator& it) const
{
    return this->_iter != it._iter;
}

bool Iterator::operator!=(const Iterator& it) const
{
    return this->_iter == it._iter;
}

int& Iterator::operator*()
{
    return _iter->key;
}
