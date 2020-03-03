#include <iostream>

// A BST node
struct node {
    int data;
    struct node *left, *right;
};

int count = 0;

void BSTk(struct node *root, int k)
{
    if (root != NULL && count <= k)
    {
        BSTk(root->right, k);
        count++;
        if (count == k)
            printf("%d ", root->data);
        BSTk(root->left, k);
    }
}

int main() {

    BSTk(2)
    return 0;
}
