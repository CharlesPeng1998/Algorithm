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
     int root; //������λ��

 public:
     HuffmanTree() {
         HT=NULL;
         numNode=0;
         numLeafNode=0;
         root=-1;
     }
     void createHT(int *w,int n);
     unsigned int getWPL();
     void inputHT(); //����Huffman��
     void encode(); //��huffman����
     void decode(); //����huffman���뽨��huffman��
     friend void Select(HTNode *HT,int i,int &s1,int &s2);
 };

 bool compare_weight(HTNode n1,HTNode n2) {
     return n1.weight<n2.weight;
 }

 //����Huffman��
 void HuffmanTree::createHT(int *w,int n) { //wΪ�洢Ҷ���Ȩֵ�����飬nΪ�ṩ��Ҷ������
     if (n<=1) return ;
     int m=2*n-1; //һ����n��Ҷ����huffman������2n-1�����
     numNode=m; numLeafNode=n;
     HT=new HTNode[m+1]; //0�ŵ�Ԫδ��
     HTNode *p; int i;//������
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

 //��ȡHuffman����WPL����Ȩ·�����ȣ�
 unsigned int HuffmanTree::getWPL() {
     int WPL=0;
     for (int i=1;i<numNode;i++) {
         WPL+=HT[i].weight;
     }
     return WPL; //WPLΪ�����ڵ���������Ȩֵ�ĺ�
 }

 //����Huffman��
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
         if (!p) root=i; //�����Ϊ0��Ϊ���ڵ�
     }
 }

 //��Ҷ�ӵ���������ÿ���ַ���huffman����
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

 //�����ַ���huffman���뽨��huffman��
 void HuffmanTree::decode() {
     int n,c;
     string code;
     cin>>n;
     if (n<1) return ;
     numLeafNode=n;
     numNode=2*n-1;
     root=1; //ѡ����һ�����Ϊ���ڵ�
     int avl=2; //��ǰδ���ý��
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
         //Ŀǰ�Ѿ��ߵ�һ��Ҷ�ӽ��
         HT[curr].weight=c; //���ַ�ASCII�븳����Ҷ�ӽڵ��Ȩֵ
     }
     //Huffman��������ϣ���ʼ����
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
     }//�ҵ�Ȩֵ��һС�Ľ��

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
     } //�ҵ�Ȩֵ�ڶ�С�Ľ��
 }

 int main() {
     HuffmanTree hT;
     hT.decode();
     return 0;
 }
