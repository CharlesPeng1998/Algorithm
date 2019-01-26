/***当前已发现的bug**
对于非连通图的输出不正确
******************/


#include <iostream>
#include <iomanip>
#include <queue>
#define INF 0x3f3f3f3f
#define ADJMTX 0
#define ADJLIST 1
using namespace std;

template<class T>
class Queue:public queue<T> { //共有继承queue并改写入队出队操作
public:
    T dequeue() {
        T tmp=queue<T>::front();
        queue<T>::pop();
        return tmp;
    }
    void enqueue(const T& el) {
        queue<T>::push(el);
    }
};

typedef enum{DG=1,DN,NDG,NDN} GraphKind;
typedef int arcCell; //邻接矩阵中结点的信息：若为图则代表是否相邻；若为网则代表权值
template <class T>
class Graph;

template<class T>
class ArcNode {
    int adjvex; //该弧所指向的顶点的位置
    ArcNode *nextarc; //指向下一条弧的指针
    int info; //该弧的相关信息，如权值
    friend Graph<T>;

public:
    ArcNode() {
        nextarc=NULL;
    }
};

template<class T>
class VNode {
    T data; //顶点信息
    ArcNode<T> *firstarc; //指向第一条依附该顶点的弧的指针
    friend Graph<T>;

public:
    VNode() {firstarc=NULL;}
};

template <class T>
class Graph { //邻接矩阵
    T *vex; //顶点向量
    arcCell **arcs;
    VNode<T> *vertices;
    int vexNum,arcNum; //顶点和弧的数量
    GraphKind kind; //图的种类
    int *visited;

public:
    Graph() {
        vex=NULL;
        arcs=NULL;
        vexNum=arcNum=0;
    }

    void setKind(); //设定图的类型
    void init(); //建立图
    void initGraphForTrav(); //为题目“图的遍历”建立图
    void printAdjMtx(); //打印邻接矩阵
    void printAdjList(); //打印邻接表
    void DFSTraverse(int structure); //dfsForAjdMtx寻找连通子集
    void dfsForAjdMtx(int v); //邻接矩阵中的深度优先搜索
    void dfsForAdjList(int v); //邻接表中的深度优先搜索
    void BFSTraverse(int structure); //BFS寻找连通子集
    void initNet(); //建立网（用于求最小生成树）
    void DFS(int v,int &vexnum); //深度优先遍历检查图的连通性
    int prim(); //prim算法求最小生成树
};

class Node{ //prim算法中辅助数组的结点
public:
    int adjvex;
    int lowcost;
}*closedge;

/*****设定图的类型*****/
template<class T>
void Graph<T>::setKind() {
    int k;
    cin>>k;
    switch(k) {
        case DG:kind=DG;break;
        case DN:kind=DN;break;
        case NDG:kind=NDG;break;
        case NDN:kind=NDN;break;
        default:break;
    }
}
/*****设定图的类型*****/

/*****建立图*****/
template<class T>
void Graph<T>::init() {
    cin>>vexNum>>arcNum;
    vex=new T[vexNum];
    int hashtable[128],w; //根据字符寻找找在字符串当中的位置
    char vex1,vex2;
    cin>>vex;
    for (int i=0;i<vexNum;i++) {
        hashtable[int(vex[i])]=i+1;
    }

    //为邻接矩阵申请空间
    arcs=new arcCell*[vexNum+1];
    for (int i=1;i<=vexNum;i++) arcs[i]=new arcCell[vexNum+1]; //邻接矩阵从1开始计数

    //邻接矩阵初始化
    for (int i=1;i<=vexNum;i++) {
        for (int j=1;j<=vexNum;j++) arcs[i][j]=0;
    }

    //不同图种类对邻接矩阵做不同处理
    if (kind==DG) {
        for (int i=0;i<arcNum;i++) {
            cin>>vex1>>vex2;
            arcs[hashtable[int(vex1)]][hashtable[int(vex2)]]=1;
        }
    }
    else if (kind==NDG) {
        for (int i=0;i<arcNum;i++) {
            cin>>vex1>>vex2;
            arcs[hashtable[int(vex1)]][hashtable[int(vex2)]]=1;
            arcs[hashtable[int(vex2)]][hashtable[int(vex1)]]=1;
        }
    }
    else if (kind==DN) {
        for (int i=0;i<arcNum;i++) {
            cin>>vex1>>vex2>>w;
            arcs[hashtable[int(vex1)]][hashtable[int(vex2)]]=w;
        }
    }
    else if (kind==NDN) {
        for (int i=0;i<arcNum;i++) {
            cin>>vex1>>vex2>>w;
            arcs[hashtable[int(vex1)]][hashtable[int(vex2)]]=w;
            arcs[hashtable[int(vex2)]][hashtable[int(vex1)]]=w;
        }
    }

    //下面建立邻接表
    vertices=new VNode<T>[vexNum];
    for (int i=0;i<vexNum;i++) {
        ArcNode<T> *head,*ptr;
        head=new ArcNode<T>;
        ptr=head;
        vertices[i].data=vex[i];
        for (int j=vexNum;j>=1;j--) {
            if (arcs[i+1][j]>0) {
                ptr->nextarc=new ArcNode<T>;
                ptr->nextarc->adjvex=j-1;
                ptr->nextarc->info=arcs[i+1][j];
                ptr=ptr->nextarc;
            }
        }
        vertices[i].firstarc=head->nextarc;
    }
}
/*****建立图*****/

/*****打印邻接矩阵*****/
template<class T>
void Graph<T>::printAdjMtx() {
    if (vexNum) {
        for (int i=0;i<vexNum;i++) cout<<vex[i]<<' ';
        cout<<endl;
        for (int i=1;i<=vexNum;i++) {
            for (int j=1;j<=vexNum;j++) {
                cout<<setw(4)<<arcs[i][j];
            }
            cout<<endl;
        }
    }
}
/*****打印邻接矩阵*****/

/*****打印邻接表*****/
template<class T>
void Graph<T>::printAdjList() {
    for (int i=0;i<vexNum;i++) {
        cout<<vertices[i].data<<"-->";
        ArcNode<T> *ptr=vertices[i].firstarc;
        while (ptr) {
            if (kind==DG || kind==NDG) cout<<ptr->adjvex<<' ';
            else cout<<ptr->adjvex<<','<<ptr->info<<' ';
            ptr=ptr->nextarc;
        }
        cout<<endl;
    }
}
/*****打印邻接表*****/

/*****为题目“图的遍历”建立图*****/
template<class T>
void Graph<T>::initGraphForTrav() {
    cin>>vexNum>>arcNum;
    //为邻接矩阵申请空间
    arcs=new arcCell*[vexNum];
    for (int i=0;i<vexNum;i++) arcs[i]=new arcCell[vexNum]; //邻接矩阵从1开始计数

    //邻接矩阵初始化
    for (int i=0;i<vexNum;i++) {
        for (int j=0;j<vexNum;j++) arcs[i][j]=0;
    }

    int v1,v2;
    for (int i=0;i<arcNum;i++) {
        cin>>v1>>v2;
        arcs[v1][v2]=1;
        arcs[v2][v1]=1;
    }

    //下面建立邻接表
    vertices=new VNode<T>[vexNum];
    for (int i=0;i<vexNum;i++) {
        vertices[i].data=i;
        ArcNode<T> *ptr1=NULL,*ptr2;
        for (int j=0;j<vexNum;j++) {
            if (arcs[i][j]==1) {
                ptr2=new ArcNode<T>;
                ptr2->nextarc=ptr1;
                ptr2->adjvex=j;
                ptr1=ptr2;
            }
        }
        vertices[i].firstarc=ptr1;
    }
}
/*****为题目“图的遍历”建立图*****/

/*****dfsForAjdMtx寻找连通子集*****/
template <class T>
void Graph<T>::DFSTraverse(int structure) {
    visited=new int[vexNum];
    for (int i=0;i<vexNum;i++) visited[i]=0;

    for (int i=0;i<vexNum;i++) {
        if(!visited[i]) {
            cout<<'{';
            switch (structure) {
                case ADJMTX: dfsForAjdMtx(i); break;
                case ADJLIST: dfsForAdjList(i); break;
                default:break;
            }
            cout<<"}";
        }
    }
    cout<<endl;
}
/*****dfsForAjdMtx寻找连通子集*****/

/*****BFS寻找连通子集*****/
template<class T>
void Graph<T>::BFSTraverse(int structure) {
    for (int i=0;i<vexNum;i++) visited[i]=false;
    Queue<int> queue;
    for (int i=0;i<vexNum;i++) {
        if (!visited[i]) {
            cout<<'{';
            visited[i]=true;
            cout<<i;
            queue.enqueue(i);
            while(!queue.empty()) {
                int u=queue.dequeue();
                if (structure==ADJMTX) {
                    for (int j=0;j<vexNum;j++) {
                        if (arcs[u][j]==1 && visited[j]==false) {
                            visited[j]=true;
                            cout<<' '<<j;
                            queue.enqueue(j);
                        }
                    }
                }
                else if (structure==ADJLIST) {
                    ArcNode<T> *ptr=vertices[u].firstarc;
                    while (ptr) {
                        if (visited[ptr->adjvex]==false) {
                            visited[ptr->adjvex]=true;
                            cout<<' '<<ptr->adjvex;
                            queue.enqueue(ptr->adjvex);
                        }
                        ptr=ptr->nextarc;
                    }
                }
            }
            cout<<"}";
        }
    }
    cout<<endl;
}
/*****BFS寻找连通子集*****/

/*****DFS for AdjList*****/
template<class T>
void Graph<T>::dfsForAdjList(int v) {
    visited[v]=true;
    cout<<v;

    ArcNode<T> *ptr=vertices[v].firstarc;
    while (ptr) {
        if(visited[ptr->adjvex]==false) {
            cout<<' ';
            dfsForAdjList(ptr->adjvex);
        }
        ptr=ptr->nextarc;
    }
}
/*****DFS for AdjList*****/

template <class T>
void Graph<T>::dfsForAjdMtx(int v) {
    visited[v]=true;
    cout<<v;

    for (int i=0;i<vexNum;i++) {
        if (arcs[v][i]==1 && visited[i]==false) {
             cout<<' ';
             dfsForAjdMtx(i);
        }
    }
}

/*****建立网（用于求最小生成树）*****/
template <class T>
void Graph<T>::initNet() {
    cin>>vexNum>>arcNum;
    //为邻接矩阵申请空间
    arcs=new arcCell*[vexNum+1];
    for (int i=1;i<=vexNum;i++) arcs[i]=new arcCell[vexNum+1]; //邻接矩阵从1开始计数

    //邻接矩阵初始化
    for (int i=1;i<=vexNum;i++) {
        for (int j=1;j<=vexNum;j++) arcs[i][j]=INF;
    }
    int v1,v2,w;

    for (int i=1;i<=arcNum;i++) {
        cin>>v1>>v2>>w;
        arcs[v1][v2]=w;
        arcs[v2][v1]=w;
    }
}
/*****建立网（用于求最小生成树）*****/

template <class T>
void Graph<T>::DFS(int v,int &vexnum) {
    visited[v]=true;
    vexnum++;

    for (int i=1;i<=vexNum;i++) {
        if (arcs[v][i]>0 && visited[i]==false) {
            DFS(i,vexnum);
        }
    }
}

int minimum(Node* closedge,int n) {
    int k=0;
    int min=0;
    for (int i=1;i<=n;i++) {
        if (closedge[i].lowcost>0) {
            k=i; min=closedge[i].lowcost;
            break;
        }
    }
    for (int i=k;i<=n;i++) {
        if (closedge[i].lowcost<min && closedge[i].lowcost!=0) {
            k=i;
            min=closedge[i].lowcost;
        }
    }
    return k;
}

template<class T>
int Graph<T>::prim() {
    int res=0;
    closedge=new Node[vexNum+1];
    visited=new int[vexNum+1];

    for (int i=1;i<=vexNum;i++) {
        visited[i]=0;
    }
    //利用深度优先遍历检查连通性
    int num=0;
    DFS(1,num);
    if (num!=vexNum) {
        return -1;
    }

    int k=1; //选定第一个顶点开始
    for (int i=1;i<=vexNum;i++) {
        if (i!=k) closedge[i]={k,arcs[k][i]};
    }
    closedge[k].lowcost=0;

    for (int i=2;i<=vexNum;i++) {
        k=minimum(closedge,vexNum);
        res+=closedge[k].lowcost;
        closedge[k].lowcost=0;
        for (int j=1;j<=vexNum;j++) {
            if (arcs[k][j]<closedge[j].lowcost) closedge[j]={k,arcs[k][j]};
        }
    }

    return res;
}

int main() {
    Graph<int> G;
    G.initNet();
    cout<<G.prim()<<endl;
    return 0;
}
