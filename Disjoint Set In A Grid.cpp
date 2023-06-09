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

const int mxn=1e6+123;
int a[mxn];

int dx[]={-1,1,0,0,-1,-1,1,1};
int dy[]={0,0,-1,1,-1,1,-1,1};

bool isValid(int x,int y,int n,int m){
    if(x>=0 and x<n and y>=0 and y<m)return true;
    else return false;
}
class Disjoinset{
public:	vector<int>size,par;
public:
	Disjoinset(int n){
		par.resize(n+2,0);
		size.resize(n+2,0);
		for(int i=0;i<=n;i++){
			par[i]=i;
			size[i]=1;
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
		if(size[p]<size[q]){
			par[p]=q;
			size[q]+=size[p];
		}else{
			par[q]=p;
			size[p]+=size[q];
		}
	}

};
void solve(){
 	int n,m;
 	cin>>n>>m;
 	Disjoinset ds(n*m);
 	vector<vector<int>>grid(n+1,vector<int>(m+1,0));
 	for(int i=0;i<n;i++){
 		for(int j=0;j<m;j++){
 			cin>>grid[i][j];
 		}
 	}
 	for(int i=0;i<n;i++){
 		for(int j=0;j<m;j++){
 			if(grid[i][j]==0)continue;
 			for(int id=0;id<4;id++){
 				int newr=i+dx[id];
 				int newc=j+dy[id];
 				if(isValid(newr,newc,n,m) and grid[newr][newc]==1){
 					int node=i*m+j;
 					int adjNode=newr*m+newc;
 					ds.Union(node,adjNode);
 				}
 			}
 		}
 	}
 	int mx=0;
 	for(int i=0;i<n*m;i++){
 		cout<<ds.par[i]<<endl;
 	}
 	cout<<mx<<endl;
	
	//maximum number of connected component


}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
