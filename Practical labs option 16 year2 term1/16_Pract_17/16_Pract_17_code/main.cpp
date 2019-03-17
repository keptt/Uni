#include <iostream>

struct Tree
{
    int data;
    Tree *left, *right;
};

void show(Tree *root)
{
    if (root != nullptr)
    {
        show(root->left);
        std::cout << root->data << ' ';
        show(root->right);
    }
}

Tree *add(Tree *&root, int data)
{
    if (!root)
    {
        root = new Tree;
        root->data = data;

        root->left = nullptr;
        root->right = nullptr;
    }
    else
    {
       if (root->data > data)
       {
           add(root->left, data);
       }
       else if (root->data < data)
       {
           add(root->right, data);
       }
       else
       {
           throw std::logic_error("Element equasion issue");
       }
    }
    return root;
}

void clear(Tree *&root)
{
    if (!root)
    {   return;}

    if (root->left)
    {
        clear(root->left);
    }
    if (root->right)
    {
        clear(root->right);
    }
    delete root;
    root = nullptr;
}

void pshow(Tree *root, size_t num_of_spaces = 1, size_t spaces = 0)
{
    if (!root)
        return;
    pshow(root->right, num_of_spaces, spaces + num_of_spaces);

    std::cout << '\n';

    for (size_t i = 0; i < spaces; ++i)
        std::cout << ' ';

    std::cout << root->data;

    pshow(root->left, num_of_spaces, spaces + num_of_spaces);
}

void fill_the_tree(Tree *&root)
{
    size_t size(0);
    int data_for_input(0);

    std::cout << "Input size of a tree: ";
    std::cin >> size;
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "INput node: ";
        std::cin >> data_for_input;
        add(root, data_for_input);
    }
}

void find_nodes_with_spec_depth(Tree *root, size_t &counter, size_t required_depth,
                                size_t current_depth = 0)
{
    if (required_depth != current_depth)
    {
        if (root->left)
        {
            find_nodes_with_spec_depth(root->left, counter, required_depth, current_depth + 1);
        }
        if (root->right)
        {
            find_nodes_with_spec_depth(root->right, counter, required_depth, current_depth + 1);
        }
    }
    else
    {
        counter++;
    }
}

int main()
{
    Tree *root = nullptr;
    fill_the_tree(root);
    show(root);

    pshow(root, 2);
    std::cout << '\n';

    size_t counter(0);
    size_t depth;
    std::cout << "Input depth ";
    std::cin >> depth;

    find_nodes_with_spec_depth(root, counter, depth);

    std::cout << counter << std::endl;
    clear(root);

    return 0;
}
