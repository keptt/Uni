#include "tree.h"
#pragma warning(disable:4996)
#define _CRT_SECURITY_NO_WARNINGS

tree::tree(std::string name, void *root): container (name, 0)
{
//    tree::name = "2";
//    container::name = "1";
    this->level_num = 0;

    if (root)
    {
        this->root = root;
        this->size++;
        this->level_num++;
    }
    else
        this->root = nullptr;

}

std::string tree::get_info() const
{
    std::string previnfo = container::get_info();

    char buffer[51];

    sprintf(buffer, "Root: %p\nLevel num: %i\n", root, level_num);

    previnfo.append(buffer);

    return previnfo;
}

std::string tree::get_typename() const
{
    return "tree";
}

tree::~tree()
{
}
