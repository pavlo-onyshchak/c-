#include "Map.h"


Map::iterator Map::find(const key& key)
{
    for (int i = 0; i < _arr.size(); i++)
    {
        if (_arr[i].first == key)
            return &_arr[i];
    }
    return nullptr;
}

Map::iterator Map::begin()
{
    return &_arr[0];
}

Map::iterator Map::end()
{
     return &_arr[_arr.size()-1];
}

Map::iterator Map::insert(const key_val& v)
{
   for (int i = 0; i < _arr.size(); i++)
    {
       if (_arr[i].first == v.first)
       {
           _arr[i].second = v.second;
           return &_arr[i];
       }
    }
   _arr.push_back(v);
   return Map::end();
}

int Map::size()
{
    return _arr.size();
}

bool Map::erase(const key& key)
{
    for (int i = 0; i < _arr.size(); i++)
    {
        if (_arr[i].first == key)
        {
            _arr.erase(_arr.begin() + i);
            return true;
        }
    }
    return false;
}


