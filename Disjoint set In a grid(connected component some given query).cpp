https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/science-experiment-in-berland-16ad8152/
/*
*   -------------- ?*?*? --------------
* |         In The Name of *Allah*     |
* |             Author : Tarik         |
* |                                    |
*  -------------- ?*?*? ---------------
*/
 
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define  pb        push_back
#define  all(v)    v.begin(),v.end()
#define  endl       '\n'  
#define  uint       long long
#define  int        long long
#define  fastio    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL) 
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set; 

const int mxn=1e4+123;
int a[mxn],ans=0;
bool vis[mxn][mxn];

int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,-1,1};

bool isValid(int x,int y,int n,int m){
    if(x>=0 and x<n and y>=0 and y<m)return true;
    else return false;
}
class Disjoinset{
public:	vector<int>rank,par;
public:
	Disjoinset(int n){
		rank.resize(n+2,0);
		par.resize(n+2,0);
		for(int i=0;i<=n;i++){
			par[i]=i;
		}
	}
	int findPar(int node){
		if(par[node]==node)return node;
		return par[node]=findPar(par[node]);
	}
	void Union(int u,int v){
		int p=findPar(u);
		int q=findPar(v);
		if(p==q)return;
		ans--;
		if(rank[p]<rank[q]){
			par[p]=q;
		}else if(rank[p]>rank[q]){
			par[q]=p;
		}else{
			par[q]=p;
			rank[p]++;
		}
	}


};
void solve(){
 	int n,m,q;
 	cin>>n>>m>>q;
 	Disjoinset ds(n*m+10);
 	while(q--){
 		int t,x,y;
 		cin>>t;
 		if(t==0){
 			cout<<ans<<endl;
 		}else{
 			cin>>x>>y;
 			x--,y--;
 			if(vis[x][y]==0){
 				ans++;
 				vis[x][y]=1;
 			}
 			for(int i=0;i<4;i++){
 				int nx=x+dx[i];
 				int ny=y+dy[i];
 				if(isValid(nx,ny,n,m) and vis[nx][ny]==1){
 					int node=x*m+y;
 					int adjNode=nx*m+ny;
 					ds.Union(node,adjNode);
 				}
 			}
 		}
 	}
}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
