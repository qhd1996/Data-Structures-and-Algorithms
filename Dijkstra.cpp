#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
 
 
#define INF  0x3f3f3f3f   //定义一个很大的数
 
 
struct Node
{
int num,val;   //存放结点编号和到初始点的距离 
}nod;
 
 
priority_queue<Node> qq;;   //优先从小到大
 
 
bool operator < (Node a,Node b)
{
if(a.val == b.val) return a.num>b.num;
return a.val>b.val;              //先出小 
}
 
 
int book[100];  //检查这个点是否用过 
int dis[100];     //到原点最短距离 
int D[100][100];  //记录路径长度
int V,E; 
 
 
int main()
{
int a,b,d;
while(cin>>V>>E && V&& E)  //输入顶点数和边数 
{
while(!qq.empty()) qq.pop(); //清空
memset(book,0,sizeof(book));
memset(D,-1,sizeof(D)); 
 
for(int i=0;i<E;i++)
{
cin>>a>>b>>d;
D[a][b] = D[b][a] = d;
}
 
for(int i=2;i<=V;i++)
dis[i]=INF;
 
dis[1]=0;
nod.num=1;
nod.val=0;
 
qq.push(nod);   //将起点放入队列 
 
while(!qq.empty())  //不为空时 
{
 
for(int i=2;i<=V;i++)
{
if(D[qq.top().num][i] != -1  &&dis[i]>dis[qq.top().num] + D[qq.top().num][i]) 
{
 
dis[i]=dis[qq.top().num] + D[qq.top().num][i];
nod.num=i; nod.val=dis[i];
qq.push(nod);
}
}
 
qq.pop();
}
 
for(int i=1;i<=V;i++)
{
cout<<"初始点到"<<i<<"点的距离为："<<dis[i]<<endl;
} 
 
}
return 0;
}
