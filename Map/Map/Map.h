#pragma once
#include <vector>
#include<string>
using namespace std;

class Iterator;

struct Node
{
    pair<int, string> _data;
    Node* _right = nullptr;
    Node* _left = nullptr;
};


class Map
{
public:
    using key_val = pair<int, string>;
    using key = int;

    Map() = default;
    Map(initializer_list<key_val> init);
    Iterator find(const key& key);
    Iterator begin();
    void insert(const key_val& data);
    size_t size();
    bool empty();
    void erase(const key& key);
    void show();
private:
    void insert(const key_val& val, Node* node);
    void traversal(Node* node);
    Node* erase(Node* node, key data);
    Node* FindMax(Node* root);
    void show(Node* node);
    size_t _size = 0;
    Node* _root = nullptr;
    Node* _right_ptr = nullptr;
    Node* _left_ptr = nullptr;
    pair<string, int> _map_data;
};
