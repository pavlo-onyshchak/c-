#include "Map.h"
#include "Iterator.h"
#include <iostream>
#include <map>


Iterator Map::find(const key& key)
{
    auto node = _root;
    while (key != node->data.first)
    {
        if (key > node->data.first)
        {
            node = node->right;
        }
        else if (key < node->data.first)
        {
            node = node->left;
        }
        if (!node)
        {
            break;
        }
    }
    return { node };
 }

Iterator Map::begin()
{
    auto ptr = _root;
    while(ptr->left != nullptr)
    {
        ptr = ptr->left;
    }
    return { ptr };
}

void Map::insert(const key_val& data, shared_ptr<node> node)
{
    if (data.first < node->data.first)
    {
        if (node->left != nullptr)
        {
            insert(data, node->left);
        }
        else
        {
            node->left = make_shared<Map::node>(data);
        }
    }
    else if (data.first > node->data.first)
    {
        if (node->right != nullptr)
        {
            insert(data, node->right);
        }
        else
        {
            node->right = make_shared<Map::node>(data);
        }
    }
    else
    {
        node->data = data;
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
        _root = make_shared<Map::node>(data);
    }
}

Map::Map(initializer_list<key_val> init)
{
    for (auto it = init.begin(); it != init.end(); it++)
    {
        insert(*it);
    }
}

size_t Map::traversal(shared_ptr<node> node,size_t& size)
{
    if (!node)
    {
        return size;
    }
    traversal(node->left,size);
    size++;
    traversal(node->right,size);
    return size;
}

size_t Map::size()
{
    size_t size = 0;
    if (!_root)
    {
        return 0;
    }
   return  traversal(_root,size);
}

bool Map::empty()
{
    return size() == 0;
}

shared_ptr<Map::node> Map::findMax(shared_ptr<node> root)
{
    if (root == nullptr)
        return nullptr;

    while (root->right != nullptr)
    {
        root = root->right;
    }
    return root;
}

shared_ptr<Map::node> Map::erase(shared_ptr<node>& node, key data)
{
    if (node == nullptr)
    {
        return node;
    }
    else if (data < node->data.first)
    {
       node->left =  erase(node->left, data);
    }
    else if (data  > node->data.first)
    {
       node->right = erase(node->right, data);
    }
    else
    {
        if (node->right == nullptr && node->left == nullptr)
        {
            node.reset();
        }
        else if (node->right == nullptr)
        {
            node = node->left;
        }
        else if (node->left == nullptr)
        {
            node = node->right;
        }
        else
        {
            auto temp = findMax(node->left);
            node->data = temp->data;
            node->left = erase(node->left, temp->data.first);
        }
    }
    return node;
}

void Map::erase(const key& key)
{
    erase(_root, key);
}

void Map::show(shared_ptr<node> root)
{
    if (!root)
    {
        return;
    }
    show(root->left);
    cout << root->data.first << " ";
    show(root->right);
}

void Map::show()
{
    show(_root);
}

bool Map::test()
{
    auto my_map = Map({ {100,"a"},{50,"b"},{30,"c"},{150,"d"},{130,"d"},{110,"d"},{140,"d"},{200,"d"} });
    map<int, string> stl_map({ {100,"a"},{50,"b"},{30,"c"},{150,"d"},{130,"d"},{110,"d"},{140,"d"},{200,"d"} });
    vector<int> vec{ 100,50,30,150,130,110,140,200 };
    for (auto i = 0; i < vec.size(); i++)
    {
        auto my_begin = my_map.begin();
        auto stl_begin = stl_map.begin();
        if (my_begin->first != stl_begin->first)
        {
            throw exception("begin() is incorrect");
        }
        auto my_size = my_map.size();
        auto stl_size = stl_map.size();
        if (my_map.size() != stl_map.size())
        {
            throw exception("size() is incorrect");
        }
        auto my_find = my_map.find(vec[i]);
        auto stl_find = stl_map.find(vec[i]);
        if (my_find->first != stl_find->first)
        {
            throw exception("find is inccorect");
        }
        if (my_map.empty() != stl_map.empty())
        {
            throw exception("empty() is imcorrect");
        }
        my_map.erase(vec[i]);
        stl_map.erase(vec[i]);
        my_size = my_map.size();
        stl_size = stl_map.size();
        if (my_map.size() != stl_map.size())
        {
            throw exception("erase() is incorrect");
        }
    }
    return true;
}
