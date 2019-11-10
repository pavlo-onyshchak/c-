#pragma once
#include <vector>
#include <string>
#include <memory>

using namespace std;

class Iterator;

class Map
{
private:
    struct Node
    {
        pair<int, string> data;
        shared_ptr<Node> right = nullptr;
        shared_ptr<Node> left = nullptr;
        Node() = default;
        Node(pair<int,string> key_val)
        {
            data = key_val;
        }
    };
public:
    using iterator = Iterator;
    using key_val = pair<int, string>;
    using key = int;
    using node = Node;

    Map() = default;
    Map(initializer_list<key_val> init);
    Iterator find(const key& key);
    Iterator begin();
    void insert(const key_val& data);
    size_t size();
    bool empty();
    void erase(const key& key);
    void show();
    static bool test();
private:
    void insert(const key_val& val, shared_ptr<node> node);
    size_t traversal(shared_ptr<node> node,size_t& size);
    void show(shared_ptr<node> node);
    shared_ptr<node> erase(shared_ptr<node>& node, key data);
    shared_ptr<node> findMax(shared_ptr<node> root);
   private:
    shared_ptr<node> _root = nullptr;
};
