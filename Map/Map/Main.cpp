#include<iostream>
#include"Map.h"

int main()
{
    auto map = Map({ {"first", "val"}, {"second", "val2"}, {"third", "val3"} });
    Map::iterator h = map.insert(make_pair("second", "val4"));
    bool b = map.erase("first");
    cout << b << endl;
    int k = map.size();
    cout << k << endl;
    h = map.end();
    cout << h->second << endl;
    return 0;
}