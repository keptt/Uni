#ifndef TREE_H
#define TREE_H
#include "container.h"

class tree : public container
{
    int *root;
    int level_num;
public:

    tree(std::string name = "tree", int *root = nullptr);
    virtual void get_info() const;
    virtual ~tree();
};

#endif // TREE_H
