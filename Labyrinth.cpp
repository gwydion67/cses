#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool ans=false;
int n,m; 
vector<string> grid;
vector<vector<int>> vis;
vector<vector<pair<int,int>>> par;

vector<pair<int,int>> children(pair<int,int> curr){
    vector<pair<int,int>> c;
    if(curr.first+1 < n) c.push_back({curr.first+1, curr.second});
    if(curr.first-1 > -1) c.push_back({curr.first-1, curr.second});
    if(curr.second+1 < m) c.push_back({curr.first, curr.second+1});
    if(curr.second-1 > -1) c.push_back({curr.first, curr.second-1}); 
    return c;
}

void bfs(pair<int,int> s){
    queue<pair<int,int>> q;
    q.push(s);
    vis[s.first][s.second]=0;

    while(!q.empty()){
        pair<int,int> curr=q.front();
        q.pop();

        for(auto child: children(curr)){
            if(grid[child.first][child.second]=='B'){
                ans=true;
            }
            if(grid[child.first][child.second]!='#' && vis[child.first][child.second]==-1){
                vis[child.first][child.second]=vis[curr.first][curr.second]+1;
                par[child.first][child.second] =curr;
                q.push(child);
            }
        }
    }
}

string printPath(pair<int,int>& e, pair<int,int> s, vector<vector<pair<int,int>>> par){
    string path="";
    while(e!=s){
        pair<int,int> p = par[e.first][e.second];
        if(p.first> e.first) path+='U';
        else if (p.first< e.first) path+='D';
        if(p.second > e.second) path+='L';
        else if(p.second < e.second) path+='R';
        e=p;  
    }
    reverse(path.begin(), path.end());
    return path;
}

int main() {
   cin>>n>>m;
   grid.resize(n);
   vis.assign(n, vector<int>(m,-1));
   par.assign(n, vector<pair<int,int>>(m, {-1,-1}));
   for(int i=0; i<n; i++){
    cin>>grid[i];
   }
   pair<int,int> s,e;
   for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
        if(grid[i][j]=='A'){
            s.first = i;
            s.second = j;
        }
        if(grid[i][j]=='B'){
            e.first=i;
            e.second=j;
        }
    }
   }
   bfs(s);
   if(ans==true) {
    cout<<"YES"<<endl;
    cout<<vis[e.first][e.second]<<endl;
    cout<<printPath(e, s, par);
   }
   else cout<<"NO"<<endl;
   
}

