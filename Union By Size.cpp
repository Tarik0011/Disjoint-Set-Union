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
 	Disjoinset ds(n);
 	for(int i=1;i<=m;i++){
 		int u,v;
 		cin>>u>>v;
 		ds.Union(u,v);
 	}
 	/*for(int i=1;i<=n;i++){
 		if(ds.findPar(i)==i){
 			cout<<ds.size[i]<<endl;
 		}
 	}
 	cout<<endl;
 	*/
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
