#pragma once
#include <string>
#include "Map.h"

using namespace std;

class Iterator
{
public:
    Iterator() = default;
    Iterator(shared_ptr<Map::node> node);
    pair<int, string>* operator->();
private:
    shared_ptr <Map::node> _iter;
    pair<int, string>* data;
};
