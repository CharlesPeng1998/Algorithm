#include <iostream>
using namespace std;

class HuffmanTree;
 class HTNode {
private:
        int weight;
        int parent,lchild,rchild;
 public:
     HTNode() {
         weight=0;
         parent=lchild=rchild=-1;
     }
     friend HuffmanTree;
     friend bool compare_weight(HTNode n1,HTNode n2);
     friend void Select(HTNode *HT,int i,int &s1,int &s2);
 };

 class HuffmanTree {
 private:
     HTNode *HT;
     int numNode;
     int numLeafNode;
     int root; //根结点的位置

 public:
     HuffmanTree() {
         HT=NULL;
         numNode=0;
         numLeafNode=0;
         root=-1;
     }
     void createHT(int *w,int n);
     unsigned int getWPL();
     void inputHT(); //输入Huffman树
     void encode(); //求huffman编码
     void decode(); //根据huffman编码建立huffman树
     friend void Select(HTNode *HT,int i,int &s1,int &s2);
 };

 bool compare_weight(HTNode n1,HTNode n2) {
     return n1.weight<n2.weight;
 }

 //构建Huffman树
 void HuffmanTree::createHT(int *w,int n) { //w为存储叶结点权值的数组，n为提供的叶结点个数
     if (n<=1) return ;
     int m=2*n-1; //一颗有n个叶结点的huffman树共有2n-1个结点
     numNode=m; numLeafNode=n;
     HT=new HTNode[m+1]; //0号单元未用
     HTNode *p; int i;//迭代器
     for (p=HT+1,i=1;i<=n;++i,++p,++w) {
         p->weight=*w;
         p->parent=p->lchild=p->rchild=0;
     }
     for (;i<m;++i,++p) {
         p->weight=p->parent=p->lchild=p->rchild=0;
     }
     for (i=n+1;i<=m;i++) {
         int s1,s2;
         Select(HT,i-1,s1,s2);
         HT[s1].parent=i; HT[s2].parent=i;
         HT[i].lchild=s1; HT[i].rchild=s2;
         HT[i].weight=HT[s1].weight+HT[s2].weight;
     }
 }

 //获取Huffman树的WPL（带权路径长度）
 unsigned int HuffmanTree::getWPL() {
     int WPL=0;
     for (int i=1;i<numNode;i++) {
         WPL+=HT[i].weight;
     }
     return WPL; //WPL为除根节点以外各结点权值的和
 }

 //输入Huffman树
 void HuffmanTree::inputHT() {
     int n,w,p,l;
     cin>>n;
     numLeafNode=n; numNode=2*n-1;
     HT=new HTNode[numNode+1];
     for (int i=1;i<=numNode;i++) {
         cin>>w>>p>>l;
         HT[i].weight=w;
         HT[i].parent=p;
         if (p!=0 && l!=0) HT[p].rchild=i;
         else if (p!=0 && l==0) HT[p].lchild=i;
         if (!p) root=i; //父结点为0的为根节点
     }
 }

 //从叶子到根逆向求每个字符的huffman编码
 void HuffmanTree::encode() {
     string HC[numLeafNode+1];
     char *cd=new char[numLeafNode];
     cd[numLeafNode-1]='\0';
     for (int i=1;i<=numLeafNode;i++) {
         int start=numLeafNode-1;
         int c,f;
         for (c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent) {
             if (HT[f].lchild==c) cd[--start]='0';
             else cd[--start]='1';
         }
         HC[i]=&cd[start];
     }

     for (int i=1;i<=numLeafNode;i++) {
         cout<<i<<' '<<HC[i]<<endl;
     }
 }

 //根据字符的huffman编码建立huffman树
 void HuffmanTree::decode() {
     int n,c;
     string code;
     cin>>n;
     if (n<1) return ;
     numLeafNode=n;
     numNode=2*n-1;
     root=1; //选定第一个结点为根节点
     int avl=2; //当前未利用结点
     HT=new HTNode[numNode+2];
     HT[root].parent=0;
     for (int i=1;i<=numLeafNode;i++) {
         cin>>c>>code;
         int curr=root;
         for (int j=0;j<int(code.length());j++) {
             if (code[j]=='1') {
                 if (HT[curr].rchild!=-1) curr=HT[curr].rchild;
                 else {
                     HT[curr].rchild=avl;
                     HT[avl++].parent=curr;
                     curr=HT[curr].rchild;
                 }
             }
             else if (code[j]=='0') {
                 if (HT[curr].lchild!=-1) curr=HT[curr].lchild;
                 else {
                     HT[curr].lchild=avl;
                     HT[avl++].parent=curr;
                     curr=HT[curr].lchild;
                 }
             }
         }
         //目前已经走到一个叶子结点
         HT[curr].weight=c; //将字符ASCII码赋给该叶子节点的权值
     }
     //Huffman树构建完毕，开始译码
     string encoded_text;
     string decoded_text;
     cin>>encoded_text;
     int curr=root;
     for (int i=0;i<int(encoded_text.length());i++) {
         if (encoded_text[i]=='1') curr=HT[curr].rchild;
         else if (encoded_text[i]=='0') curr=HT[curr].lchild;

         if (HT[curr].lchild==-1 && HT[curr].rchild==-1) {
             decoded_text+=char(HT[curr].weight);
             curr=root;
         }
     }

     cout<<decoded_text<<endl;
 }

 void Select(HTNode *HT,int i,int &s1,int &s2) {
     int j;
     int minW;
     for (j=1;j<=i;j++) {
         if (HT[j].parent==0) {
             minW=HT[j].weight;
             s1=j;
             break;
         }
     }
     for (;j<=i;j++) {
         if (HT[j].parent==0 && HT[j].weight<=minW) {
             minW=HT[j].weight;
             s1=j;
         }
     }//找到权值第一小的结点

     for (j=1;j<=i;j++) {
         if (HT[j].parent==0 && j!=s1){
             minW=HT[j].weight;
             s2=j;
             break;
         }
     }
     for (;j<=i;j++) {
         if (HT[j].parent==0 && HT[j].weight<=minW && j!=s1) {
             minW=HT[j].weight;
             s2=j;
         }
     } //找到权值第二小的结点
 }

 int main() {
     HuffmanTree hT;
     hT.decode();
     return 0;
 }
