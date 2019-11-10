#pragma once
#include <string>
#include <vector>
#include "Map.h"

using namespace std;

class Iterator
{
public:
    Iterator() = default;
    Iterator(Map::node* node,Map::node* root);
    Map::key_val* operator->();
    Map::key_val& operator*();
    Iterator operator++(int);
    Iterator operator--(int);
    void traversal(Map::node* node);
private:
    vector<Map::node*> _vec;
    Map::node* _iter;
    Map::key_val _data;
};
