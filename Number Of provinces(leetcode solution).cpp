//https://leetcode.com/problems/number-of-provinces/description/

class Solution {
public:

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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        Disjoinset ds(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    ds.Union(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(ds.par[i]==i){
                ans++;
            }
        }
        return ans;

    }
};
