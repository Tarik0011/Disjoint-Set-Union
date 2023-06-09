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
 	int n,m;
 	cin>>n>>m;
 	Disjoinset ds(n);
 	for(int i=1;i<=n;i++){
 		int u,v;
 		cin>>u>>v;
 		ds.Union(u,v);
 	}
 	if(ds.findPar(1)==ds.findPar(4))cout<<1<<endl;
 	else cout<<0<<endl;

 /* is 1 and 4 are same component?

 	4 3
 	1 2
 	2 3
 	1 3

 */
}
signed main(){ 
    fastio; 
    int t=1;
    //cin>>t;
    while(t--){
       solve();
    }
}
