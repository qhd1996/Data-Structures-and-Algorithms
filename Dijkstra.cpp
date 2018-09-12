#include <queue>  
#include <vector>  
#include <cstdio>  
#include <cstring>  
#include <iostream>  
#include <algorithm>  
#define  pb push_back  
#define  mp make_pair  
#define  sz(x) ((int)(x).size())  
using namespace std;  
  
const int N = 1010;  
const int INF = 12345678;  
int n, m, dis[N];  
bool vis[N];  
struct Node {  
    int d, e;  
    bool operator < (const Node x) const {  
        return x.d < d;  
    }  
    Node(int d, int e):d(d), e(e){}  
};  
vector<pair<int, int> > V[N];  
  
void dijkstra(int s) {  
    priority_queue<Node> q;  
    fill(dis + 1, dis + n + 1, INF);  
    fill(vis + 1, vis + n + 1, false);  
    q.push(Node(0, s));  
    dis[s] = 0;  
    while(!q.empty()) {  
        Node deq = q.top(); q.pop();  
        if(vis[deq.e])    
            continue;  
        vis[deq.e] = true;  
        for(int i = 0;i < sz(V[deq.e]);i++) {  
            int e = V[deq.e][i].first;  
            int w = V[deq.e][i].second;  
            if(dis[deq.e] < dis[e] - w) {  
                dis[e] = dis[deq.e] + w;  
                q.push(Node(dis[e], e));      
            }  
        }  
    }     
}  
  
int main(){  
    while(cin >> n >> m, n || m) {  
        for(int i = 1;i <= n;i++)  
            V[i].clear();  
        for(int i = 0;i < m;i++) {  
            int a, b, w;  
            scanf("%d%d%d", &a, &b, &w);  
            V[a].pb(mp(b, w));  
            V[b].pb(mp(a, w));    
        }  
        dijkstra(1);  
        printf("%d\n", dis[n]);  
    }  
    return 0;  
} 
