#include <iostream>
#include <string>
using namespace std;

#define TRAVERSE 0
#define SEARCH 1

enum pointerTag {Link,Thread};
template<class T>
class biThrTree; //Foward declaration
int count=1;

/*******线索二叉树结点*********/
template <class T>
class biThrNode {
private: //注意修改
    T data;
    biThrNode *left,*right;
    pointerTag lTag,rTag;
    friend biThrTree<T>;
public:
    biThrNode() {
        left=NULL;
        right=NULL;
        lTag=Link;
        rTag=Link;
    }
};
/*******线索二叉树结点*********/

/*********线索二叉树***********/
template<class T>
class biThrTree {
private:
    biThrNode<T> *root;
public:
    void createBiTree(); //建立二叉树

    void preCreateBiTree(biThrNode<T>* &ptr); //先序建立二叉树（递归实现）
    void preTreading(biThrNode<T> *ptr,biThrNode<T>* &pre); //先序线索化
    void preOrderTreading(); //先序线索化
    void preOrderTraverse(); //先序遍历线索二叉树 There's some problem here!!
    void display(biThrNode<T> *p,int nLayer); //递归打印二叉树
    template <class Type>
    friend void print(biThrTree<Type> btt);
    void preTraverse(biThrNode<T> *ptr);
    void Traverse();
    void inThreading(biThrNode<T> *ptr,biThrNode<T>* &pre); //中序线索化
    void inOrderTreading(); //中序线索化
    void InOrderTraverse(int opt); //搜索指定结点的并求其前驱和后继
    void getPreSucc(biThrNode<T> *targetNode);

};
template <class T>
void biThrTree<T>::preTraverse(biThrNode<T> *ptr) {
    if (ptr) {
        cout<<ptr->data;
        if (ptr->lTag==Link)
            preTraverse(ptr->left);
        if (ptr->rTag==Link)
            preTraverse(ptr->right);
    }
}

template<class T>
void biThrTree<T>::Traverse() {
    preTraverse(root->left);
}

template <class T>
void biThrTree<T>::preCreateBiTree(biThrNode<T>* &ptr) {
    char data;
    if (!(cin>>data)) return;
    if (data!='#'){
        ptr=new biThrNode<T>;
        ptr->data=data;
        preCreateBiTree(ptr->left);
        preCreateBiTree(ptr->right);
    }
    else ptr=NULL;
}

template<class T>
void biThrTree<T>::createBiTree() {
    preCreateBiTree(root);
}

template<class T>
void biThrTree<T>::preTreading(biThrNode<T> *ptr,biThrNode<T>* &pre) {
    if (ptr) {
        if (!ptr->left) {
            ptr->lTag=Thread;
            ptr->left=pre;
        }
        if (pre && !pre->right) {
            pre->rTag=Thread;
            pre->right=ptr;
        }
        pre=ptr;
        if (ptr->lTag==Link) preTreading(ptr->left,pre);
        if (ptr->rTag==Link) preTreading(ptr->right,pre); //这两句的条件很重要
                                                          //判断是否有子树
    }
}

template<class T>
void biThrTree<T>::preOrderTreading() {
    biThrNode<T> *pre=0;
    preTreading(root,pre);
    pre->rTag=Thread;
}

template <class T>
void biThrTree<T>::preOrderTraverse() {
    biThrNode<T> *ptr=root;
    while (ptr) {
        while (ptr->lTag!=Thread) {
            cout<<ptr->data;
            ptr=ptr->left;
        }
        cout<<ptr->data;
        ptr=ptr->right;
    }
    cout<<endl;
}

template<class T>
void biThrTree<T>::inThreading(biThrNode<T> *ptr,biThrNode<T>* &pre) {
    if (ptr) {
        inThreading(ptr->left,pre);
        if (!ptr->left) {
            ptr->lTag=Thread;
            ptr->left=pre;
        }
        if (!pre->right) {
            pre->rTag=Thread;
            pre->right=ptr;
        }
        pre=ptr;
        inThreading(ptr->right,pre);
    }
}

template <class T>
void biThrTree<T>::inOrderTreading() {
    biThrNode<T> *head=new biThrNode<T>;
    biThrNode<T> *pre;
    head->lTag=Link;
    head->rTag=Thread;
    head->right=head;
    if (!root) head->left=head;
    else {
        head->left=root;
        pre=head;
        inThreading(root,pre);
        pre->right=head;
        pre->rTag=Thread;
        head->right=pre;
    }
    root=head;
}

template<class T>
void biThrTree<T>::display(biThrNode<T> *p,int nLayer) {
    int i;
    //if (p==0) return;
    if (p->rTag==Link) display(p->right,nLayer+1);
    for(i=0;i<nLayer;i++)
        cout<<"     ";
    cout<<p->data<<p->lTag<<p->rTag<<endl;
    if (p->lTag==Link) display(p->left,nLayer+1);
}

template<class Type>
void print(biThrTree<Type> btt) {
    //btt.display(btt.root->left,0);
    btt.display(btt.root,0);
}

template<class T>
void biThrTree<T>::InOrderTraverse(int opt) {
    string inOrderseq;
    char target;
    biThrNode<T> *targetNode=NULL;
    cin>>target;
    biThrNode<T> *ptr=root->left;
    while (ptr!=root) {
        while (ptr->lTag==Link) ptr=ptr->left;
        inOrderseq+=ptr->data;
        if (ptr->data==target) targetNode=ptr;
        while (ptr->rTag==Thread && ptr->right!=root) {
            ptr=ptr->right;
            inOrderseq+=ptr->data;
            if (ptr->data==target) targetNode=ptr;
        }
        ptr=ptr->right;
    }
    cout<<inOrderseq<<endl;

    if (!targetNode) cout<<"Not found"<<endl;
    else {
        if (targetNode->rTag==Thread) {
            if (targetNode->right!=root)
                cout<<"succ is "<<targetNode->right->data<<targetNode->right->rTag<<endl;
            else cout<<"succ is NULL"<<endl;
        }
        else {
            ptr=targetNode->right;
            while (ptr->lTag==Link) ptr=ptr->left;
            cout<<"succ is "<<ptr->data<<ptr->rTag<<endl;
        }

        if (targetNode->lTag==Thread) {
            if (targetNode->left!=root)
                cout<<"prev is "<<targetNode->left->data<<targetNode->left->lTag<<endl;
            else cout<<"prev is NULL"<<endl;
        }
        else {
            ptr=targetNode->left;
            while (ptr->rTag==Link) ptr=ptr->right;
            cout<<"prev is "<<ptr->data<<ptr->lTag<<endl;
        }
    }
}

/*********线索二叉树***********/

int main() {
    biThrTree<char> BTT;
    BTT.createBiTree();
    BTT.inOrderTreading();
    BTT.InOrderTraverse(TRAVERSE);
    return 0;
}
