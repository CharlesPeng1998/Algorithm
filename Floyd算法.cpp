#include <iostream>
#include <string.h>
#include <vector>
#define INF 0x3f3f3f
using namespace std;

vector<vector<int>> Graph;
vector<vector<int>> D;
int main() {
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    int u,v,w;

    Graph.resize(n+1);
    for (int i=1;i<=n;i++) Graph[i].resize(n+1);
    D.resize(n+1);
    for (int i=1;i<=n;i++) D[i].resize(n+1);

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i==j) {
                 Graph[i][j]=0;
            }
            else
                Graph[i][j]=INF;
        }
    }
    for (int i=1;i<=m;i++) {
        cin>>u>>v>>w;
        Graph[u][v]=w;
        Graph[v][u]=w;
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            D[i][j]=Graph[i][j];
        }
    }

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            for (int k=1;k<=n;k++) {
                if (D[j][i]+D[i][k]<D[j][k]) {
                    D[j][k]=D[j][i]+D[i][k];
                }
            }
        }
    }

    cout<<D[s][t]<<endl;

    return 0;
}
