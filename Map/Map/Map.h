#pragma once
#include <vector>
#include<string>
using namespace std;


//class MapIterator {
//public:
//    pair<string, string>& operator*() {
//        return *ptr;
//    }
//
//    pair<string, string>* operator->() {
//        return ptr;
//    }
//
//private:
//    pair<string, string>* ptr = nullptr;
//};


class Map
{
public:
    using iterator = pair<string, string>*;
    using key_val = pair<string, string>;
    using key = string;

    Map(initializer_list<key_val> init) : _arr(init) {};
    iterator find(const key& key);
    iterator begin();
    iterator end();
    iterator insert(const key_val& v);
    int size();
    bool erase(const key& key);

private:
    vector<key_val> _arr;
};
