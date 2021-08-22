#include <bits/stdc++.h>

using namespace std;

class node
{

public:
    int val;
    node *left;
    node *right;
    int height;
};

node *newNode(int val)
{

    node *n = new node();

    n->val = val;

    n->left = NULL;
    n->right = NULL;
    n->height = 1;

    return n;
}

int getHgt(node *root)
{

    if (root == nullptr)
    {
        return 0;
    }

    return root->height;
}

node *rightRotate(node *y)
{

    node *x = y->left;
    node *t3 = x->right;

    x->right = y;
    y->left = t3;

    y->height = max(getHgt(y->left), getHgt(y->right)) + 1;
    x->height = max(getHgt(x->left), getHgt(x->right)) + 1;

    return x;
}

node *leftRotate(node *z)
{

    node *x = z->right;
    node *t2 = x->left;

    x->left = z;
    z->right = t2;

    z->height = max(getHgt(z->left), getHgt(z->right));
    x->height = max(getHgt(x->left), getHgt(x->right));

    return x;
}

int getBal(node *n)
{

    if (n == NULL)
    {
        return 0;
    }

    return (getHgt(n->left) - getHgt(n->right));
}

node *insertion(node *root, int key)
{

    if (root == NULL)
    {
        return newNode(key);
    }

    if (root->val > key)
    {

        root->left = insertion(root->left, key);
    }
    else if (root->val < key)
    {

        root->right = insertion(root->right, key);
    }
    else
    {
        return root;
    }

    root->height = max(getHgt(root->left), getHgt(root->right)) + 1;

    int balance = getBal(root);

    // left left case
    if (balance > 1 and root->left->val > key)
    {

        root = rightRotate(root);
    }

    // left right case
    if (balance > 1 and root->left->val < key)
    {
        root->left = leftRotate(root->left);

        root = rightRotate(root);
    }

    // right right case
    if (balance < -1 and root->right->val < key)
    {
        root = leftRotate(root);
    }

    // right left case
    if (balance < -1 and root->right->val > key)
    {

        root->right = rightRotate(root->right);

        root = leftRotate(root);
    }

    return root;
}

void pre(node *root)
{

    if (root == NULL)
    {
        return;
    }

    cout << root->val;

    pre(root->left);
    pre(root->right);

    return;
}

int main()
{
    node *root = NULL;

    root = insertion(root, 1);
    root = insertion(root, 2);
    root = insertion(root, 3);

    pre(root);
}
