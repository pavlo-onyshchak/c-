#include "Map.h"
#include <iostream>
#include <map>

Map::Map()
{
    _arr.push_back(make_pair("", ""));
}

Map::Map(initializer_list<key_val> init) : _arr(init)
{
    _arr.push_back(make_pair("",""));
};

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
   _arr.insert(_arr.end() -1 , v);
   return Map::end();
}

size_t Map::size()
{
    return _arr.size() -1;
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

void Map::show()
{
    for (int i = 0; i < Map::size(); i++)
    {
        cout << _arr[i].first << " " << _arr[i].second << endl;
    }
}

bool Map::test()
{
    map <string, string> stl_map;
    stl_map["first"] = "val1";
    stl_map["second"] = "val2";
    this->insert({ "first","val1" });
    this->insert({ "second","val2" });
    int k = this->size();
    if (stl_map.size() != this->size())
    {
        throw exception("size is incorect");
    }
    map<string, string>::iterator stl_it = stl_map.find("first");
    iterator my_it = this->find("first");
    if (stl_it->second != my_it->second)
    {
        throw exception("incorect find function");

    }
    stl_it = stl_map.begin();
    my_it = this->begin();
    if (stl_it->first != my_it->first)
    {
        throw exception("incorect begin function");
    }
   
    return true;
}


