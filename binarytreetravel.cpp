// binary tree traversal methods

#include <iostream>
#include "arrayQueue.h"
#include "binaryTreeNode.h"
#include "myExceptions.h"

using namespace std;

template <class T>
void visit(binaryTreeNode<T>* x)
{// visit node *x, just output element field.
    cout << x->element << ' ';
}

template <class T>
void preOrder(binaryTreeNode<T>* t)
{
    if (t != NULL)
    {
        visit(t);                 // visit tree root
        preOrder(t->leftChild);   // do left subtree
        preOrder(t->rightChild);  // do right subtree
    }
}

template <class T>
void inOrder(binaryTreeNode<T>* t)
{
    if (t != NULL) {
        inOrder(t->leftChild);
        visit(t);
        inOrder(t->rightChild);
    }

}

template <class T>
void postOrder(binaryTreeNode<T>* t)
{
    if (t != NULL) {
        postOrder(t->leftChild);
        postOrder(t->rightChild);
        visit(t);
    }
}

template <class T>
void levelOrder(binaryTreeNode<T>* t) {
    arrayQueue<binaryTreeNode<T>*> q;
    while (t != NULL) {
        visit(t);
        if (t->leftChild) {
            q.push(t->leftChild);
        }
        if (t->rightChild) {
            q.push(t->rightChild);
        }
        try {
            t = q.front();
        }
        catch (queueEmpty) {
            return;
        }
        q.pop();
    }


}

int main(void)
{
    /* input tree:
     *
     *          1
     *	      / \
     *        2   3
     *       / \
     *      4   5
     *
     */
    binaryTreeNode <int>* L = new binaryTreeNode<int>(2);
    binaryTreeNode <int>* R = new binaryTreeNode<int>(3);
    binaryTreeNode <int>* M = new binaryTreeNode<int>(1, L, R);
    L->leftChild = new binaryTreeNode<int>(4);
    L->rightChild = new binaryTreeNode<int>(5);
    cout << "InOrder";
    inOrder(M);
    cout << endl;
    cout << "PreOrder";
    preOrder(M);
    cout << endl;
    cout << "postOrder";
    postOrder(M);
    cout << endl;
    cout << "Level Order";
    levelOrder(M);
    cout << endl;
    return 0;
}