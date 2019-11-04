#include<iostream>
#include"Map.h"
#include "Iterator.h"
#include <map>

using namespace std;
int main()
{
    auto map = Map({ {100,"a"},{50,"b"},{30,"c"},{150,"d"} });
    auto size = map.size();
    cout << size << endl;
    map.show();
    return 0;
}
