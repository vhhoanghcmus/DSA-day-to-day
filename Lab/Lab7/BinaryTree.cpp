/*
Creating functions
1. Define Binary tree
2. Preorder tree traversal (Root - Left - Right)
3. Postorder tree traversal (Root - Left - Right)
4. Inorder tree traversal (Root - Left - Right)
*/


#include <bits/stdc++.h>

using namespace std;


struct Node{
    int data;
    Node* pLeft;
    Node* pRight;
};
typedef struct Node NODE;
typedef NODE* TREE;

void InitTree(TREE &t) {
    t = NULL;
}

void InsertNode( TREE &t, int x) {
    if( t == NULL ) {
        NODE *p = new NODE;
        p->data = x;
        p->pLeft = p->pRight = NULL;
        t = p;
    }
    else {
        if(t->data > x) {
            InsertNode(t->pLeft, x);
        } else {
            InsertNode(t->pRight, x);
        } 
    }
}
// Preorder tree traversal (Root - Left - Right)
void preorderTraversal(TREE root)
{
    if (!root)
        return;
    cout << root->data << " ";
    preorderTraversal(root->pLeft);
    preorderTraversal(root->pRight);
}
// Postorder tree traversal (Left - Right - Root)
void postorderTraversal(Node* root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->pLeft);
    postorderTraversal(root->pRight);
    cout << root->data << " ";
}

// Inorder tree traversal (Left - Root - Right)
void inorderTraversal(Node* root)
{
    if (!root)
        return;
    inorderTraversal(root->pLeft);
    cout << root->data << " ";
    inorderTraversal(root->pRight);
}

void DeleteNode(TREE &t, int data) {
    if (t == NULL) return;
    else {
        if( t->data > data ) {
            DeleteNode(t->pLeft, data);
        }
        else if ( data > t->data) {
            DeleteNode(t->pRight, data);
        }
        else {
            NODE *TokenNode = t;
            if ( t->pLeft == NULL ) {
                t = t->pRight;
            }
            else if ( t -> pRight == NULL) {
                t = t->pLeft;
            }
            delete TokenNode;
        }
    }
}
int main() {
    TREE T;
    InitTree(T);
    InsertNode(T, 3);
    InsertNode(T, 2);
    InsertNode(T, 1);
    InsertNode(T, 4);
    InsertNode(T, 5);
    DeleteNode(T, 2);
    preorderTraversal(T);
}