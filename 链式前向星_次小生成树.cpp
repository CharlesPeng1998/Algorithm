#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <cstdio>
#include <string>

using namespace std;
typedef long long LL;

const int MAXN = 500;
const int MAXE = 500 * 500;
const int INF = 0x3f3f3f3f;
int pre[MAXN + 7];

void initPre(int n){ for(int i = 0; i <= n; i++) pre[i] = i; }

//并查集
int Find(int x){ return x == pre[x] ? x : pre[x] = Find(pre[x]); }

void merge(int x, int y){ int fx = Find(x), fy = Find(y); if(fx != fy) pre[fx] = fy; }

struct Edge{ //前向星存边
    int u, v; //起点  终点
    int w;
    bool select;
}edge[MAXE + 7];

bool cmp(Edge a, Edge b){
    if(a.w != b.w) return a.w < b.w;
    if(a.u != b.u) return a.u < b.u;
    return a.v < b.v;
}

struct Node{//链式前向星 用于存储每个集合里面的边
    int to;
    int next;
}link[MAXN + 7];

int head[MAXN + 7];//邻接表的头结点的位置
int End[MAXN + 7];//邻接表的尾节点的位置
int length[MAXN + 7][MAXN + 7];//最小生成树中任意两点路径上的最长边

int kruskal(int n, int m){
    //初始化邻接表,对于每一个顶点添加一个指向自身的边,表示以i为代表元的集合中只有点i
    for(int i = 1; i <= n; i++){
        link[i].to = i, link[i].next = head[i];
        End[i] = i, head[i] = i;
    }
    sort(edge + 1, edge + 1 + m, cmp);
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        if(cnt == n - 1) break;//当找到的边数等于节点数-1,说明mst已经找到
        int fx = Find(edge[i].u);
        int fy = Find(edge[i].v);
        if(fx != fy){
            for(int j = head[fx]; j != -1; j = link[j].next)//修改length数组
                for(int k = head[fy]; k != -1; k = link[k].next)
                //每次合并两个等价类的之后,分别属于两个等价类的两个节点之间的最长边一定是当前加入的边
                    length[link[j].to][link[k].to] = length[link[k].to][link[j].to] = edge[i].w;
            //合并邻接表
            link[End[fy]].next = head[fx];
            End[fy] = End[fx];
            merge(fx, fy);
            cnt++;
            edge[i].select = true;
        }
    }
    if(cnt < n - 1) return -1;
    return 1;
}

int main(){
    int n,m;
    cin>>n>>m;
    //初始化建图后执行以下操作
    kruskal(n, m);
    int mst = 0;
    for(int i = 1; i <= m; i++) if(edge[i].select) mst += edge[i].w;//计算出最小生成树
    int secmst = INF;
    //在 T/(u,v) + (x, y)中寻得次小生成树
    for(int i = 1; i <= m; i++) if(!edge[i].select) secmst = min(secmst, mst + edge[i].w - length[edge[i].u][edge[i].v]);
    return 0;
}
