#pragma once
#include <string>
#include "Map.h"
using namespace std;

class Iterator
{
public:
    Iterator() = default;
    Iterator(Node* node);
    pair<int, string>* operator->();
private:
    Node* _iter;
    pair<int, string>* _data;
};
