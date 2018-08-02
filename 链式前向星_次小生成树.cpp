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

//���鼯
int Find(int x){ return x == pre[x] ? x : pre[x] = Find(pre[x]); }

void merge(int x, int y){ int fx = Find(x), fy = Find(y); if(fx != fy) pre[fx] = fy; }

struct Edge{ //ǰ���Ǵ��
    int u, v; //���  �յ�
    int w;
    bool select;
}edge[MAXE + 7];

bool cmp(Edge a, Edge b){
    if(a.w != b.w) return a.w < b.w;
    if(a.u != b.u) return a.u < b.u;
    return a.v < b.v;
}

struct Node{//��ʽǰ���� ���ڴ洢ÿ����������ı�
    int to;
    int next;
}link[MAXN + 7];

int head[MAXN + 7];//�ڽӱ��ͷ����λ��
int End[MAXN + 7];//�ڽӱ��β�ڵ��λ��
int length[MAXN + 7][MAXN + 7];//��С����������������·���ϵ����

int kruskal(int n, int m){
    //��ʼ���ڽӱ�,����ÿһ���������һ��ָ������ı�,��ʾ��iΪ����Ԫ�ļ�����ֻ�е�i
    for(int i = 1; i <= n; i++){
        link[i].to = i, link[i].next = head[i];
        End[i] = i, head[i] = i;
    }
    sort(edge + 1, edge + 1 + m, cmp);
    int cnt = 0;
    for(int i = 1; i <= m; i++){
        if(cnt == n - 1) break;//���ҵ��ı������ڽڵ���-1,˵��mst�Ѿ��ҵ�
        int fx = Find(edge[i].u);
        int fy = Find(edge[i].v);
        if(fx != fy){
            for(int j = head[fx]; j != -1; j = link[j].next)//�޸�length����
                for(int k = head[fy]; k != -1; k = link[k].next)
                //ÿ�κϲ������ȼ����֮��,�ֱ����������ȼ���������ڵ�֮������һ���ǵ�ǰ����ı�
                    length[link[j].to][link[k].to] = length[link[k].to][link[j].to] = edge[i].w;
            //�ϲ��ڽӱ�
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
    //��ʼ����ͼ��ִ�����²���
    kruskal(n, m);
    int mst = 0;
    for(int i = 1; i <= m; i++) if(edge[i].select) mst += edge[i].w;//�������С������
    int secmst = INF;
    //�� T/(u,v) + (x, y)��Ѱ�ô�С������
    for(int i = 1; i <= m; i++) if(!edge[i].select) secmst = min(secmst, mst + edge[i].w - length[edge[i].u][edge[i].v]);
    return 0;
}
