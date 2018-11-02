#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

/***************Stack****************/
template<class T>
class Stack:public stack<T> { //公有继承stack类并改写pop()
public:
    T pop() {
        T tmp=stack<T>::top();
        stack<T>::pop();
        return tmp;
    }
};
/***************Stack****************/

/****************Queue******************/
template<class T>
class Queue:public queue<T> { //共有继承queue并改写入队出队操作
public:
    T dequeue() {
        T tmp=queue<T>::front();
        queue<T>::pop();
        return tmp;
    }
    void enqueue(const T& el) {
        push(el);
    }
};
/****************Queue******************/

/*************Binary Search Tree**************/
template<class T>
class BSTNode {
public:
    BSTNode() {
        left=right=0;
    }
    BSTNode(const T &e,BSTNode<T> *l=0, BSTNode<T> *r=0) {
        el=e;left=l;right=r;
    }
    T el;
    BSTNode<T> *left,*right;
};

template<class T>
class BST {
public:
    BST() {
        root=0;
    }
    friend void initBST(BST<char> bst);
protected:
    BSTNode<T> *root;
};


void initBST(BST<char> bst) {
    string input;
    Stack<BSTNode<char>*> nodeStack;
    cin>>input;
    if (!input.length()) return; //无输入
    bst.root=new BSTNode<char>;
    bst.root->el=input[0];
    BSTNode<char> *ptr=bst.root;
    for (int i=1;i<int(input.length());i++) {
        if (ptr) { //当前结点不为空结点
            if (input[i]!='#') {
                ptr->left=new BSTNode<char>;
                ptr->left->el=input[i];
                nodeStack.push(ptr);
                ptr=ptr->left;
            }
            else {
                nodeStack.push(ptr);
                ptr=ptr->left;
            }
        }
        else { //当前结点位空结点，从栈中弹出上一个结点
            ptr=nodeStack.pop();
            if (input[i]!='#') {
                ptr->right=new BSTNode<char>;
                ptr->right->el=input[i];
                ptr=ptr->right;
            }
            else {
                ptr=ptr->right;
            }
        }
    }
}
/*************Binary Search Tree**************/

int main() {

}
