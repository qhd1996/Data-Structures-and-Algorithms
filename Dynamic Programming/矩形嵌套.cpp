#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
 
const int M=1002;
int map[M][M],dp[M],n;
 
struct Rec{
	int x,y;
}rec[M]; 
 
int DP(int i){
	if(dp[i]>0) return dp[i];
	for(int j=0;j<n;j++){ //遍历i的所有可达出边 
		if(map[i][j]){
			dp[i]=max(dp[i],DP(j)+map[i][j]); 
		} 
	}
	return dp[i]; 
}
 
//检查a<c,b<d或者b<c,a<d
int check(Rec r1,Rec r2){
	if(r1.x<r2.x&&r1.y<r2.y){
		return 1;
	}	
	if(r1.x<r2.y&&r1.y<r2.x){
		return 1;
	}
	return 0; 
} 
 
int main(){
	int i,m,j;
	cin>>m;
	while(m--){
		memset(dp,0,sizeof(dp));
		memset(map,0,sizeof(map)); 
		cin>>n;
		for(i=0;i<n;i++){
			cin>>rec[i].x>>rec[i].y;
		}
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(i!=j) //设置边的关系,0为无边 
					map[i][j]=check(rec[i],rec[j]);	
			}
		}
		DP(0);
		int max_=-1;
		for(i=0;i<n;i++){
			if(max_<dp[i])max_=dp[i];
		}
		cout<<max_+1<<endl; //顶点数为边数 
	}
}
