#include "Iterator.h"

void Iterator::traversal(Map::node* node)
{
    if (!node)
    {
        return;
    }
    traversal(node->left.get());
    _vec.push_back(node);
    traversal(node->right.get());
}

Iterator::Iterator(Map::node* node,Map::node* root)
{
    _iter = node;
    _data = node->data;
    traversal(root);
}

Map::key_val* Iterator::operator->()
{
    return &_data;
}

Map::key_val& Iterator::operator*()
{
    return _data;
}

Iterator Iterator::operator++(int)
{
    auto it = *this;
    for (auto i = 0; i < _vec.size(); i++)
    {
        if (this->_iter == _vec[i])
        {
            this->_iter = _vec[i+1];
            this->_data = _vec[i+1]->data;
            break;
        }
    }
    return it;
}

Iterator Iterator::operator--(int)
{
    auto it = *this;
    for (auto i = 0; i < _vec.size(); i++)
    {
        if (this->_iter == _vec[i])
        {
            this->_iter = _vec[i-1];
            this->_data = _vec[i-1]->data;
            break;
        }
    }
    return it;
}
