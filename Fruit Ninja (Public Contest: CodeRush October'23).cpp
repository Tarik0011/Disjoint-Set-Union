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
map<int,map<int,int>>mp;

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
			for(auto x:mp[p]){
				mp[q][x.first]+=x.second;
			}

		}else if(rank[p]>rank[q]){
			par[q]=p;
			for(auto x:mp[q]){
				mp[p][x.first]+=x.second;
			}

		}else{
			
			par[q]=p;
			for(auto x:mp[q]){
				mp[p][x.first]+=x.second;
			}
			rank[p]++;
		}
	}

};
void solve(){
 	int n,q;
 	cin>>n>>q;
 	Disjoinset ds(n);
 	for(int i=1;i<=n;i++){
 		int x;
 		cin>>x;
 		mp[i][x]=1;
 	}
 	while(q--){
 		int t;
 		cin>>t;
 		if(t==1){
 			int x,y;
 			cin>>x>>y;
 			ds.Union(x,y);
 		}else{
 			int x,y;
 			cin>>x>>y;
 			int ans=ds.findPar(x);
 			cout<<mp[ans][y]<<endl;
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
