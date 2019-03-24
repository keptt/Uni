#include "tree.h"

tree::tree(std::string name, int *root)
{
//    tree::name = "2";
//    container::name = "1";
    this->name = name;
    this->size = 0;
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

void tree::get_info() const
{
    printf("\n");

    container::get_info();

    printf("\n");
}

tree::~tree()
{
}

