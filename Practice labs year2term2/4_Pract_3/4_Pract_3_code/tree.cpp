#include "tree.h"

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

std::string tree::get_base_info() const
{
    return container::get_base_info();
}

std::string tree::get_derived_info() const
{
    char buffer[51];

    sprintf(buffer, "Root: %p\nLevel num: %i\n", root, level_num);

    return buffer;
}

std::string tree::get_typename() const
{
    return "tree";
}

tree::~tree()
{
}
