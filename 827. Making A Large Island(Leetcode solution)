class Solution {
public:

int dx[8]={-1,1,0,0,-1,-1,1,1};
int dy[8]={0,0,-1,1,-1,1,-1,1};

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
 int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        Disjoinset ds(n*n);
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
            int x=ds.findPar(i);
            int y=ds.size[x];
            mx=max(mx,y);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)continue;
                int sum=0;
                set<int>s;
                for(int id=0;id<4;id++){
                    int newr=i+dx[id];
                    int newc=j+dy[id];
                    if(isValid(newr,newc,n,m) and grid[newr][newc]==1){
                        int adjNode=newr*m+newc;
                        int x=ds.findPar(adjNode);
                        s.insert(x);
                    }

                }
                for(auto x:s){
                    int z=ds.size[x];
                    sum+=z;
                }
                mx=max(mx,sum+1);
            }
        }
        return mx;

    }
};
