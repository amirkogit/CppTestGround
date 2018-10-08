// Comparing two trees if they are structurally equal

#include <QCoreApplication>
#include <vector>
#include <iostream>
#include <memory>

using namespace std;

struct node {
    int data = 0;
    node* left = nullptr;
    node* right = nullptr;
};

node* newNode(int data)
{
    auto tempNode = new node;
    tempNode->data = data;
    tempNode->left = nullptr;
    tempNode->right = nullptr;
    return tempNode;
}

void printTree(node* root)
{
    if(root == nullptr) {
        return;
    }

    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}

// check if two trees are structurally identical
bool identicalTrees(node* root1, node* root2)
{
    if(root1 == nullptr && root2 == nullptr) {
        return true;
    }

    if(root1 != nullptr && root2 != nullptr) {
        bool isEqual = root1->data == root2->data &&
                identicalTrees(root1->left, root2->left) &&
                identicalTrees(root1->right, root2->right);
        return isEqual;
    }

    return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout << "Identical trees demo\n";

    node* root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left = newNode(4);
    root1->left->right = newNode(5);

    node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    printTree(root1);
    cout << endl;
    printTree(root2);
    cout << endl;

    if(identicalTrees(root1,root2)) {
        cout << "identical trees.\n";
    }
    else {
        cout << "not identical trees.\n";
    }

    return a.exec();
}
