#ifndef TREE_H
#define TREE_H
#include "container.h"

class tree : public container
{
    void *root;
    int level_num;
public:

    tree(std::string name = "tree", void *root = nullptr);
    virtual std::string get_base_info() const;
    virtual std::string get_derived_info() const;
    virtual std::string get_typename() const;
    virtual ~tree();
};

#endif // TREE_H
