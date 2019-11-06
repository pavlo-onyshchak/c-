#include "Iterator.h"


Iterator::Iterator(shared_ptr<Map::node> node)
{
    _iter = node;
    data = &node->data;
}

pair<int, string>* Iterator::operator->()
{
    return data;
}
