#include "Map.h"
#include "Iterator.h"
#include <iostream>
#include <map>

Iterator Map::find(const key& key)
{
    auto node = _root;
    while (key != node->_data.first)
    {
        if (key > node->_data.first)
        {
            node = node->_right;
        }
        else if (key < node->_data.first)
        {
            node = node->_left;
        }
        if (!node)
        {
            break;
        }
    }
    Iterator it(node);
    return it;
}

Iterator Map::begin()
{
    Iterator it(_root);
    return it;
}

void Map::insert(const key_val& data, Node* node)
{
    if (data.first < node->_data.first)
    {
        if (node->_left != nullptr)
        {
            insert(data, node->_left);
        }
        else
        {
            auto leaf = new Node;
            leaf->_data = data;
            node->_left = leaf;
        }
    }
    else if (data.first > node->_data.first)
    {
        if (node->_right != nullptr)
        {
            insert(data, node->_right);
        }
        else
        {
            auto leaf = new Node;
            leaf->_data = data;
            node->_right = leaf;
        }
    }
    else
    {
        node->_data = data;
    }

}


void Map::insert(const key_val& data)
{
    if (_root)
    {
        insert(data,_root);
    }
    else
    {
        auto node = new Node;
        node->_data = data;
        _root = node;
    }
}

Map::Map(initializer_list<key_val> init)
{
    auto size = init.size();
    for (auto it = init.begin(); it != init.end(); it++)
    {
        insert(*it);
    }
}

void Map::traversal(Node* node)
{
    if (!node)
    {
        return;
    }
    traversal(node->_left);
    _size++;
    traversal(node->_right);
    
}

size_t Map::size()
{
    if (!_root)
    {
        return _size;
    }
    traversal(_root);
    return _size;
}

bool Map::empty()
{
    return _root; //it's work correct, but doesn't shure if code style is ok
}

Node* Map::FindMax(Node* root)
{
    if (root == nullptr)
        return nullptr;

    while (root->_right != nullptr)
    {
        root = root->_right;
    }
    return root;
}


Node* Map::erase(Node* node, key data)
{
    if (node == nullptr)
    {
        return node;
    }
    else if (data < node->_data.first)
    {
       node->_left =  erase(node->_left, data);
    }
    else if (data  > node->_data.first)
    {
       node->_right = erase(node->_right, data);
    }
    else
    {
        if (node->_right == nullptr && node->_left == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if (node->_right == nullptr)
        {
            auto temp = node;
            node = node->_left;
            delete temp;
        }
        else if (node->_left == nullptr)
        {
            auto temp = node;
            node = node->_right;
            delete temp;
        }
        else
        {
            auto temp = FindMax(node->_left);
            node->_data = temp->_data;
            node->_left = erase(node->_left, temp->_data.first);
        }
    }
    return node;
}

void Map::erase(const key& key)
{
    erase(_root, key);
}

void Map::show(Node* root)
{
    if (!root)
    {
        return;
    }
    show(root->_left);
    cout << root->_data.first << " ";
    show(root->_right);
}

void Map::show()
{
    show(_root);
}