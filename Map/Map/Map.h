#pragma once
#include <vector>
#include<string>
using namespace std;

class Map
{
public:
    using iterator = pair<string, string>*;
    using key_val = pair<string, string>;
    using key = string;

    Map();
    Map(initializer_list<key_val> init);
    iterator find(const key& key);
    iterator begin();
    iterator end();
    iterator insert(const key_val& v);
    size_t size();
    bool erase(const key& key);
    void show();
    bool test();

private:
    vector<key_val> _arr;
};
